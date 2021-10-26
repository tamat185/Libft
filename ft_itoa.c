/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecosting <ecosting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:51:30 by ecosting          #+#    #+#             */
/*   Updated: 2021/10/21 20:13:01 by ecosting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	make_number(long int n)
{
	if (n < 0)
		return (n * (-1));
	else
		return (n);
}

static char	*make_str(int *i, int n)
{
	char	*s;

	if (n < 0)
	{
		s = (char *)malloc(sizeof(char) * (*i + 2));
		*i = *i + 1;
	}
	if (n == 0)
	{
		*i = 1;
		s = (char *)malloc(sizeof(char) * (*i + 1));
	}
	if (n > 0)
		s = (char *)malloc(sizeof(char) * (*i + 1));
	return (s);
}

static int	len_s(long int num)
{
	int	i;

	i = 0;
	while (num > 0)
	{
		i++;
		num = num / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*s;
	int				i;
	long int		num;

	num = (long int)n;
	num = make_number(num);
	i = len_s(num);
	s = make_str(&i, n);
	if (!s)
		return (NULL);
	s[i] = '\0';
	i--;
	num = make_number(n);
	if (n == 0)
		s[i] = '0';
	while (num > 0)
	{
		s[i] = num % 10 + '0';
		i--;
		num = num / 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
