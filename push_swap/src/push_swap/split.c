/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilin <jilin@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:33:29 by jilin             #+#    #+#             */
/*   Updated: 2025/02/22 13:57:32 by jilin            ###   ########.fr       */
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
		while (*s && *s != c)
		{
			if (!inside_word)
			{
				count++;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

//* EXPLANATION:
//? This function counts the number of words in a string *s separated by a delimiter c
// Inside_word is a cursor to check if inside a word or not
// Initialize count to 0 for counting the words
//? In the first while loop, we iterate untill end of string
//? and we set the bool to false to check if we are inside a word
//? In the second while loop, we skip the character `c` at the beginning
//? In the third while loop, we check if we are inside a word,
//? this means we are at the beginning of a new word, so we increment the count,
//? as we have set the bool to true, we are not incrementing the count again,
//? and we will increment s until finding a c, then we increment s to skip the c
// After each word, we set the bool to false again and repeat the process
// In the end, we return the count

static char	*get_next_word(char *s, char c, int *cursor)
{
	char	*next_word;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[*cursor] == c)
		(*cursor)++;
	while (s[*cursor + len] && s[*cursor + len] != c)
		len++;
	next_word = malloc(sizeof(char) * (len + 1));
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

static void	free_split_result(char **result_array, int index)
{
	while (index > 0)
		free(result_array[--index]);
	free(result_array);
}

char	**split(char *s, char c)
{
	int		words_count;
	char	**result_array;
	int		i;
	int		cursor;

	if (!s)
		return (NULL);
	words_count = count_words(s, c);
	result_array = malloc(sizeof(char *) * (words_count + 1));
	if (!result_array)
		return (NULL);
	cursor = 0;
	i = 0;
	while (i < words_count)
	{
		result_array[i] = get_next_word(s, c, &cursor);
		if (!result_array[i])
		{
			free_split_result(result_array, i);
			return (NULL);
		}
		i++;
	}
	result_array[i] = NULL;
	return (result_array);
}

//* EXPLANATION:
//? This function splits the string *s into words separated by a delimiter c
// we will split the string into words and store them in an array of strings
// words_count is the number of words in the string
// (**result_array) is the array of strings that will store the words
// call a function that counts the number of words in the string
// if there are no words, we exit the program
// malloc the number of words and +1 if the first character is a delimiter, we need to 
// store an empty string and +1 for the NULL at the end of the array
// Even if there is no empty string, we still allocate +2
// Then we protect the malloc
// In the while, >= 0 because we need to store the NULL at the end of the array
// if i is 0, we allocate memory for an empty string
// in the case s starts with the delimiter, "" is added to the array
// when the i is not 0, we call the function get_next_word to get the next word