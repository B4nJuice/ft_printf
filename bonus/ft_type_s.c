/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:39:57 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/20 12:34:49 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_s(va_list arg_ptr, int *count, t_flags flags)
{
	char	*s;
	int		len;

	s = va_arg(arg_ptr, char *);
	if (!s)
	{
		if (!(flags.flags_int % MOD_POINT) && flags.string_widht < 6)
			len = 0;
		else
			len = 6;
		if ((flags.widht != -1 && flags.flags_int % MOD_DASH))
			ft_swrite(count, ft_fill(' ', flags.widht - len));
		ft_swrite(count, write(1, &"(null)", len));
		if (!(flags.flags_int % MOD_DASH))
			ft_swrite(count, ft_fill(' ', flags.widht - len));
		return ;
	}
	len = ft_min(ft_strlen(s), flags.string_widht);
	if ((flags.widht != -1 && flags.flags_int % MOD_DASH))
		ft_swrite(count, ft_fill(' ', flags.widht - len));
	ft_swrite(count, write(1, s, len));
	if (!(flags.flags_int % MOD_DASH))
		ft_swrite(count, ft_fill(' ', flags.widht - len));
}
