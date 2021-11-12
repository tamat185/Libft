/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecosting <ecosting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 14:27:18 by ecosting          #+#    #+#             */
/*   Updated: 2021/10/23 14:35:23 by ecosting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp1;

	if (lst && del)
	{
		tmp1 = *lst;
		while (tmp1)
		{
			tmp = tmp1->next;
			del(tmp1->content);
			free(tmp1);
			tmp1 = tmp;
		}
		*lst = NULL;
	}
}
