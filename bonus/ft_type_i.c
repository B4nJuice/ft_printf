/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:00:57 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/19 15:12:43 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_plus(char *src);
int		ft_write_i(char *output, int len, t_flags flags);

void	ft_type_i(va_list arg_ptr, int *count, t_flags flags)
{
	int		nb;
	char	*output;
	int		len;

	nb = va_arg(arg_ptr, int);
	output = ft_itoa(nb);
	if (!(flags.flags_int % MOD_PLUS) && nb >= 0)
		output = ft_add_plus(output);
	if (!output)
	{
		*count = -1;
		return ;
	}
	len = ft_min(ft_strlen(output), flags.string_widht);
	if (!(flags.flags_int % MOD_SPACE) && nb >= 0)
	{
		*count += write(1, " ", 1);
		len++;
	}
	if (flags.flags_int % MOD_ZERO && flags.flags_int % MOD_DASH)
		*count += ft_fill(' ', flags.widht - len);
	*count += ft_write_i(output, len, flags);
	if (!(flags.flags_int % MOD_DASH))
		*count += ft_fill(' ', flags.widht - len);
	free (output);
}

int	ft_write_i(char *output, int len, t_flags flags)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (output[i])
	{
		if (i == 0 && !(flags.flags_int % MOD_POINT)
			&& (output[i] != '+' && output[i] != '-'))
			count += ft_fill('0', flags.string_widht - len);
		else if (i == 0 && !(flags.flags_int % MOD_ZERO)
			&& (output[i] != '+' && output[i] != '-'))
			count += ft_fill('0', flags.widht - len);
		ft_putchar_fd (output[i], 1);
		if (i == 0 && !(flags.flags_int % MOD_POINT)
			&& (output[i] == '+' || output[i] == '-'))
			count += ft_fill('0', flags.string_widht - len + 1);
		else if (i == 0 && !(flags.flags_int % MOD_ZERO)
			&& (output[i] == '+' || output[i] == '-'))
			count += ft_fill('0', flags.widht - len);
		count++;
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
