/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:28:43 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/20 11:28:51 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_add_hex_prefix(char c)
{
	int	count;

	count = 0;
	ft_swrite(&count, write(1, &"0", 1));
	ft_swrite(&count, write(1, &c, 1));
	return (count);
}
