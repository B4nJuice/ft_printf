/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:27:25 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/15 10:43:18 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "../libft/libft.h"

int		ft_printf(const char *str, ...);

void	ft_type_c(va_list arg_ptr, int *count, int mode);
void	ft_type_s(va_list arg_ptr, int *count, int mode);
void	ft_type_i(va_list arg_ptr, int *count, int mode);
void	ft_type_p(va_list arg_ptr, int *count, int mode);
void	ft_type_x(va_list arg_ptr, char c, int *count, int mode);
void	ft_type_u(va_list arg_ptr, int *count, int mode);

char	*ft_itobase(unsigned int nb, char *base);
char	*ft_ptrtohex(uintptr_t nb, char *base);

#endif
