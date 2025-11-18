/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:12:41 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/08 13:27:31 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !*lst || !del)
		return ;
	if ((*lst)->next)
		ft_lstclear(&(*lst)->next, del);
	(*del)((*lst)->content);
	free (*lst);
	*lst = NULL;
}
