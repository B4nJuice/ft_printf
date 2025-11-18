/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:52:28 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/07 08:59:07 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_size(int n, unsigned int un);
static char		ft_isolate_num(unsigned int un, size_t sz, size_t i, int sign);
static size_t	ft_power_ten(int b);

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;
	int				sign;
	size_t			size;
	size_t			i;

	i = 0;
	sign = 1;
	if (n < 0)
		sign = -1;
	un = n * sign;
	size = ft_get_size(n, un);
	if (sign == -1)
	{
		ft_putchar_fd('-', fd);
		i++;
	}
	i--;
	while (++i < size + (sign == -1))
		ft_putchar_fd(ft_isolate_num(un, size, i, sign), fd);
}

static int	ft_get_size(int n, unsigned int un)
{
	int	size;

	size = 0;
	while (n != 0)
	{
		n /= 10;
		size ++;
	}
	if (un == 0)
		size++;
	return (size);
}

static char	ft_isolate_num(unsigned int un, size_t sz, size_t i, int sign)
{
	if (i - (sign == -1) == 0)
		return ((un / ft_power_ten (sz - i + (sign == -1))) + '0');
	return (((un % ft_power_ten (sz - i + (sign == -1) + 1))
			/ ft_power_ten (sz - i + (sign == -1))) + '0');
}

static size_t	ft_power_ten(int b)
{
	int	i;
	int	r;

	i = 0;
	r = 1;
	while (i < b - 1)
	{
		r *= 10;
		i++;
	}
	return (r);
}
