/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:30:39 by vde-melo          #+#    #+#             */
/*   Updated: 2020/02/04 15:22:35 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr_str(char const *s, char c)
{
	int		i;
	int		nbr_str;

	(void)c;
	i = 0;
	nbr_str = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			nbr_str++;
		i++;
	}
	return (nbr_str);
}

static int	ft_len_x(char const *s, char c)
{
	int		len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**ft_split2(char const *s, char c, int j, int i)
{
	int		n;
	char	**array;

	n = 0;
	if (!(array = (char **)ft_calloc((ft_nbr_str(s, c) + 1), sizeof(char *))))
		return (0);
	while (s[n])
	{
		while (s[n] == c && s[n])
			n++;
		i = 0;
		array[j] = (char *)ft_calloc((ft_len_x(s + n, c) + 1), sizeof(char));
		while (s[n] && s[n] != c)
		{
			array[j][i++] = s[n++];
			if (s[n] == c || s[n] == '\0')
				array[j][i] = '\0';
		}
		while (s[n] == c && s[n])
			n++;
		j++;
	}
	return (array);
}

char		**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (0);
	if (ft_nbr_str(s, c) == 0)
	{
		if (!(array = (char **)ft_calloc(1, sizeof(char *))))
			return (0);
		return (array);
	}
	if (!(array = ft_split2(s, c, 0, 0)))
		return (0);
	return (array);
}
