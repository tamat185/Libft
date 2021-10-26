/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecosting <ecosting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:50:02 by ecosting          #+#    #+#             */
/*   Updated: 2021/10/20 19:30:58 by ecosting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;
	char	*haystack1;
	size_t	count;

	k = 0;
	count = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[k] != '\0' && k < len)
	{
		i = 0;
		while (needle[i] != haystack[k] && haystack[k] && k < len)
			k++;
		haystack1 = (char *)&haystack[k];
		while (needle[i] == haystack[k] && k < len && needle[i] && haystack[k])
		{
			i++;
			k++;
		}
		if (i == ft_strlen(needle))
			return (haystack1);
		k = ++count;
	}
	return (NULL);
}
