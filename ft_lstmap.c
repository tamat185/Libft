/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecosting <ecosting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 23:57:52 by ecosting          #+#    #+#             */
/*   Updated: 2021/10/24 15:05:54 by ecosting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clean_all(t_list *t1, t_list *t2, void (*del)(void *))
{
	ft_lstclear(&t1, del);
	ft_lstclear(&t2, del);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;

	if (!f || !lst)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (!(new_lst))
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	tmp = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_lst = ft_lstnew(f(lst->content));
		if (!new_lst)
		{
			clean_all(tmp, lst, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&tmp, new_lst);
	}
	return (tmp);
}
