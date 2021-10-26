/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecosting <ecosting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:53:32 by ecosting          #+#    #+#             */
/*   Updated: 2021/10/21 19:53:34 by ecosting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	i;
	size_t	j;
	size_t	len_strjoin;

	i = 0;
	j = 0;
	if ((!s1 || !s2) || (!s1 && !s2))
		return (NULL);
	len_strjoin = ft_strlen(s1) + ft_strlen(s2) + 1;
	strjoin = (char *)malloc(sizeof(char) * len_strjoin);
	if (!strjoin)
		return (NULL);
	while (s1[i])
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		strjoin[i + j] = s2[j];
		j++;
	}
	strjoin[i + j] = '\0';
	return (strjoin);
}
