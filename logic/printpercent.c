/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpercent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 21:27:40 by vde-melo          #+#    #+#             */
/*   Updated: 2020/08/24 21:32:06 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	printpercent(t_specs *t_specs, va_list ap)
{
	int len;

	len = 0;
	(t_specs->asterisk_width == 1) ? len = va_arg(ap, int) : 0;
	if (len < 0)
	{
		t_specs->minus = 1;
		len *= -1;
	}
	(t_specs->width > 0) ? len = t_specs->width : 0;
	(t_specs->zero == 1 && t_specs->minus == 1) ? t_specs->zero = 0 : 0;
	len += (len == 0) ? 0 : -1;
	t_specs->len += (t_specs->minus) ? ft_cs("%", ' ', len, 0) : 0;
	t_specs->len += (t_specs->zero) ? ft_cs("%", '0', len, 1) : 0;
	t_specs->len += (!t_specs->minus && !t_specs->zero) ? ft_cs("%", ' ', len, 1) : 0;
}