/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecosting <ecosting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:29:38 by ecosting          #+#    #+#             */
/*   Updated: 2021/10/21 19:48:37 by ecosting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*out;

	i = 0;
	if (!s || !f)
		return (NULL);
	while (s[i])
		i++;
	out = (char *)malloc(sizeof(char) * (i + 1));
	if (!out)
		return (NULL);
	out[i] = '\0';
	if (i == 0)
		return (out);
	i--;
	while (i > 0)
	{
		out[i] = f(i, s[i]);
		i--;
	}
	out[i] = f(i, s[i]);
	return (out);
}
