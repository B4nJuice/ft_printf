/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 07:39:07 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/15 14:14:20 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_p(va_list arg_ptr, int *count)
{
	uintptr_t	address;
	char		*hex_address;

	address = va_arg(arg_ptr, uintptr_t);
	if (!address)
	{
		*count += write(1, &"(nil)", 5);
		return ;
	}
	hex_address = ft_ptrtohex(address, "0123456789abcdef");
	write(1, &"0x", 2);
	*count += ft_strlen(hex_address) + 2;
	ft_putstr_fd (hex_address, 1);
	free (hex_address);
}
