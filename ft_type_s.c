/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:39:57 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/15 14:14:11 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_s(va_list arg_ptr, int *count)
{
	char	*s;
	size_t	size;

	s = va_arg(arg_ptr, char *);
	if (!s)
	{
		*count += write(1, &"(null)", 6);
		return ;
	}
	size = ft_strlen(s);
	*count += size;
	write(1, s, size);
}
