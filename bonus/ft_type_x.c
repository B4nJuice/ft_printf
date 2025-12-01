/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 08:38:54 by lgirard           #+#    #+#             */
/*   Updated: 2025/12/01 14:47:54 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_x(va_list arg_ptr, char c, int *count, t_flags flags)
{
	int		nb;
	char	*converted;
	int		len;

	nb = va_arg(arg_ptr, unsigned int);
	if (nb == 0)
		converted = ft_itoa(nb);
	else if (c == 'x')
		converted = ft_itobase(nb, "0123456789abcdef");
	else
		converted = ft_itobase(nb, "0123456789ABCDEF");
	if (!converted)
	{
		*count = -1;
		return ;
	}
	len = ft_strlen(converted) + (!(flags.flags_int % MOD_SHARP) && nb != 0) * 2;
	if (!(flags.flags_int % MOD_POINT) && (flags.string_widht < 0 || (flags.string_widht <= 0 && nb == 0)))
		len = 0;
	if ((flags.flags_int % MOD_ZERO && flags.flags_int % MOD_DASH) || (!(flags.flags_int % MOD_ZERO) && !(flags.flags_int % MOD_POINT)))
		ft_swrite(count, ft_fill(' ', flags.widht - len - (flags.string_widht - len) * (!(flags.flags_int % MOD_POINT) && flags.string_widht >= len)));
	if (!(flags.flags_int % MOD_SHARP) && nb != 0)
		ft_swrite(count, ft_add_hex_prefix(c));
	if (!(flags.flags_int % MOD_POINT))
		ft_swrite(count, ft_fill('0', flags.string_widht - len));
	if (!(flags.flags_int % MOD_ZERO) && flags.flags_int % MOD_POINT)
		ft_swrite(count, ft_fill('0', flags.widht - len));
	if (len)
		ft_swrite(count, write(1, converted, ft_min(len, ft_strlen(converted))));
	if (!(flags.flags_int % MOD_DASH))
		ft_swrite(count, ft_fill(' ', flags.widht - len - (flags.string_widht - len) * !(flags.flags_int % MOD_POINT) * (flags.string_widht > len)));
	free (converted);
}
