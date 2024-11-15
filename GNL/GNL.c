/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:43:17 by jilin             #+#    #+#             */
/*   Updated: 2024/11/15 17:51:27 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *_fill_line_buffer(int fd, char *left_c, char *buffer);
static char *_set_line(char *line_buffer);
static char	*ft_strchr(const char *s, int c);
static ssize_t read(int fd, void *buf, size_t nbytes);

char	*get_next_line(int fd)
{
	char *buf;
	char *stash;
	int i;

	i = 0;
	buf = malloc(sizeof(ft_strlen(buf)) * (char));
	stash = malloc(sizeof(ft_strlen(stash)) * (char));
	while (stash[i] != '\n' || stash[i] != '\0')
	{
		read(fd, buf, 5);
		ft_strjoin(buf, stash);
		i++;
	}


}

char *_fill_line_buffer(int fd, char *left_c, char *buffer)
{

}

char *_set_line(char *line_buffer)
{

}

int	main()
{
	int fd;
	char *buf;

	buf = malloc(sizeof(char) * 5);
	fd = open("txt", O_RDONLY);
	read(fd, buf, 5);
	read(fd, buf, 5);
	printf("%s\n", buf);
}
