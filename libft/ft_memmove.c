/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 07:26:29 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/13 15:36:51 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*p;

	if (!dest && !src)
		return (NULL);
	i = -1;
	p = dest;
	if (p > (const unsigned char *)src)
	{
		src += n - 1;
		p += n - 1;
	}
	while (++i < n)
	{
		*p = *(unsigned char *)src;
		if (p > (const unsigned char *)src)
		{
			src -= 2;
			p -= 2;
		}
		src++;
		p++;
	}
	return (dest);
}
