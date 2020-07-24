/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:32:26 by vde-melo          #+#    #+#             */
/*   Updated: 2020/01/27 14:52:32 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*s2;
	char	*s1_walker;
	char	*s2_walker;

	len = 1;
	s1_walker = (char *)s1;
	while (*s1_walker)
	{
		s1_walker++;
		len++;
	}
	s2 = malloc(sizeof(char) * len);
	if (s2 == 0)
		return (0);
	s1_walker = (char *)s1;
	s2_walker = s2;
	while (len > 0)
	{
		s2_walker[len - 1] = s1_walker[len - 1];
		len--;
	}
	return (s2);
}
