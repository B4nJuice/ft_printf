/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:27:25 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/19 09:47:45 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "../libft/libft.h"

int		ft_printf(const char *str, ...);

/*
	Var type functions
*/

void	ft_type_c(va_list arg_ptr, int *count);
void	ft_type_s(va_list arg_ptr, int *count);
void	ft_type_i(va_list arg_ptr, int *count);
void	ft_type_p(va_list arg_ptr, int *count);
void	ft_type_u(va_list arg_ptr, int *count);
void	ft_type_x(va_list arg_ptr, char c, int *count);

/*
	Utils
*/

char	*ft_ptrtohex(uintptr_t nb, char *base);
char	*ft_itobase(unsigned int nb, char *base);

/*
	Flags
*/

typedef struct s_flags
{
	int	*flags_int;
	int *widht;
	int	*string_widht;
}	t_flags;

int		is_type(char c);
t_flags	get_flags(char *str, int *i);
int		flags_atoi(char *str, int *index);
void	mult_flags(char *str, int *flags_int, int *index,
		t_flags *flags_struct);

#endif
