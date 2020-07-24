/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:22:43 by vde-melo          #+#    #+#             */
/*   Updated: 2020/01/29 18:06:13 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_chrcmp(const char c, const char *s)
{
	int	size;

	size = ft_strlen((char *)s);
	while (--size >= 0)
		if (c == s[size])
			return (1);
	return (0);
}

static	int	ft_strrevtrim(char const *s1, char const *set)
{
	int	size;

	size = ft_strlen((char *)s1) - 1;
	while (size >= 0 && ft_chrcmp(s1[size], set))
		size--;
	return (size);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	size;

	if (!s1 || !set)
		return (0);
	i = 0;
	while (s1[i] && ft_chrcmp(s1[i], set))
		i++;
	size = ft_strrevtrim((s1 + i), set);
	return (ft_substr(s1, i, (size + 1)));
}
