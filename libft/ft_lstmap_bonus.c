/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:47:28 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/13 15:25:09 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*cnlst;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	nlst = NULL;
	cnlst = nlst;
	while (lst)
	{
		content = (*f)(lst->content);
		cnlst = ft_lstnew(content);
		if (!cnlst)
		{
			if (content)
				(*del)(content);
			ft_lstclear(&nlst, del);
			return (NULL);
		}
		else
			ft_lstadd_back(&nlst, cnlst);
		lst = lst->next;
	}
	return (nlst);
}
