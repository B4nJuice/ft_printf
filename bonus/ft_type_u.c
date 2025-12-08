/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 08:38:54 by lgirard           #+#    #+#             */
/*   Updated: 2025/12/08 12:28:38 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_u(va_list arg_ptr, int *count, t_flags flags)
{
	int		nb;
	int		len;
	char	*converted;

	nb = va_arg(arg_ptr, unsigned int);
	if (nb == 0)
		converted = ft_itoa(nb);
	else
		converted = ft_itobase(nb, "0123456789");
	if (!converted)
	{
		*count = -1;
		return ;
	}
	len = ft_strlen(converted) * !(!(flags.flags_int % MOD_POINT)
			&& (flags.string_widht < 0 || (flags.string_widht <= 0 && !nb)));
	if (flags.flags_int % MOD_ZERO && flags.flags_int % MOD_DASH)
		ft_swrite(count, ft_fill(' ', dash_zero_fill(len, flags, 0)));
	if (!(flags.flags_int % MOD_ZERO) && !(flags.flags_int % MOD_POINT))
		ft_swrite(count, ft_fill(' ', flags.widht - len
				- (flags.string_widht - len) * (flags.string_widht > len)));
	ft_swrite(count, ft_write_i(converted, len, flags));
	if (!(flags.flags_int % MOD_DASH))
		ft_swrite(count, ft_fill(' ', dash_zero_fill(len, flags, 0)));
	free (converted);
}
