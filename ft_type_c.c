/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:28:35 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/15 14:05:57 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_c(va_list arg_ptr, int *count)
{
	int	c;

	c = (unsigned char)(va_arg(arg_ptr, int));
	write(1, &c, 1);
	*count += 1;
}
