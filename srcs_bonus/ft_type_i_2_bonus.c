/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_i_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 08:14:12 by lgirard           #+#    #+#             */
/*   Updated: 2025/12/08 13:12:47 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	fill_point_zero_b(char *output, int i, t_flags flags, int len)
{
	int	count;

	count = 0;
	if (i == 0 && !(flags.flags_int % MOD_POINT)
		&& (output[i] != '+' && output[i] != '-'))
		count += ft_fill('0', flags.string_widht - len);
	else if (i == 0 && !(flags.flags_int % MOD_ZERO)
		&& (output[i] != '+' && output[i] != '-'))
		count += ft_fill('0', flags.widht - len);
	return (count);
}

int	fill_point_zero_a(char *output, int i, t_flags flags, int len)
{
	int	count;

	count = 0;
	if (i == 0 && !(flags.flags_int % MOD_POINT)
		&& (output[i] == '+' || output[i] == '-'))
		count += ft_fill('0', flags.string_widht - len + 1);
	else if (i == 0 && !(flags.flags_int % MOD_ZERO)
		&& (output[i] == '+' || output[i] == '-'))
		count += ft_fill('0', flags.widht - len);
	return (count);
}

int	ft_write_i(char *output, int len, t_flags flags)
{
	int	i;
	int	count;
	int	temp;

	i = 0;
	count = 0;
	temp = 0;
	if (!len)
		return (0);
	while (output[i])
	{
		ft_swrite(&count, fill_point_zero_b(output, i, flags, len));
		ft_swrite(&count, write (1, &output[i], 1));
		ft_swrite(&count, fill_point_zero_a(output, i, flags, len));
		i++;
	}
	return (count);
}

char	*ft_add_plus(char *src)
{
	char	*output;
	int		i;
	int		len;

	i = 1;
	len = ft_strlen(src);
	output = malloc (len + 2);
	if (!output)
	{
		free (src);
		return (NULL);
	}
	output[0] = '+';
	while (i < len + 1)
	{
		output[i] = src[i - 1];
		i++;
	}
	free (src);
	output[i] = 0;
	return (output);
}
