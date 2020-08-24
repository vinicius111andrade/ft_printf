/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 21:35:14 by vde-melo          #+#    #+#             */
/*   Updated: 2020/08/24 21:36:03 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	printx(t_specs *specs, va_list ap)
{
	int		n;
	int		len;
	char	*str;

	len = 0;
	(specs->asterisk_width == 1) ? len = va_arg(ap, int) : 0;
	(specs->asterisk_precision == 1) ? specs->precision = va_arg(ap, int) : 0;
	(len < 0) ? specs->minus = 1 : 0;
	(len < 0) ? len *= -1 : 0;
	(specs->width > 0) ? len = specs->width : 0;
	n = va_arg(ap, int);
	(specs->zero == 1 && specs->minus == 1) ? specs->zero = 0 : 0;
	(specs->type == 'x') ? str = ft_strmapi(ft_itoa_base(n, 16), ft_tolower) : 0;
	(specs->type == 'X') ? str = ft_strmapi(ft_itoa_base(n, 16), ft_toupper) : 0;
	(specs->precision >= 0) ? specs->zero = 0 : 0;
	if (specs->precision > 0 && specs->precision > (int)ft_strlen(str))
		str = ft_strjoin(r_str_x('0', specs->precision - ft_strlen(str)), str);
	(specs->precision == 0 && n == 0) ? str[0] = '\0' : 0;
	len += (len == 0) ? 0 : -ft_strlen(str);
	(len < 0) ? len = 0 : 0;
	specs->len += (specs->minus) ? ft_cs(str, ' ', len, 0) : 0;
	specs->len += (specs->zero) ? ft_cs(str, '0', len, 1) : 0;
	specs->len += (!specs->minus && !specs->zero) ? ft_cs(str, ' ', len, 1) : 0;
	free(str);
}