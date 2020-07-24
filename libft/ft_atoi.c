/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 19:19:49 by vde-melo          #+#    #+#             */
/*   Updated: 2020/02/17 17:09:13 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_atoi(const char *str)
{
	int		sign;
	int		index;
	long	num;

	num = 0;
	sign = 1;
	index = 0;
	while ((str[index] > 8 && str[index] < 14) || (str[index] == 32))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index] > 47 && str[index] < 58)
	{
		num *= 10;
		num += str[index++] - 48;
	}
	return (num * sign);
}
