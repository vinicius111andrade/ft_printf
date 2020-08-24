/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 19:30:40 by vde-melo          #+#    #+#             */
/*   Updated: 2020/08/24 23:26:01 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	prints(t_spec *spec, va_list ap)
{
	char	*str;
	int		len;

	len = 0;
	(spec->asterisk_width == 1) ? len = va_arg(ap, int) : 0;
	(spec->asterisk_precision == 1) ? spec->precision = va_arg(ap, int) : 0;
	if (len < 0)
	{
		spec->minus = 1;
		len *= -1;
	}
	str = (va_arg(ap, char *));
	(str == NULL) ? str = "(null)" : 0;
	(spec->width > 0) ? len = spec->width : 0;
	if (spec->precision <= (int)ft_strlen(str) && spec->precision >= 0)
		str = ft_str_until(str, ft_strlen(str), spec->precision);
	len += (len == 0) ? 0 : -ft_strlen(str);
	(len < 0) ? len = 0 : 0;
	(spec->zero == 1 && spec->minus == 1) ? spec->zero = 0 : 0;
	spec->len += (spec->minus) ? ft_cs(str, ' ', len, 0) : 0;
	spec->len += (spec->zero) ? ft_cs(str, '0', len, 1) : 0;
	spec->len += (!spec->minus && !spec->zero) ? ft_cs(str, ' ', len, 1) : 0;
	if (spec->precision <= (int)ft_strlen(str) && spec->precision >= 0)
		free(str);
}
