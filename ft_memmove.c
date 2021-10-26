/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecosting <ecosting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:51:57 by ecosting          #+#    #+#             */
/*   Updated: 2021/10/21 19:51:58 by ecosting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;

	if ((!dst && !src))
		return (NULL);
	d = (unsigned char *)dst;
	if (d < (unsigned char *)src)
	{
		while (len)
		{
			*d = *(unsigned char *)src;
			d++;
			src++;
			len--;
		}
	}
	else
	{
		while (len)
		{
			*(char *)(d + (len - 1)) = *(char *)(src + (len - 1));
			len--;
		}
	}
	return (dst);
}
