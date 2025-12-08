/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtohex_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 07:14:56 by lgirard           #+#    #+#             */
/*   Updated: 2025/12/08 13:12:44 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_ptrtohex(uintptr_t nb, char *base)
{
	char		*converted;
	uintptr_t	temp;
	int			size;
	int			i;

	i = 0;
	size = 0;
	temp = nb;
	while (temp > 0)
	{
		temp /= 16;
		size++;
	}
	converted = malloc (size * sizeof(char) + 1);
	if (!converted)
		return (NULL);
	while (nb > 0)
	{
		converted[size - i - 1] = base[nb % 16];
		nb /= 16;
		i++;
	}
	converted[size] = 0;
	return (converted);
}
