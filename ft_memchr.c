/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecosting <ecosting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:51:36 by ecosting          #+#    #+#             */
/*   Updated: 2021/10/21 19:51:38 by ecosting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*s1;

	i = 0;
	s1 = s;
	while (i < n)
	{
		if ((unsigned char)s1[i] == (unsigned char)c)
			return ((void *)&s1[i]);
		i++;
	}
	return ((void *)0);
}
