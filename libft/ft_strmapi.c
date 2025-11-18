/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:08:50 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/10 10:07:35 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	int				len;
	char			*s2;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen ((char *)s);
	s2 = malloc ((len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	while (s[i])
	{
		s2[i] = (*f)(i, s[i]);
		i++;
	}
	s2[i] = 0;
	return (s2);
}
