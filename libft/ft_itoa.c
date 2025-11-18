/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:28:31 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/12 12:26:44 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_size(int n, unsigned int un);
static char		ft_isolate_num(unsigned int un, size_t sz, size_t i, int sign);
static size_t	ft_power_ten(int b);

char	*ft_itoa(int n)
{
	unsigned int	un;
	int				sign;
	size_t			size;
	size_t			i;
	char			*a;

	i = 0;
	sign = 1;
	if (n < 0)
		sign = -1;
	un = n * sign;
	size = ft_get_size(n, un);
	a = malloc ((1 + size + (sign == -1)) * sizeof(char));
	if (a == NULL)
		return (NULL);
	if (sign == -1)
	{
		a[0] = '-';
		i++;
	}
	i--;
	while (++i < size + (sign == -1))
		a[i] = ft_isolate_num(un, size, i, sign);
	a[i] = 0;
	return (a);
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
