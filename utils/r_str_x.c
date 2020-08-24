/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_str_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 21:20:48 by vde-melo          #+#    #+#             */
/*   Updated: 2020/08/24 21:26:03 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*r_str_x(char c, unsigned int x)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!(str = ft_calloc(x + 1, sizeof(char))))
		return (0);
	while (i < x)
	{
		str[i] = c;
		i++;
	}
	return (str);
}