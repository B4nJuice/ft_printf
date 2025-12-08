/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:11:48 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/20 10:13:15 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_p(char *str, t_flags flags, int len)
{
	int	count;

	count = 0;
	if ((flags.widht != -1 && flags.flags_int % MOD_DASH))
		ft_swrite(&count, ft_fill(' ', flags.widht - len));
	ft_swrite(&count, write(1, &"0x", 2));
	ft_swrite(&count, write(1, str, ft_strlen(str)));
	if (!(flags.flags_int % MOD_DASH))
		ft_swrite(&count, ft_fill(' ', flags.widht - len));
	return (count);
}
