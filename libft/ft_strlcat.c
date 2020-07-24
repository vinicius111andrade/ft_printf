/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:55:57 by vde-melo          #+#    #+#             */
/*   Updated: 2020/02/04 16:23:43 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t destsize)
{
	size_t	i;
	size_t	len;
	size_t	d_len;
	size_t	s_len;

	i = 0;
	len = 0;
	d_len = ft_strlen(dst);
	s_len = ft_strlen((char *)src);
	if (destsize < d_len)
		return (s_len + destsize);
	while (src[i] && ((d_len + i + 1) < destsize))
	{
		dst[d_len + i] = ((char *)src)[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (s_len + d_len);
}
