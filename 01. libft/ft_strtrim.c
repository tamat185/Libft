/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecosting <ecosting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:54:38 by ecosting          #+#    #+#             */
/*   Updated: 2021/10/24 15:12:29 by ecosting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	found_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_trimstart(char const *s, char const *set)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (found_set(s[i], set) == 0)
			return (i);
		i++;
	}
	return (0);
}

static int	ft_trimfinish(char const *s, char const *set)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	i--;
	while (i > 0)
	{
		if (found_set(s[i], set) == 0)
			return (i);
		i--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		trim_start;
	int		trim_finish;
	int		i;
	char	*strtrim;

	if ((!s1 || !set) || (!s1 && !set))
		return (NULL);
	trim_start = ft_trimstart(s1, set);
	trim_finish = ft_trimfinish(s1, set);
	strtrim = (char *)malloc(sizeof(char) * (trim_finish - trim_start + 2));
	if (!strtrim)
		return (NULL);
	i = 0;
	while (trim_start <= trim_finish)
	{
		if (trim_finish == 0)
			break ;
		strtrim[i] = s1[trim_start];
		i++;
		trim_start++;
	}
	strtrim[i] = '\0';
	return (strtrim);
}
