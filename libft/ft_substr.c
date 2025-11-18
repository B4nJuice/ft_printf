/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:35:22 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/13 10:55:07 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_min(long a, size_t b);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		msize;
	char	*sub;

	if (!s)
		return (NULL);
	msize = ft_min (ft_strlen((char *)s) - start, len);
	sub = malloc ((msize + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	if (ft_strlen((char *)s) > (size_t)start)
	{
		s += start;
		ft_strlcpy (sub, (char *)s, msize + 1);
	}
	else
		sub[0] = 0;
	return (sub);
}

static int	ft_min(long a, size_t b)
{
	if (a < 0)
		return (0);
	if ((unsigned int)a < b)
		return (a * (a > 0));
	return (b * (b > 0));
}
