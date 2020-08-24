/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 21:17:09 by vde-melo          #+#    #+#             */
/*   Updated: 2020/08/24 23:30:26 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_itoa_base2(size_t value, size_t base)
{
	int			i;
	char		*str;
	size_t		tmp;
	size_t		test;

	i = 0;
	tmp = value;
	test = -1;
	if (tmp == test)
		tmp = 2147483647;
	while (tmp >= base)
	{
		tmp = tmp / base;
		i++;
	}
	if (!(str = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	while (i >= 0)
	{
		tmp = value % base;
		str[i] = (tmp >= 10) ? tmp - 10 + 'a' : tmp + '0';
		value /= base;
		i--;
	}
	return (str);
}
