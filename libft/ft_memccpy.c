/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:56:32 by vde-melo          #+#    #+#             */
/*   Updated: 2020/01/28 15:01:08 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	chr;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	chr = (unsigned char)c;
	while (n > 0)
	{
		*d = *s;
		if (*d == chr)
			return (d + 1);
		d++;
		s++;
		n--;
	}
	return (0);
}
