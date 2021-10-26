/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecosting <ecosting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:53:15 by ecosting          #+#    #+#             */
/*   Updated: 2021/10/21 19:53:17 by ecosting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*s++ == (char)c)
			return ((char *)s - 1);
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
