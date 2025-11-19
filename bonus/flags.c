/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 08:51:36 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/19 13:15:12 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	get_flags(const char *str, int *i)
{
	t_flags	flags_struct;
	int		index;

	index = *i + 1;
	flags_struct.flags_int = 1;
	flags_struct.string_widht = -1;
	flags_struct.widht = -1;
	if (is_only_space(str, index))
		return (flags_struct);
	while (str[index] && !is_type(str[index]))
	{
		mult_flags(str, &flags_struct.flags_int, &index);
		if (ft_isdigit(str[index]) && str[index] != '0')
			flags_struct.widht = flags_atoi(str, &index, -1);
		else if ((str[index] == '0' || str[index] == '-') && str[index + 1]
			&& str[index + 1] != '0' && flags_struct.widht == -1)
			flags_struct.widht = flags_atoi(str, &index, 0);
		else if (str[index] == '.' && flags_struct.string_widht)
			flags_struct.string_widht = flags_atoi(str, &index, 0);
		index++;
	}
	*i = index - 1;
	return (flags_struct);
}
