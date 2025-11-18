/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:10:15 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/13 10:23:46 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	i;
	size_t	len;
	char	*sub;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	len = 0;
	while (is_in_set (s1[start], set))
		start++;
	i = start;
	while (s1[i])
		i++;
	i--;
	while (i > start && is_in_set (s1[i], set))
	{
		len++;
		i--;
	}
	sub = ft_substr (s1, start, ft_strlen((char *)s1) - len - start);
	return (sub);
}

static int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
