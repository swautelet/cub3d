/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 18:21:05 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/18 12:19:37 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_letsmap(t_list **lst, t_list **new_lst, void *(*f)(void *),
				void (*del)(void *))
{
	t_list	*new_elem;

	while (*lst)
	{
		new_elem = ft_lstnew(f((*lst)->content));
		if (!new_elem)
		{
			ft_lstclear(lst, del);
			ft_lstclear(new_lst, del);
			*new_lst = NULL;
			return ;
		}
		ft_lstadd_back(new_lst, new_elem);
		*lst = (*lst)->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	lst = lst->next;
	ft_letsmap(&lst, &new_lst, f, del);
	ft_lstclear(&lst, del);
	return (new_lst);
}
