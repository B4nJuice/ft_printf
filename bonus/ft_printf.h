/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:27:25 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/19 13:14:44 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "../libft/libft.h"

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
	int	flags_int;
	int	widht;
	int	string_widht;
}	t_flags;

int		is_type(char c);
t_flags	get_flags(const char *str, int *i);
int		is_only_space(const char *str, int index);
int		flags_atoi(const char *str, int *index, int gap);
void	mult_flags(const char *str, int *flags_int, int *index);

/*
	Core functions
*/

int		ft_printf(const char *str, ...);
int		percent_type(t_flags flags, va_list arg_ptr, int *count,
			const char *str);

#endif
