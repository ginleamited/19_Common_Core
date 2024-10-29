/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 01:29:37 by jilin             #+#    #+#             */
/*   Updated: 2024/10/28 22:09:12 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(const char *str, char c);
static void	ft_strcpy(char *dst, const char *src, char c, int j);
static char	*ft_stralloc(const char *str, char c, int *k);
static void	ft_free(char **strs);

char	**ft_split(const char *str, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		pos;

	if (str == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	j = ft_wordcount(str, c);
	strs = (char **)malloc(sizeof(char *) * (j + 1));
	if (strs == NULL)
		return (NULL);
	strs[j] = NULL;
	while (i < j)
	{
		strs[i] = ft_stralloc(str, c, &pos);
		if (strs[i] == NULL)
		{
			ft_free(strs);
			return (NULL);
		}
		i++;
	}
	return (strs);
}

static int	ft_wordcount(const char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (word);
}

static void	ft_strcpy(char *dst, const char *src, char c, int src_j)
{
	int	i;

	i = 0;
	while (src[src_j] != '\0' && src[src_j] == c)
		src_j++;
	while (src[src_j + i] != c && src[src_j + i] != '\0')
	{
		dst[i] = src[src_j + i];
		i++;
	}
	dst[i] = '\0';
}

static char	*ft_stralloc(const char *src, char c, int *k)
{
	char	*dst;
	int		src_j;
	int		start;

	dst = NULL;
	src_j = *k;
	while (src[*k] != '\0')
	{
		if (src[*k] != c)
		{
			start = *k;
			while (src[*k] != '\0' && src[*k] != c)
				(*k)++;
			dst = (char *)malloc(sizeof(char) * (*k - start + 1));
			if (dst == NULL)
				return (NULL);
			ft_strcpy(dst, src, c, start);
			return (dst);
		}
		(*k)++;
	}
	return (NULL);
}

static void	ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs);
		i++;
	}
	free(strs);
}
// int main(void)
// {
// 	char **result;
// 	char str[] = "HELLO WORLD HELLO YOU";
// 	char delimiter = ' ';
// 	int i = 0;

// 	result = ft_split(str, delimiter);
	
// 	if (result != NULL)
// 	{
// 		while (result[i] != NULL)
// 		{
// 			printf("Word %d: %s\n", i, result[i]);
// 			free(result[i]);
// 			i++;
// 		}
// 		free(result);
// 	}
// 	else
// 		printf("Error: ft_split returned NULL\n");
// }

//* EXPLANATION:

//? FT_SPLIT
// char **strs 	: A pointer to an array of strings (the result).
// int 	i 		: An index for looping through words.
// int 	j 		: The number of words found in the string.
// int 	pos 	: This will hold the current position in the string.
// First it allocates enough memory for the array of string pointers
// If allocation failed, then return (NULL).

// Then it will allocate memory for each word and store it in the strs[i].
// If strs[i] is NUL -> allocation failed -> free -> return NULL

//? FT_WORDCOUNT
// To count the words
// int 	i 		: For iteration
// int 	word 	: Counting words
// First loop the string, if str[i] != delimiter then add a word, 
// then loop the string until finishing the word and occuring a 
// delimiter or the NULL, then getting out from the inner loop 
// and go in the else condition, then go back in the inner loop again
// return the number of words in the end

//? FT_STRCPY
// To copy the word from a string to a newly allocated string
// char *dst 		: destination where the word will be copied
// const char *src 	: source string
// int j 			: index in the source string
// int i			: index in the destination string
// First let's loop with index j to skip the leading delimiters
// Then we will find the first letter or reach the NULL

// The second loop will copy the characters from the src[j + i] to dst[i]
// until it occurs c or NULL, then NULL terminate the word[i] at the end

//? FT_STRALLOC
// 

//? INT MAIN
// char **result : A pointer to an array of strings 
// (char pointers) that will hold the split words.