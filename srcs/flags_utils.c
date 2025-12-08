/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:45:58 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/20 12:06:02 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_type(char c)
{
	return (c == 'c' || c == 'i' || c == 'd' || c == 'p'
		|| c == 's' || c == 'u' || c == 'x' || c == 'X' || c == '%');
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
	if (c == '-' && *flags_int % MOD_DASH != 0)
	{
		if (*flags_int % MOD_ZERO == 0)
			*flags_int /= MOD_ZERO;
		*flags_int *= MOD_DASH;
	}
	else if (c == '0' && *flags_int % MOD_ZERO != 0)
	{
		if (*flags_int % MOD_DASH != 0)
			*flags_int *= MOD_ZERO;
	}
	else if (c == '.' && *flags_int % MOD_POINT != 0)
		*flags_int *= MOD_POINT;
	else if (c == '#' && *flags_int % MOD_SHARP != 0)
		*flags_int *= MOD_SHARP;
	else if (c == ' ' && *flags_int % MOD_SPACE != 0)
		*flags_int *= MOD_SPACE;
	else if (c == '+' && *flags_int % MOD_PLUS != 0)
		*flags_int *= MOD_PLUS;
}

int	is_only_space(const char *str, int index)
{
	while (str[index] && str[index] == ' ')
		index++;
	if (str[index] == '%')
		return (1);
	return (0);
}
