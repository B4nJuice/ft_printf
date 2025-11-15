/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:28:35 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/15 10:52:50 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_c(va_list arg_ptr, int *count, int mode)
{
	int	c;

	c = (unsigned char)(va_arg(arg_ptr, int));
	if (c < 0)
	{
		*count = -1;
		return ;
	}
	if (!mode)
		return ;
	write(1, &c, 1);
	*count += 1;
}
