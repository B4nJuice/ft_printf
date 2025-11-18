/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:09:38 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/08 12:23:51 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	size_t			i;
	size_t			msize;

	msize = nmemb * size;
	if (nmemb != 0 && msize / nmemb != size)
		return (NULL);
	p = malloc (msize);
	i = 0;
	if (p == NULL)
		return (NULL);
	while (i < msize)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}
