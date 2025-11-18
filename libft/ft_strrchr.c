/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 08:13:33 by lgirard           #+#    #+#             */
/*   Updated: 2025/11/07 13:24:57 by lgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(char *s, int c)
{
	int	i;
	int	ci;

	i = 0;
	ci = -1;
	c = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == c)
			ci = i;
		i++;
	}
	if (c == 0)
		ci = i;
	if (ci >= 0)
		return (&s[ci]);
	return (0);
}
