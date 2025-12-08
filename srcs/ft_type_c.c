/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:28:35 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/20 11:51:47 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_c(va_list arg_ptr, int *count, t_flags flags)
{
	int	c;

	c = (unsigned char)(va_arg(arg_ptr, int));
	if ((flags.widht != -1 && flags.flags_int % MOD_DASH))
		ft_swrite(count, ft_fill(' ', flags.widht - 1));
	ft_swrite(count, write(1, &c, 1));
	if (!(flags.flags_int % MOD_DASH))
		ft_swrite(count, ft_fill(' ', flags.widht - 1));
}
