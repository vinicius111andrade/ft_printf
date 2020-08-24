/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpercent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 21:27:40 by vde-melo          #+#    #+#             */
/*   Updated: 2020/08/24 23:26:13 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	printpercent(t_spec *spec, va_list ap)
{
	int len;

	len = 0;
	(spec->asterisk_width == 1) ? len = va_arg(ap, int) : 0;
	if (len < 0)
	{
		spec->minus = 1;
		len *= -1;
	}
	(spec->width > 0) ? len = spec->width : 0;
	(spec->zero == 1 && spec->minus == 1) ? spec->zero = 0 : 0;
	len += (len == 0) ? 0 : -1;
	spec->len += (spec->minus) ? ft_cs("%", ' ', len, 0) : 0;
	spec->len += (spec->zero) ? ft_cs("%", '0', len, 1) : 0;
	spec->len += (!spec->minus && !spec->zero) ? ft_cs("%", ' ', len, 1) : 0;
}
