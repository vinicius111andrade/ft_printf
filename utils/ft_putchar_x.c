/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 21:19:55 by vde-melo          #+#    #+#             */
/*   Updated: 2020/08/24 23:32:14 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar_x(char c, unsigned int x)
{
	unsigned int i;

	i = 0;
	while (i < x)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}
