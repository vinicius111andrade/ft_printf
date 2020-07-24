/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:37:18 by vde-melo          #+#    #+#             */
/*   Updated: 2020/01/27 16:48:08 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*chr1;
	unsigned char	*chr2;

	chr1 = (unsigned char *)s1;
	chr2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*chr1 != *chr2)
			return (*chr1 - *chr2);
		if (*chr1 == 0 && *chr2 == 0)
			return (0);
		n--;
		chr1++;
		chr2++;
	}
	return (0);
}
