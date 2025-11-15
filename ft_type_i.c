/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:00:57 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/15 14:07:46 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_i(va_list arg_ptr, int *count)
{
	int	nb;
	int	nb2;

	nb = va_arg(arg_ptr, int);
	nb2 = nb;
	if (nb < 0)
		*count += 1;
	while (nb2 != 0)
	{
		nb2 /= 10;
		*count += 1;
	}
	ft_putnbr_fd(nb, 1);
}
