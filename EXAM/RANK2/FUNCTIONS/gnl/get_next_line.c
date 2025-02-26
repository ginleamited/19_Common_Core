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

	if (!src)
		return (NULL);
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
// Uses a static buffer to read from the file descriptor fd.
// Stores read characters in a dynamically allocated line buffer.
// Stops when a newline (\n) is encountered or when read() returns 0.
{
	static char	buffer[BUFFER_SIZE];
	static int	buffer_read = 0;
	static int	buffer_pos = 0;
	// Static variables keep track of the buffer state across function calls.
	// ✅ Good practice: Prevents re-reading previous data.
	// ❌ Issue: Not handling cases where BUFFER_SIZE is too small.
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
		// If the buffer is exhausted, it reads BUFFER_SIZE bytes into buffer.
		// If read() returns 0 (EOF) or -1 (error), it stops reading.
		// ✅ Good: Uses buffer_read and buffer_pos to track the read progress.
		// ❌ Bad: No error handling for read() returning -1.
		}
		line[i++] = buffer[buffer_pos++];
		if (line[i - 1] == '\n')
			break ;
		// Copies characters from the buffer to line until a newline is found.
		// ✅ Good: Efficient use of buffer.
		// ❌ Bad: line has a fixed allocation of 70,000 bytes (malloc(sizeof(char) * 70000)).
		// ✅ Fix: Use realloc() to dynamically expand line.
	}

	if (i == 0 || buffer_read < 0)
	{
		free(line);
		return (NULL);
	}
	// If i == 0, no characters were read → return NULL.
	// If read() failed (buffer_read < 0) → free memory and return NULL.
	// ✅ Good: Proper cleanup of allocated memory.
	// ❌ Bad: buffer_read < 0 should be checked before writing characters to line.

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
// Opens txt.txt and calls get_next_line(fd) in a loop.
// Prints and frees each line.
// Closes the file after reading.
// ✅ Good: Correctly handles file opening and closing.
// ❌ Bad: No handling of malloc failures in get_next_line.
