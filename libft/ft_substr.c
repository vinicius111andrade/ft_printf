/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:06:14 by vde-melo          #+#    #+#             */
/*   Updated: 2020/02/04 15:54:30 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub_s;

	i = 0;
	if (!(sub_s = (char *)ft_calloc((len + 1), sizeof(char))))
		return (NULL);
	if (start > (unsigned int)ft_strlen((char *)s))
		return (sub_s);
	sub_s[len] = '\0';
	while (i < len)
	{
		sub_s[i] = ((char *)s)[start];
		i++;
		start++;
	}
	return (sub_s);
}
