/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:43:17 by jilin             #+#    #+#             */
/*   Updated: 2025/01/18 20:49:51 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

static char	*free_stuff(char *stash);
static char	*reading(int fd, char *buf, char *stash);
static char	*extract(char *txt);

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

// this function return one line at a time, it is not a recursive,
// the looping come from reading function
// find the text before \n or \0, return text before that and 
// extract text after it to use it later for the next call of GNL
// read function will continue from where it stopped until read over

// we need to secure fd, BUFFER_SIZE and buf after malloc
// buf hold data read from file, line store the line to return
// The stash is static bc we need to reain its value across calls to GNL
// For the malloc we do BUFFER_SIZE + 1 to ensure the /0
// Call the function reading and it will give all the stash that we will
// store and append in line each time until we arrived to \n

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

// static char	*adding(char *stash, char *buf)
// {
// 	char	*new_stash;

// 	new_stash = ft_strjoin(stash, buf);
// 	free (stash);
// 	stash = NULL;
// 	return (new_stash);
// }

static char	*reading(int fd, char *buf, char *stash)
{
	int		char_read;
	char	*tmp;

	char_read = 1;
	while (char_read > 0)
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read == -1)
			return (free_stuff(stash));
		buf[char_read] = '\0';
		if (!stash)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, buf);
		free(tmp);
		if (!stash)
			return (NULL);
		if (ft_strchr (buf, '\n'))
			break ;
	}
	if (char_read == 0 && stash && *stash == '\0')
		return (free_stuff(stash));
	return (stash);
}

//* EXPLANATION

// Reads data from fd and appends it to stash until 
// \n is found or \0 is reached.

// char_read = 1 so it loop at least once and will read data
// function read() read BUFFER_SIZE bytes from fd into buf
// if empty, read return 0 or if error char_read == -1

// we need buf to store each buffer between 0 and BUFFER_SIZE
// null terminate the string read into buf with \0

// if stash is NULL, set it as empty string ("") used to append

// so we need a tmp to temporarily store stash value when we
// do ft_strjoin, otherwise it will erase stash when doing ft_strjoin

// store each stash into tmp then strjoin tmp and buf
// then send it into stash and free tmp

// after that, if ft_strjoin allocated failed then return NULL

// when we find \n, loop will break

// add a condition that free if the stash is empty at the EOF(char_read == 0)

// return stash, which hold the read data, it will be updated
// to get_next_line, used to extract a complete line

static char	*extract(char *txt)
{
	size_t	count;
	char	*left;

	if (!txt || *txt == '\0')
		return (NULL);
	count = 0;
	while (txt[count] != '\n' && txt[count] != '\0')
		count++;
	if (txt[count] == '\0' || txt[count + 1] == '\0')
		return (NULL);
	left = ft_substr(txt, count + 1, ft_strlen(txt) - count);
	if (!left || *left == '\0')
	{
		free(left);
		left = NULL;
	}
	txt[count + 1] = '\0';
	return (left);
}
//* EXPLANATION

// extracts the leftover of the txt if found \n 

// Count until \n or \0 to find the size of txt
// if txt[count] is \0 then there no \n so no leftover
// if txt[count + 1] is \0 then the \0 is just after the \n so no leftover

// we will store the leftover into left using ft_substr
// ft_substr(file, starting index, len), we calculate len as
// ft_strlen - count because we want len after \n and count is \n
// and start as count + 1 because we want to start after \n

// Add a condition if ft_substr create empty string

// terminate the string with count + 1 for \0 because count is \n
// return leftover

//* MAIN

// int main(int ac, char **av)
// {
//     int fd;
//     char *txt;

//     if (ac != 2)
//     {
//         printf("Usage: %s <filename>\n", av[0]);
//         return (1);
//     }
//     fd = open(av[1], O_RDONLY);
//     if (fd < 0)
//     {
//         perror("Error opening file");
//         return (1);
//     }
//     while ((txt = get_next_line(fd)) != NULL)
//     {
//         printf("ligne: %s", txt);
//         free(txt);
//     }
//     if (close(fd) < 0)
//     {
//         perror("Error closing file");
//         return (1);
//     }
//     return (0);
// }