/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:33:51 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/10 10:10:59 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	int		i;
	int		size;

	i = 0;
	if (!lst || !f)
		return ;
	size = ft_lstsize(lst);
	while (i < size)
	{
		(*f)(lst->content);
		if (i + 1 < size)
			lst = lst->next;
		i++;
	}
}
