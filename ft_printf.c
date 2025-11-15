/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 07:40:27 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/15 15:10:53 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	percent_type(const char *str, va_list arg_ptr, int *count);

int	ft_printf(const char *str, ...)
{
	va_list	arg_ptr;
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (!str)
		return (-1);
	va_start(arg_ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
			i += 2 + percent_type(str + i, arg_ptr, &count);
		else
		{
			ft_putchar_fd(str[i], 1);
			i++;
			count++;
		}
		if (count < 0)
			return (count);
	}
	return (count);
}

int	percent_type(const char *str, va_list arg_ptr, int *count)
{
	int	i;

	i = 0;
	str++;
	if (*str == 'c')
		ft_type_c(arg_ptr, count);
	else if (*str == 's')
		ft_type_s(arg_ptr, count);
	else if (*str == 'i' || *str == 'd')
		ft_type_i(arg_ptr, count);
	else if (*str == 'p')
		ft_type_p(arg_ptr, count);
	else if (*str == 'x' || *str == 'X')
		ft_type_x(arg_ptr, *str, count);
	else if (*str == 'u')
		ft_type_u(arg_ptr, count);
	while (str[i] == ' ')
		i++;
	if (str[i] == '%')
	{
		write(1, &"%", 1);
		*count += 1;
		return (i);
	}
	return (0);
}
