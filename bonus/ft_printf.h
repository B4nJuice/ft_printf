/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:27:25 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/20 09:15:28 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "../libft/libft.h"

# define MOD_DASH 2
# define MOD_ZERO 3
# define MOD_POINT 5
# define MOD_SHARP 7
# define MOD_SPACE 11
# define MOD_PLUS 13

typedef struct s_flags
{
	int	flags_int;
	int	widht;
	int	string_widht;
}	t_flags;

/*
	Core functions
*/

int		ft_printf(const char *str, ...);
int		percent_type(t_flags flags, va_list arg_ptr, int *count,\
		const char *str);

/*
	Var type functions
*/

void	ft_type_c(va_list arg_ptr, int *count);
void	ft_type_s(va_list arg_ptr, int *count);
void	ft_type_i(va_list arg_ptr, int *count, t_flags flags);
void	ft_type_p(va_list arg_ptr, int *count);
void	ft_type_u(va_list arg_ptr, int *count, t_flags flags);
void	ft_type_x(va_list arg_ptr, char c, int *count);

/*
	Utils
*/

int		ft_max(int a, int b);
int		ft_min(int a, int b);
char	*ft_add_plus(char *src);
int		ft_fill(char c, int len);
void	check_write_fail(int *count, int temp);
char	*ft_ptrtohex(uintptr_t nb, char *base);
char	*ft_itobase(unsigned int nb, char *base);
int		ft_write_i(char *output, int len, t_flags flags);
int		fill_point_zero_a(char *output, int i, t_flags flags, int len);
int		fill_point_zero_b(char *output, int i, t_flags flags, int len);

/*
	Flags
*/

int		is_type(char c);
t_flags	get_flags(const char *str, int *i);
int		is_only_space(const char *str, int index);
int		flags_atoi(const char *str, int *index, int gap);
void	mult_flags(const char *str, int *flags_int, int *index);

#endif
