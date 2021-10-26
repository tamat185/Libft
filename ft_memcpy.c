/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecosting <ecosting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:51:49 by ecosting          #+#    #+#             */
/*   Updated: 2021/10/21 19:51:50 by ecosting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*dst1;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	dst1 = dst;
	i = 0;
	while (i < n)
	{
		*(unsigned char *) dst1 = *(unsigned char *) src;
		dst1++;
		src++;
		i++;
	}
	return (dst);
}
