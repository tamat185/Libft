/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecosting <ecosting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:26:45 by ecosting          #+#    #+#             */
/*   Updated: 2021/10/21 21:41:36 by ecosting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp)
	{
		if (!temp->next)
			return (temp);
		temp = temp->next;
	}
	return (temp);
}
