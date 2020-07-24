/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:54:44 by vde-melo          #+#    #+#             */
/*   Updated: 2020/02/04 16:24:12 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *d, const char *s, size_t dsize)
{
	size_t	i;

	i = 0;
	if (dsize == 0)
		return (ft_strlen((char *)s));
	while ((s[i] != '\0') && (i < dsize - 1))
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (ft_strlen((char *)s));
}
