/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 08:34:08 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/07 13:46:05 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		n;
	int		lsize;
	char	*bigp;

	if (!big && !len)
		return (0);
	i = 0;
	bigp = (char *)big;
	lsize = ft_strlen((char *)little);
	if (!lsize)
		return (bigp);
	while (bigp[i] && i < len)
	{
		n = 0;
		if (bigp[i] == little[0])
		{
			while (bigp[i + n] == little[n] && i + n < len && little[n])
				n++;
			if (n == lsize)
				return (&bigp[i]);
		}
		i++;
	}
	return (0);
}
