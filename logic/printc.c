/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:42:14 by vde-melo          #+#    #+#             */
/*   Updated: 2020/08/24 22:36:19 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	printc(t_specs *specs, va_list ap)
{
	int c;
	int len;

	len = 0;
	(specs->asterisk_width == 1) ? len = va_arg(ap, int) : 0;
	(specs->asterisk_precision == 1) ? len = va_arg(ap, int) : 0;
	(specs->width > 0) ? len = specs->width : 0;
	c = va_arg(ap, int);
	len += (len > 0) ? -1 : 0;
	(len < 0) ? len = 0 : 0;
	if (specs->minus)
	{
		specs->len += ft_putchar(c);
		specs->len += ft_putchar_x(' ', len);
	}
	else if (!specs->minus)
	{
		specs->len += ft_putchar_x(' ', len);
		specs->len += ft_putchar(c);
	}
}