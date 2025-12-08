/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_i_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:00:57 by lgirard           #+#    #+#             */
/*   Updated: 2025/12/08 13:12:50 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_type_i(va_list arg_ptr, int *count, t_flags flags)
{
	int		nb;
	char	*output;
	int		len;

	nb = va_arg(arg_ptr, int);
	output = ft_itoa(nb);
	if (!(flags.flags_int % MOD_PLUS) && nb >= 0)
		output = ft_add_plus(output);
	if (!output)
	{
		*count = -1;
		return ;
	}
	len = ft_strlen(output) * !(!(flags.flags_int % MOD_POINT)
			&& (flags.string_widht < 0 || (flags.string_widht <= 0 && !nb)));
	if (!(flags.flags_int % MOD_SPACE) && nb >= 0)
		ft_swrite(count, write(1, " ", 1));
	if ((flags.flags_int % MOD_ZERO || !(flags.flags_int % MOD_POINT))
		&& flags.flags_int % MOD_DASH)
		ft_swrite(count, ft_fill(' ', zero_point_dash_fill(nb, flags, len)));
	ft_swrite(count, ft_write_i(output, len, flags));
	if (!(flags.flags_int % MOD_DASH))
		ft_swrite(count, ft_fill(' ', zero_point_dash_fill(nb, flags, len)));
	free (output);
}
