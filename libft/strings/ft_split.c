/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 15:03:20 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/18 00:16:12 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Frees the array of strings, and the strings themselves
 *
 * @param strs String array to free
 * @param i Index to start freeing from
 * @return char** NULL
 */
char	**ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

/**
 * @brief Counts the amount of words in a string, seperated by c
 *
 * @param s The string to count the words in
 * @param c The character to split on
 * @return int The amount of words in the string
 */
static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (*s)
	{
		if (*s != c && found == 0)
		{
			found = 1;
			i++;
		}
		else if (*s == c && found == 1)
			found = 0;
		s++;
	}
	return (i);
}

static int	ft_getwordlen(char const *s, unsigned int start, char c)
{
	while (s[start] != c)
	{
		if (s[start] == '\0')
			return (start);
		start++;
	}
	return (start);
}

/**
 * @brief Splits a string into an array of strings, seperated by c
 *
 * @param s Address of the string to split
 * @param c The character to split on
 * @return char** The array of strings, NULL if allocation fails
 */
char	**ft_split(char const *s, char c)
{
	char			**arr;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	arr = ft_calloc(ft_wordcount(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	while (s[j] != '\0')
	{
		if (s[j] != c)
		{
			arr[i] = ft_substr(s, j, ft_getwordlen(s, j, c) - j);
			if (!arr[i])
				return (ft_free(arr));
			i++;
			j = ft_getwordlen(s, j, c);
		}
		else
			j++;
	}
	return (arr);
}
