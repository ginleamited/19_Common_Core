/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:47:49 by jilin             #+#    #+#             */
/*   Updated: 2025/02/20 10:55:12 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>  // For read()
# include <stdlib.h>  // For malloc() and free()
# include <fcntl.h>   // For open()
# include <stdio.h>   // For printf()

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_LINE_SIZE
#  define MAX_LINE_SIZE 70000
# endif

// Main function
char	*get_next_line(int fd);

// Helper functions (if needed)
char	*ft_strdup(const char *src);

#endif