/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 08:38:54 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/20 10:13:33 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_u(va_list arg_ptr, int *count, t_flags flags)
{
	int		nb;
	char	*converted;
	int		len;

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
	len = ft_strlen(converted);
	ft_swrite(count, ft_write_i(converted, len, flags));
	if (!(flags.flags_int % MOD_DASH))
		ft_swrite(count, ft_fill(' ', flags.widht - len));
	free (converted);
}
