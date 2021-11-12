/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecosting <ecosting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:10:09 by ecosting          #+#    #+#             */
/*   Updated: 2021/10/20 22:39:20 by ecosting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	n1;

	n1 = (long int)n;
	if (n1 == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n1 < 0 && n1 != -2147483648)
	{
		write(fd, "-", 1);
		n1 = -n1;
	}
	if (n1 >= 10)
	{
		ft_putnbr_fd(n1 / 10, fd);
	}	
	ft_putchar_fd(n1 % 10 + '0', fd);
}
