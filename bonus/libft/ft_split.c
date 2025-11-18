/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:37:20 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/10 10:06:55 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counttab(char const*s, char c);
static int	tabend(char const *s, int index, char c);
static char	**freetab(char **splittab, int t);

char	**ft_split(char const *s, char c)
{
	char	**splittab;
	int		t;
	int		i;
	int		ntab;

	t = 0;
	i = 0;
	if (!s)
		return (NULL);
	ntab = counttab(s, c);
	splittab = malloc ((ntab + 1) * sizeof(char *));
	if (splittab == NULL)
		return (NULL);
	while (t < ntab)
	{
		while (s[i] && s[i] == c)
			i++;
		splittab[t] = ft_substr (s, i, tabend(s, i, c) - i);
		if (splittab[t] == NULL)
			return (freetab(splittab, t));
		i = tabend(s, i, c);
		t++;
	}
	splittab[t] = NULL;
	return (splittab);
}

static char	**freetab(char **splittab, int t)
{
	while (t)
	{
		t--;
		free (splittab[t]);
	}
	free (splittab);
	return (NULL);
}

static int	tabend(char const *s, int index, char c)
{
	while (s[index] && s[index] != c)
		index++;
	return (index);
}

static int	counttab(char const*s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (!s[i + 1] || s[i + 1] == c))
			count++;
		i++;
	}
	return (count);
}
