/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 07:39:07 by lgirard           #+#    #+#             */
/*   Updated: 2025/12/08 13:12:56 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_type_p(va_list arg_ptr, int *count, t_flags flags)
{
	uintptr_t	address;
	char		*hex_address;
	int			len;

	address = va_arg(arg_ptr, uintptr_t);
	if (!address)
	{
		if ((flags.widht != -1 && flags.flags_int % MOD_DASH))
			ft_swrite(count, ft_fill(' ', flags.widht - 5));
		ft_swrite(count, write(1, &"(nil)", 5));
		if (!(flags.flags_int % MOD_DASH))
			ft_swrite(count, ft_fill(' ', flags.widht - 5));
		return ;
	}
	hex_address = ft_ptrtohex(address, "0123456789abcdef");
	if (!hex_address)
	{
		*count = -1;
		return ;
	}
	len = ft_strlen(hex_address) + 2;
	ft_swrite(count, ft_write_p(hex_address, flags, len));
	free (hex_address);
}
