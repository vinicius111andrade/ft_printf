/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 21:29:31 by vde-melo          #+#    #+#             */
/*   Updated: 2020/08/24 23:24:50 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	printp(t_spec *spec, va_list ap)
{
	char	*n;
	int		len;
	char	*tmp;

	len = 0;
	(spec->asterisk_width == 1) ? len = va_arg(ap, int) : 0;
	(spec->asterisk_precision == 1) ? spec->precision = va_arg(ap, int) : 0;
	(len < 0) ? spec->minus = 1 : 0;
	(len < 0) ? len *= -1 : 0;
	n = ft_itoa_base2(va_arg(ap, size_t), 16);
	(spec->width > 0) ? len = spec->width : 0;
	if (spec->precision > 0 && spec->precision > (int)ft_strlen(n))
		n = ft_strjoin(r_str_x('0', spec->precision - ft_strlen(n)), n);
	(spec->precision == 0 && n[0] == '0') ? n[0] = '\0' : 0;
	tmp = n;
	n = ft_strjoin("0x", n);
	free(tmp);
	len += (len == 0) ? 0 : -ft_strlen(n);
	(len < 0) ? len = 0 : 0;
	(spec->zero == 1 && spec->minus == 1) ? spec->zero = 0 : 0;
	spec->len += (spec->minus) ? ft_cs(n, ' ', len, 0) : 0;
	spec->len += (spec->zero) ? ft_cs(n, '0', len, 1) : 0;
	spec->len += (!spec->minus && !spec->zero) ? ft_cs(n, ' ', len, 1) : 0;
	free(n);
}
