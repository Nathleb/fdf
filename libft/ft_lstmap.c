/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-biha <nle-biha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:47:37 by nle-biha          #+#    #+#             */
/*   Updated: 2021/06/03 23:25:30 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*new;

	if (lst == NULL)
		return (NULL);
	ret = ft_lstnew((*f)(lst->content));
	if (ret == NULL)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (new == NULL)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, new);
		lst = lst->next;
	}
	return (ret);
}
