/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:43:17 by jilin             #+#    #+#             */
/*   Updated: 2024/12/03 23:12:03 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_stuff(char *stash);
static char	*reading(int fd, char *buf, char *stash);
static char	*extract(char *line);

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = reading(fd, buf, stash);
	free (buf);
	buf = NULL;
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = extract(line);
	return (line);
}
//* EXPLANATION

// this function return one line at a time, the looping come 
// from reading function
// find the text before \n or \0, return text before that and 
// extract text
// after it to use it later for the next call of GNL

// at first we declare static char stash to keep its data after 
// each extract call
// read function will continue from where it stopped until read over
// 

// we need to secure fd, BUFFER_SIZE and buf after malloc

// malloc BUFFER_SIZE + 1 into buf
// then we call function reading until uncounting \n or reach \0,
// then we call function extract to find the leftover
// then we return line

// buf hold data read from file, line store the line to return
// The stash is static bc we need to reain its value across calls to GNL
// For the malloc we do BUFFER_SIZE + 1 to ensure the /0
// Call the function reading and it will give all the stash that we will
// store and append in line each time until we arrived to \n

// Get_next_line does not recursively call itself. 
// It loops by calling reading to fetch data 
// and extract to manage the leftover data.

// reading continues reading chunks of data into buf and appending 
// them to stash until a newline is found or EOF is reached.

// extract processes the current line and separates 
// any leftover data into stash for the next call.

static char	*free_stuff(char *stash)
{
	if (stash)
	{
		free(stash);
		return (NULL);
	}
	return (NULL);
}

static char	*reading(int fd, char *buf, char *stash)
{
	int		line_read;
	char	*stash_temp;

	line_read = 1;
	while (line_read > 0)
	{
		line_read = read(fd, buf, BUFFER_SIZE);
		if (line_read == -1)
			return (free_stuff(stash));
		buf[line_read] = '\0';
		if (!stash)
			stash = ft_strdup("");
		stash_temp = stash;
		stash = ft_strjoin(stash_temp, buf);
		free(stash_temp);
		if (!stash)
			return (NULL);
		if (ft_strchr (buf, '\n'))
			break ;
	}
	if (line_read == 0 && stash && *stash == '\0')
		return (free_stuff(stash));
	return (stash);
}

//* EXPLANATION

// Reads data from fd and appends it to stash until 
// a \n is found or \0 is reached.

// line_read = 1 so it loop at least once and will read data
// function read() read BUFFER_SIZE bytes from fd into buf
// if empty, read return 0 or if error line_read == -1

// we need buf to store each buffer between 0 and BUFFER_SIZE
// null terminate the string read into buf with \0

// if stash is NULL, set it as empty string ("") used to append

// so we need a stash_temp to temporarily store stash value when we
// do ft_strjoin, otherwise it will erase stash when doing ft_strjoin

// store each stash into stash_temp then strjoin stash_temp and buf
// then send it into stash and free stash_temp

// after that, if ft_strjoin allocated failed then return NULL

// when we find \n, loop will break

// add a condition that free if the stash is empty at the EOF

// return stash, which hold the read data, it will be updated
// to get_next_line, used to extract a complete line

static char	*extract(char *line)
{
	size_t	count;
	char	*left;

	if (!line || *line == '\0')
		return (NULL);
	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[count + 1] == '\0')
		return (NULL);
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

// extracts the leftover of the line if found \n 

// Count until \n or \0 to find the size of line
// if line[count] is \0 then there no \n so no leftover
// if line[count + 1] is \0 then the \0 is just after the \n so no leftover

// we will store the leftover into left using ft_substr
// if left is empty or equal to \0 then we free it and = NULL

// Add a condition if ft_substr create empty string

// terminate the string with count + 1 for \0
// return leftover

//* MAIN

// int main(int argc, char **argv)
// {
//     int fd;
//     char *line;

//     if (argc != 2)
//     {
//         printf("Usage: %s <filename>\n", argv[0]);
//         return (1);
//     }
//     fd = open(argv[1], O_RDONLY);
//     if (fd < 0)
//     {
//         perror("Error opening file");
//         return (1);
//     }
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("Line: %s", line);
//         free(line);
//     }
//     if (close(fd) < 0)
//     {
//         perror("Error closing file");
//         return (1);
//     }
//     return (0);
// }