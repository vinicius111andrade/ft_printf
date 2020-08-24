/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 19:30:40 by vde-melo          #+#    #+#             */
/*   Updated: 2020/08/24 22:13:24 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void    prints(t_specs *specs, va_list ap)
{
	char	*str;
	int		len;

	len = 0;
	(specs->asterisk_width == 1) ? len = va_arg(ap, int) : 0;
	(specs->asterisk_precision == 1) ? specs->precision = va_arg(ap, int) : 0;
	if (len < 0)
	{
		specs->minus = 1;
		len *= -1;
	}
	str = (va_arg(ap, char *));
	(str == NULL) ? str = "(null)" : 0;
	(specs->width > 0) ? len = specs->width : 0;
	if (specs->precision <= (int)ft_strlen(str) && specs->precision >= 0)
		str = ft_str_until(str, ft_strlen(str), specs->precision);
	len += (len == 0) ? 0 : -ft_strlen(str);
	(len < 0) ? len = 0 : 0;
	(specs->zero == 1 && specs->minus == 1) ? specs->zero = 0 : 0;
	specs->len += (specs->minus) ? ft_cs(str, ' ', len, 0) : 0;
	specs->len += (specs->zero) ? ft_cs(str, '0', len, 1) : 0;
	specs->len += (!specs->minus && !specs->zero) 
    ? ft_cs(str, ' ', len, 1) : 0;
	if (specs->precision <= (int)ft_strlen(str) && specs->precision >= 0)
		free(str);
}