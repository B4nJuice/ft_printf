/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:28:43 by lgirard           #+#    #+#             */
/*   Updated: 2025/12/08 13:13:03 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_add_hex_prefix(char c)
{
	int	count;

	count = 0;
	ft_swrite(&count, write(1, &"0", 1));
	ft_swrite(&count, write(1, &c, 1));
	return (count);
}

int	ft_write_x(int len, t_flags flags, unsigned int nb, char c)
{
	int	count;

	count = 0;
	if ((flags.flags_int % MOD_ZERO && flags.flags_int % MOD_DASH)
		|| (!(flags.flags_int % MOD_ZERO) && !(flags.flags_int % MOD_POINT)))
		ft_swrite(&count, ft_fill(' ', dash_zero_fill(len, flags, 0)));
	if (!(flags.flags_int % MOD_SHARP) && nb != 0)
		ft_swrite(&count, ft_add_hex_prefix(c));
	if (!(flags.flags_int % MOD_POINT))
		ft_swrite(&count, ft_fill('0', flags.string_widht - len));
	if (!(flags.flags_int % MOD_ZERO) && flags.flags_int % MOD_POINT)
		ft_swrite(&count, ft_fill('0', flags.widht - len));
	return (count);
}
