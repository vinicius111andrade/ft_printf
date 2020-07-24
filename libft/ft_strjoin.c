/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:04:35 by vde-melo          #+#    #+#             */
/*   Updated: 2020/01/28 17:58:29 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	t_len;
	char	*str1;
	char	*str2;
	char	*str3;
	char	*re;

	if (!s1 || !s2)
		return (0);
	str1 = (char *)s1;
	str2 = (char *)s2;
	t_len = ft_strlen(str1) + ft_strlen(str2) + 1;
	str3 = malloc(sizeof(char) * t_len);
	if (!str3)
		return (0);
	re = str3;
	while (*str1)
		*str3++ = *str1++;
	while (*str2)
		*str3++ = *str2++;
	*str3 = 0;
	return (re);
}
