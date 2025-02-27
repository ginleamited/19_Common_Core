/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 01:29:37 by jilin             #+#    #+#             */
/*   Updated: 2025/02/24 22:07:37 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_wordcount(const char *str, char c);
static void	ft_strcpy(char *dst, const char *src, char c, int j);
static char	*ft_stralloc(const char *str, char c, int *src_k);
static void	ft_free(char **strs);

char	**ft_split(const char *str, char c)
{
	char	**splitted_str;
	int		i;
	int		word;
	int		pos;

	if (!str)
		return (NULL);
	i = 0;
	pos = 0;
	word = ft_wordcount(str, c);
	splitted_str = (char **)malloc(sizeof(char *) * (word + 1));
	if (splitted_str == NULL)
		return (NULL);
	splitted_str[word] = NULL;
	while (i < word)
	{
		splitted_str[i] = ft_stralloc(str, c, &pos);
		if (splitted_str[i] == NULL)
		{
			ft_free(splitted_str);
			return (NULL);
		}
		i++;
	}
	return (splitted_str);
}

static int	ft_wordcount(const char *str, char c)
{
	int	i;
	int	word;
	int	leading_delim;

	i = 0;
	word = 0;
	if (str[0] == c)
		leading_delim = 1;
	else
		leading_delim = 0;
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
	if (leading_delim && word > 0)
		word--;
	return (word);
}

static void	ft_strcpy(char *d, const char *s, char c, int src_j)
{
	int	i;

	i = 0;
	while (s[src_j] != '\0' && s[src_j] == c)
		src_j++;
	while (s[src_j + i] != c && s[src_j + i] != '\0')
	{
		d[i] = s[src_j + i];
		i++;
	}
	d[i] = '\0';
}

static char	*ft_stralloc(const char *src, char c, int *src_k)
{
	char	*dst;
	int		start;

	dst = NULL;
	while (src[*src_k] != '\0')
	{
		if (src[*src_k] != c)
		{
			start = *src_k;
			while (src[*src_k] != '\0' && src[*src_k] != c)
				(*src_k)++;
			dst = (char *)malloc(sizeof(char) * (*src_k - start + 1));
			if (dst == NULL)
				return (NULL);
			ft_strcpy(dst, src, c, start);
			return (dst);
		}
		(*src_k)++;
	}
	return (NULL);
}

static void	ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

//* MAIN
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
// The parameters are only working in the actual function, if it
// is called in another function then the params will be replaced 
// by the params of the another function

//? FT_SPLIT
// char **splitted_str 	: A pointer to an array of strings (the result).
// int 	i 				: An index for looping through words.
// int 	word 			: The number of words found in the string.
// int 	pos 			: This will hold the current position in the string.
// First it allocates enough memory for the array of string pointers
// If allocation failed, then return (NULL).

// Then it will allocate memory for each word and store it in the 
// splitted_str[i]. 
// If splitted_str[i] is NUL -> allocation failed -> free -> return NULL

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

// char *d 			: destination where the word will be copied
// const char *s 	: source string
// int j 			: index in the source string
// int i			: index in the destination string
// First let's loop with index j to skip the leading delimiters
// Then we will find the first letter or reach the NULL

// The second loop will copy the characters from the s[j + i] to d[i]
// until it occurs c or NULL, then NULL terminate the word[i] at the end

//? FT_STRALLOC
// To allocate memory and return the newly allocated word

// We initialize *dst to NULL because it provides a safe starting point
// to random memory locations
// Int start 	: the starting position of the allocated word
// int *src_k 	: it is a pointer to let it be updatable in the split function
// First start a loop to identify the first non delimeter char
// then the inner loop to iterate the word
// then send the malloc len of the word to dst
// if allocation failed then return NULL
// Then we use ft_strcpy to copy src into dst and return dst which is in 
// the new allocated memory
// In the end, return NULL if no word is found

//? FT_FREE
// (**strs) means array of strings
// Loop the array and free each string
// Then free the array itself

//? INT MAIN
// char **result : A pointer to an array of strings 
// (char pointers) that will hold the split words.