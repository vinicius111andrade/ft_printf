/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_until.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 19:48:30 by vde-melo          #+#    #+#             */
/*   Updated: 2020/08/24 23:33:01 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_str_until(char *str, int len, int until)
{
	int		i;
	char	*newstr;

	i = 0;
	if (until > len)
		return (0);
	if (!(newstr = ft_calloc(until + 1, sizeof(char))))
		return (0);
	while (i < until)
	{
		newstr[i] = str[i];
		i++;
	}
	return (newstr);
}
