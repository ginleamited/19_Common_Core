/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:43:17 by jilin             #+#    #+#             */
/*   Updated: 2024/11/18 20:31:04 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*reading(int fd, char *buf, char *stash);
static char	*extract(char *line);

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*left;

	left = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = reading(fd, buf, left);
	free (buf);
	buf = NULL;
	if (!line)
		return (NULL);
	left = extract(line);
	return (line);
}
//* EXPLANATION
// essentially to secure the function
// then we call function reading to read each line
// then we call function extract to find the leftover
// then we return line

static char	*reading(int fd, char *buf, char *stash)
{
	int		line_read;
	char	*buf_temp;

	line_read = 1;
	while (line_read != '\0')
	{
		line_read = read(fd, buf, BUFFER_SIZE);
		if (line_read == -1)
			return (0);
		buf[line_read] = '\0';
		if (!stash)
			stash = ft_strdup("");
		buf_temp = stash;
		stash = ft_strjoin(buf_temp, buf);
		free(buf_temp);
		buf_temp = NULL;
		if (ft_strchr (buf, '\n'))
			break ;
	}
	return (stash);
}

static char	*extract(char *line)
{
	size_t	count;
	char	*left;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	left = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (!left || *left == '\0')
	{
		free(left);
		left = NULL;
	}
	line[count + 1] = '\0';
	return (left);
}
//* EXPLANATION
// find a leftover, check if there is a line with \n
// if found then call ft_substr, if not found then return 0
// end count+1 as \0 at the end
