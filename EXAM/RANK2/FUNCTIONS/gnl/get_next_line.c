/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:14:35 by jilin             #+#    #+#             */
/*   Updated: 2025/02/20 10:48:56 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	buffer_read = 0;
	static int	buffer_pos = 0;
	char		*line;
	int			i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	line = malloc(sizeof(char) * 70000);
	if (!line)
		return (NULL);

	while (1)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_read <= 0)
				break ;
		}
		line[i++] = buffer[buffer_pos++];
		if (line[i - 1] == '\n')
			break ;
	}

	if (i == 0 || buffer_read < 0)
	{
		free(line);
		return (NULL);
	}

	line[i] = '\0';
	return (line);
}

int	main()
{
	char *line;
	int	fd = open("./txt.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line : %s", line);
		free(line);
	}
	close(fd);
	return (0);
}