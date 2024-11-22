/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:43:17 by jilin             #+#    #+#             */
/*   Updated: 2024/11/22 18:33:56 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*reading(int fd, char *buf, char *stash);
static char	*extract(char *line);

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*stash;

	stash = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = reading(fd, buf, stash);
	free (buf);
	buf = NULL;
	if (!line)
		return (NULL);
	stash = extract(line);
	return (line);
}
//* EXPLANATION
// essentially to secure the function
// then we call function reading to read each line
// then we call function extract to find the leftover
// then we return line

// buf hold data read from file, line store the line to return
// The stash is static bc we need to reain its value across calls to GNL
// For the malloc we do BUFFER_SIZE + 1 to ensure the /0
// Call the function reading and it will give all the stash that we will
// store and append in line each time until we arrived to \n
// 

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

//* EXPLANATION
// Reads data from fd and appends it to stash until 
// a newline character is found or \0 is reached.

// line_read = 1 so it loop at least once and read will read data
// read function returns the byte read
// if empty, read return 0 or error return -1
// read() read BUFFER_SIZE bytes from fd into buf
// if stash is NULL set it as empty string ("") used to append
// store the actual stash into buf_temp then strjoin buf_temp and buf
// then send it into stash and free buf_temp

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
// extracts the leftover par of the line after \n to 
// store in stash for the next call.

// Count until \n or \0 is found to find the size of the string
// if not found \n before \0 then return 0 (no leftover)
// if found then call ft_substr and extract it to left
// terminate with count + 1 for \0 at the end
