/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 08:38:54 by lgirard           #+#    #+#             */
/*   Updated: 2025/12/08 12:36:24 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_x(va_list arg_ptr, char c, int *count, t_flags flags)
{
	int		nb;
	char	*output;
	int		len;

	nb = va_arg(arg_ptr, unsigned int);
	if (nb == 0)
		output = ft_itoa(nb);
	else if (c == 'x')
		output = ft_itobase(nb, "0123456789abcdef");
	else
		output = ft_itobase(nb, "0123456789ABCDEF");
	if (!output)
	{
		*count = -1;
		return ;
	}
	len = (ft_strlen(output) + (!(flags.flags_int % MOD_SHARP) && nb != 0) * 2)
		* !(!(flags.flags_int % MOD_POINT) && (flags.string_widht < 0
				|| (flags.string_widht <= 0 && !nb)));
	ft_swrite(count, ft_write_x(len, flags, nb, c));
	if (len)
		ft_swrite(count, write(1, output, ft_min(len, ft_strlen(output))));
	if (!(flags.flags_int % MOD_DASH))
		ft_swrite(count, ft_fill(' ', dash_zero_fill(len, flags, 1)));
	free (output);
}
