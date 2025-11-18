/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 07:45:55 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/08 10:15:09 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_size;
	size_t	src_size;
	size_t	i;

	if (!dest && !size)
		return (0);
	dest_size = ft_strlen(dest);
	src_size = ft_strlen((char *)src);
	i = 0;
	while (src[i] && (i + dest_size + 1) < size)
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = 0;
	if (size < dest_size)
		return (src_size + size);
	return (src_size + dest_size);
}
