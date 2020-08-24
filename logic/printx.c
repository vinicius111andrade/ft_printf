/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 21:35:14 by vde-melo          #+#    #+#             */
/*   Updated: 2020/08/24 23:26:43 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	printx(t_spec *spec, va_list ap)
{
	int		n;
	int		len;
	char	*str;

	len = 0;
	(spec->asterisk_width == 1) ? len = va_arg(ap, int) : 0;
	(spec->asterisk_precision == 1) ? spec->precision = va_arg(ap, int) : 0;
	(len < 0) ? spec->minus = 1 : 0;
	(len < 0) ? len *= -1 : 0;
	(spec->width > 0) ? len = spec->width : 0;
	n = va_arg(ap, int);
	(spec->zero == 1 && spec->minus == 1) ? spec->zero = 0 : 0;
	(spec->type == 'x') ? str = ft_strmapi(ft_itoa_base(n, 16), ft_tolower) : 0;
	(spec->type == 'X') ? str = ft_strmapi(ft_itoa_base(n, 16), ft_toupper) : 0;
	(spec->precision >= 0) ? spec->zero = 0 : 0;
	if (spec->precision > 0 && spec->precision > (int)ft_strlen(str))
		str = ft_strjoin(r_str_x('0', spec->precision - ft_strlen(str)), str);
	(spec->precision == 0 && n == 0) ? str[0] = '\0' : 0;
	len += (len == 0) ? 0 : -ft_strlen(str);
	(len < 0) ? len = 0 : 0;
	spec->len += (spec->minus) ? ft_cs(str, ' ', len, 0) : 0;
	spec->len += (spec->zero) ? ft_cs(str, '0', len, 1) : 0;
	spec->len += (!spec->minus && !spec->zero) ? ft_cs(str, ' ', len, 1) : 0;
	free(str);
}
