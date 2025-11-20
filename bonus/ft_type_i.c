/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:00:57 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/20 08:15:21 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	len = ft_min(ft_strlen(output), flags.string_widht);
	if (!(flags.flags_int % MOD_SPACE) && nb >= 0)
	{
		*count += write(1, " ", 1);
		len++;
	}
	if (flags.flags_int % MOD_ZERO && flags.flags_int % MOD_DASH)
		*count += ft_fill(' ', flags.widht - len);
	*count += ft_write_i(output, len, flags);
	if (!(flags.flags_int % MOD_DASH))
		*count += ft_fill(' ', flags.widht - len);
	free (output);
}

