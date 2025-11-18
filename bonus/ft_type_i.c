/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:00:57 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/15 14:49:29 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_i(va_list arg_ptr, int *count)
{
	int		nb;
	int		nb2;
	char	*output;

	nb = va_arg(arg_ptr, int);
	nb2 = nb;
	output = ft_itoa(nb);
	if (!output)
	{
		*count = -1;
		return ;
	}
	*count += write(1, output, ft_strlen(output));
	free (output);
}
