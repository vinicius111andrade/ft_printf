/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 21:34:12 by vde-melo          #+#    #+#             */
/*   Updated: 2020/08/24 21:35:26 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	printu(t_specs *specs, va_list ap)
{
	char	*n;
	int		len;

	len = 0;
	(specs->asterisk_width == 1) ? len = va_arg(ap, int) : 0;
	(specs->asterisk_precision == 1) ? specs->precision = va_arg(ap, int) : 0;
	if (len < 0)
	{
		specs->minus = 1;
		len *= -1;
	}
	n = ft_itoa_base(va_arg(ap, unsigned int), 10);
	if (specs->precision > 0 && specs->precision > (int)ft_strlen(n))
		n = ft_strjoin(r_str_x('0', specs->precision - (int)ft_strlen(n)), n);
	(specs->precision == 0 && n[0] == '0') ? n[0] = '\0' : 0;
	(specs->precision >= 0) ? specs->zero = 0 : 0;
	(specs->width > 0) ? len = specs->width : 0;
	(specs->zero == 1 && specs->minus == 1) ? specs->zero = 0 : 0;
	len += (len == 0) ? 0 : -ft_strlen(n);
	(len < 0) ? len = 0 : 0;
	specs->len += (specs->minus) ? ft_cs(n, ' ', len, 0) : 0;
	specs->len += (specs->zero) ? ft_cs(n, '0', len, 1) : 0;
	specs->len += (!specs->minus && !specs->zero) ? ft_cs(n, ' ', len, 1) : 0;
	free(n);
}