/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 07:21:33 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/13 15:36:46 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*p;
	const unsigned char	*src2;

	if (!dest && !src)
		return (NULL);
	i = 0;
	p = dest;
	src2 = src;
	while (i < n)
	{
		*p = *src2;
		src2++;
		p++;
		i++;
	}
	return (dest);
}
