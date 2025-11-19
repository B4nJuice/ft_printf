/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:45:58 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/19 13:14:27 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_type(char c)
{
	return (c == 'c' || c == 'i' || c == 'd' || c == 'p'
		|| c == 's' || c == 'u' || c == 'x' || c == 'X');
}

int	flags_atoi(const char *str, int *index, int gap)
{
	int	nb;

	nb = 0;
	*index += gap;
	while (str[*index + 1] && ft_isdigit(str[*index + 1]))
	{
		nb = nb * 10 + str[*index + 1] - '0';
		*index += 1;
	}
	return (nb);
}

void	mult_flags(const char *str, int *flags_int, int *index)
{
	char	c;

	c = str[*index];
	if (c == '-' && *flags_int % 2 != 0)
	{
		if (*flags_int % 3 == 0)
			*flags_int /= 3;
		*flags_int *= 2;
	}
	else if (c == '0'&& *flags_int % 3 != 0)
	{
		if (*flags_int % 2 != 0)
			*flags_int *= 3;
	}
	else if (c == '.'&& *flags_int % 5 != 0)
		*flags_int *= 5;
	else if (c == '#'&& *flags_int % 7 != 0)
		*flags_int *= 7;
	else if (c == ' '&& *flags_int % 11 != 0)
		*flags_int *= 11;
	else if (c == '+'&& *flags_int % 13 != 0)
		*flags_int *= 13;
}

int	is_only_space(const char *str, int index)
{
	while (str[index] && str[index] == ' ')
		index++;
	if (str[index] == '%')
		return (1);
	return (0);
}
