/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:54:31 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/10 10:05:31 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		tsize;

	if (!s1 || !s2)
		return (NULL);
	tsize = ft_strlen ((char *)s1) + ft_strlen ((char *)s2) + 1;
	s3 = malloc (tsize * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	ft_strlcpy (s3, (char *)s1, ft_strlen ((char *)s1) + 1);
	ft_strlcat (s3, (char *)s2, tsize);
	return (s3);
}
