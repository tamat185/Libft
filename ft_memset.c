/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecosting <ecosting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:52:05 by ecosting          #+#    #+#             */
/*   Updated: 2021/10/21 19:52:06 by ecosting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	void	*p;

	i = 0;
	p = b;
	while (i < len)
	{
		*((unsigned char *)p) = (unsigned char) c;
		i++;
		p++;
	}
	return (b);
}
