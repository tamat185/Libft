/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecosting <ecosting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:51:43 by ecosting          #+#    #+#             */
/*   Updated: 2021/10/21 19:51:45 by ecosting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s12;

	i = 0;
	s11 = (unsigned char *)s1;
	s12 = (unsigned char *)s2;
	while (i < n)
	{
		if (s11[i] != s12[i])
			return (s11[i] - s12[i]);
		i++;
	}
	return (0);
}
