/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:21:28 by vde-melo          #+#    #+#             */
/*   Updated: 2020/02/12 14:45:11 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

/*
 ** procura needle no haystack
 ** s1 == haystack;
 ** s2 == needle;
*/

char		*ft_strnstr(const char *s1, const char *s2, size_t max_len)
{
	size_t	inicio_teste;
	size_t	i1;
	size_t	i2;
	size_t	s2_len;

	inicio_teste = 0;
	s2_len = ft_strlen((char *)s2);
	if (s2_len == 0)
		return ((char*)s1);
	while (inicio_teste < max_len && s1[inicio_teste])
	{
		i2 = 0;
		if (s1[inicio_teste] == s2[i2])
		{
			i1 = inicio_teste + 1;
			i2++;
			while (i1 < max_len && s1[i1] && s2[i2] && s1[i1] == s2[i2])
			{
				i1++;
				i2++;
			}
			if (i2 == s2_len)
				return ((char *)&s1[inicio_teste]);
		}
		inicio_teste++;
	}
	return (0);
}
