/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 21:15:23 by vde-melo          #+#    #+#             */
/*   Updated: 2020/08/24 21:16:29 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_itoa_base(unsigned int value, size_t base)
{
	int				i;
	char			*str;
	unsigned int	tmp;

	i = 0;
	tmp = value;
	while (tmp >= base)
	{
		tmp = tmp / base;
		i++;
	}
	if (!(str = (char *)ft_calloc((i + 1), sizeof(char))))
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