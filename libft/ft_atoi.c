/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 21:52:11 by vde-melo          #+#    #+#             */
/*   Updated: 2020/08/24 21:52:29 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	resp_atoi(const char *str, int signal)
{
	int i;
	int resp;

	i = 0;
	resp = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		resp = (resp * 10) + str[i] - 48;
		i++;
	}
	return (resp * signal);
}

int	ft_atoi(const char *str)
{
	int	i;
	int signal;

	i = 0;
	signal = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	return (resp_atoi((char *)&str[i], signal));
}