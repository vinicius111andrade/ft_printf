/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 21:11:13 by vde-melo          #+#    #+#             */
/*   Updated: 2020/08/24 23:24:30 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	printdi(t_spec *spec, va_list ap)
{
	char	*n;
	int		nbr;
	int		len;

	len = 0;
	(spec->asterisk_width == 1) ? len = va_arg(ap, int) : 0;
	(spec->asterisk_precision == 1) ? spec->precision = va_arg(ap, int) : 0;
	(len < 0) ? spec->minus = 1 : 0;
	(len < 0) ? len *= -1 : 0;
	nbr = va_arg(ap, int);
	n = (nbr < 0) ? ft_itoa(nbr * -1) : ft_itoa(nbr);
	if (spec->precision > 0 && spec->precision > (int)ft_strlen(n))
		n = ft_strjoin(r_str_x('0', spec->precision - ft_strlen(n)), n);
	(spec->precision == 0 && n[0] == '0') ? n[0] = '\0' : 0;
	(spec->precision >= 0) ? spec->zero = 0 : 0;
	(spec->width > 0) ? len = spec->width : 0;
	(spec->zero == 1 && spec->minus == 1) ? spec->zero = 0 : 0;
	len += (len == 0) ? 0 : -ft_strlen(n);
	(len < 0) ? len = 0 : 0;
	get_nbr(nbr);
	spec->len += (spec->minus) ? ft_cs(n, ' ', len, 0) : 0;
	spec->len += (spec->zero) ? ft_cs(n, '0', len, 1) : 0;
	spec->len += (!spec->minus && !spec->zero) ? ft_cs(n, ' ', len, 1) : 0;
	free(n);
}
