/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 21:57:29 by vde-melo          #+#    #+#             */
/*   Updated: 2020/08/24 23:13:26 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*make_itoa(int n, int count, char *str)
{
	unsigned int	num;

	str[count] = 0;
	count--;
	num = (n > 0) ? n : -n;
	while (num)
	{
		str[count] = (num % 10) + '0';
		num /= 10;
		count--;
	}
	if (!count)
		str[count] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int				count;
	unsigned int	num;
	char			*str;

	count = (n > 0) ? 0 : 1;
	num = (n > 0) ? n : -n;
	if (n == 0)
	{
		if (!(str = malloc(count + 1)))
			return (NULL);
		str[0] = '0';
		str[1] = 0;
		return (str);
	}
	while (num)
	{
		count++;
		num /= 10;
	}
	if (!(str = malloc(count + 1)))
		return (NULL);
	return (make_itoa(n, count, str));
}
