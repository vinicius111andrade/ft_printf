/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:42:14 by vde-melo          #+#    #+#             */
/*   Updated: 2020/08/24 23:23:52 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	printc(t_spec *spec, va_list ap)
{
	int	c;
	int	len;

	len = 0;
	(spec->asterisk_width == 1) ? len = va_arg(ap, int) : 0;
	(spec->asterisk_precision == 1) ? len = va_arg(ap, int) : 0;
	(spec->width > 0) ? len = spec->width : 0;
	c = va_arg(ap, int);
	len += (len > 0) ? -1 : 0;
	(len < 0) ? len = 0 : 0;
	if (spec->minus)
	{
		spec->len += ft_putchar(c);
		spec->len += ft_putchar_x(' ', len);
	}
	else if (!spec->minus)
	{
		spec->len += ft_putchar_x(' ', len);
		spec->len += ft_putchar(c);
	}
}
