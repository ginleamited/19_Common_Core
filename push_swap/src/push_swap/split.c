/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:49:52 by jilin             #+#    #+#             */
/*   Updated: 2025/02/07 00:43:18 by jilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	count_words(char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

//* EXPLANATION:
//? This function counts the number of words in a string *s separated by a delimiter c
// bool inside_word is used to check if the cursor is inside a word or not
// initialize count to 0 for counting the words
//? In the first while loop, we set inside_word to false
//? In the second while loop, we skip the character `c` at the beginning
//? In the third while loop, we check if we are not inside a word,
//? this means we are at the beginning of a new word, so we increment the count
// We set inside_word to true so that we don't count the same word again
// We increment the cursor to move to the next character
// if *s is not NULL, then we set inside_word to false again and repeat the process
// In the end, we return the count


static char *get_next_word(char *s, char c, int *cursor)
{
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	if (!s || !cursor)
		return (NULL);
	while (s[*cursor] == c)
		(*cursor)++;
	while ((s[*cursor + len] != c) && s[*cursor + len])
		len++;
	if (len == 0)
		return (NULL);
	next_word = (char *)malloc((len + 1) * sizeof(char));
	if (!next_word)
		return (NULL);
	while (i < len)
		next_word[i++] = s[(*cursor)++];
	next_word[i] = '\0';
	return (next_word);
}

//* EXPLANATION:
//? This function returns the next word in the string *s separated by a delimiter c
// We use a cursor to keep track of the position in the string
//? The first while loop skips the delimiter `c` at the beginning and
//? moving the cursor until it reaches a character that is not `c`
//? The second while loop calculates the length of the word for memory allocation
// We allocate memory for the next_word using malloc, better (len + 1) * sizeof(char) 
// than len * sizeof(char) + 1
// We protect the malloc
//? The third while loop copies the word to the next_word
// We increment the cursor and the index i
// We set the last character of the next_word to NULL
// In the end, we return the next_word

char	**split(char *s, char c)
{
	int		words_count;
	char	**result_array;
	int		i;

	i = 0;
	words_count = count_words(s, c);
	if (!words_count)
		exit(1);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2));
	if (!result_array)
		return (NULL);
	while (words_count-- >= 0)
	{
		if (i == 0)
		{
			result_array[i] = malloc(sizeof(char));
			if (!result_array[i])
				return (NULL);
			result_array[i++][0] = '\0';
			continue ;
		}
		result_array[i++] = get_next_word(s, c);
	}
	result_array[i] = NULL;
	return (result_array);
}

//* EXPLANATION:
//? This function splits the string *s into words separated by a delimiter c
// we will split the string into words and store them in an array of strings
// 