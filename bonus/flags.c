/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 08:51:36 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/19 09:46:16 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	get_flags(char *str, int *i)
{
	t_flags	*flags_struct;
	int		flags_int;
	int		index;

	index = *i + 1;
	flags_int = 1;
	flags_struct->flags_int = flags_int;
	flags_struct->widht = -1;
	flags_struct->string_widht = -1;
	while (str[index] && !is_type(str[index]))
	{
		mult_flags(str, &flags_int, &index, flags_struct);
		index++;
	}
	*i = index - 1;
	flags_struct->flags_int = flags_int;
	return (*flags_struct);
}

