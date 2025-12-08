/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 07:40:27 by lgirard           #+#    #+#             */
/*   Updated: 2025/12/08 13:12:40 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
			i += 2 + percent_type(get_flags(str, &i), arg_ptr, &count, str + i);
		else
		{
			ft_swrite(&count, write(1, &str[i], 1));
			i++;
		}
		if (count < 0)
			return (count);
	}
	return (count);
}

int	percent_type(t_flags flags, va_list arg_ptr, int *count, const char *str)
{
	int	i;

	i = 0;
	str++;
	if (*str == 'c')
		ft_type_c(arg_ptr, count, flags);
	else if (*str == 's')
		ft_type_s(arg_ptr, count, flags);
	else if (*str == 'i' || *str == 'd')
		ft_type_i(arg_ptr, count, flags);
	else if (*str == 'p')
		ft_type_p(arg_ptr, count, flags);
	else if (*str == 'x' || *str == 'X')
		ft_type_x(arg_ptr, *str, count, flags);
	else if (*str == 'u')
		ft_type_u(arg_ptr, count, flags);
	while (str[i] == ' ')
		i++;
	if (str[i] == '%')
	{
		ft_swrite(count, write(1, &"%", 1));
		return (i);
	}
	return (0);
}
