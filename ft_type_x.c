/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 08:38:54 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/15 14:07:30 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_x(va_list arg_ptr, char c, int *count)
{
	int		nb;
	char	*converted;

	nb = va_arg(arg_ptr, unsigned int);
	if (c == 'x')
		converted = ft_itobase(nb, "0123456789abcdef");
	else
		converted = ft_itobase(nb, "0123456789ABCDEF");
	if (!converted)
		return ;
	*count += ft_strlen(converted);
	ft_putstr_fd (converted, 1);
	free (converted);
}
