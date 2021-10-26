/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecosting <ecosting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:53:06 by ecosting          #+#    #+#             */
/*   Updated: 2021/10/23 16:19:18 by ecosting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count_words;

	i = 0;
	count_words = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		count_words++;
		while (s[i] != c && s[i] != '\0')
			i++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (count_words);
}

static int	len_word(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char	*make_word(const char *s, char c)
{
	char		*word;
	size_t		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (len_word(s, c) + 1));
	if (!word)
		return (NULL);
	while (s[i] != c && s[i] != '\0')
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**clean_all(int i, char **array)
{
	while (i >= 0)
	{
		free(array[i]);
		i = i - 1;
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**array;

	if (!s)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!array)
		return (NULL);
	i = 0;
	j = 0;
	while (i < count_words(s, c))
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		array[i] = make_word(&s[j], c);
		if (array[i] == NULL)
			return (clean_all(i, array));
		while (s[j] != c && s[j] != '\0')
			j++;
		i++;
	}
	array[i] = NULL;
	return (array);
}
