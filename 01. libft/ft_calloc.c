/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecosting <ecosting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:50:50 by ecosting          #+#    #+#             */
/*   Updated: 2021/10/21 19:50:53 by ecosting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s1;
	size_t	i;

	i = 0;
	s1 = malloc(count * size);
	if (!s1)
		return (NULL);
	while (i < count * size)
	{
		s1[i] = 0;
		i++;
	}
	return (s1);
}
