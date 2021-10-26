/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecosting <ecosting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:54:52 by ecosting          #+#    #+#             */
/*   Updated: 2021/10/21 19:54:54 by ecosting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if ((start < (ft_strlen(s) - 1)) && (len > ft_strlen(s)))
		len = ft_strlen(s) - start;
	if (len > ft_strlen(s))
		len = 1;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	while (i < len && s[i + start])
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
