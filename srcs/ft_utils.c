/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:05:07 by lgirard           #+#    #+#             */
/*   Updated: 2025/12/08 12:54:16 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_swrite(int *count, int temp)
{
	if (*count == -1 || temp == -1)
	{
		*count = -1;
		return ;
	}
	*count += temp;
}

int	dash_zero_fill(int len, t_flags flags, int mode)
{
	if (mode)
		return (flags.widht - len - (flags.string_widht - len)
			* !(flags.flags_int % MOD_POINT) * (flags.string_widht > len));
	return (flags.widht - len - (flags.string_widht - len)
		* !(flags.flags_int % MOD_POINT) * (flags.string_widht >= len));
}

int	zero_point_dash_fill(int nb, t_flags flags, int len)
{
	int	lenght;

	lenght = flags.widht - len;
	lenght -= ((!(flags.flags_int % MOD_SPACE) + !(flags.flags_int % MOD_PLUS))
			* (nb >= 0));
	lenght -= (flags.string_widht + (nb < 0) - len)
		* !(flags.flags_int % MOD_POINT) * (flags.string_widht >= len);
	return (lenght);
}
