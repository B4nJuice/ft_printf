/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:45:58 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/19 09:46:20 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_type(char c)
{
	return (c == 'c' || c == 'i' || c == 'd' || c == 'p'
		|| c == 's' || c == 'u' || c == 'x' || c == 'X');
}

int	flags_atoi(char *str, int *index)
{
	int nb;

	nb = 0;
	while (ft_isdigit(str[*index]))
	{
		nb = nb * 10 + str[*index] - '0';
		*index += 1;
	}
	return (nb);
}

void	mult_flags(char *str, int *flags_int, int *index, t_flags *flags_struct)
{
	char	c;

	c = str[*index];
	if (c == '-')
	{
		if (*flags_int % 3 == 0)
			*flags_int /= 3;
		*flags_int *= 2;
	}
	else if (c == '0')
		if (*flags_int % 2 != 0)
			*flags_int *= 3;
	else if (c == '.')
		*flags_int *= 5;
	else if (c == '#')
		*flags_int *= 7;
	else if (c == ' ')
		*flags_int *= 11;
	else if (c == '+')
		*flags_int *= 13;
}