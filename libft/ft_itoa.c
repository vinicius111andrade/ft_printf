/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:49:04 by vde-melo          #+#    #+#             */
/*   Updated: 2020/01/29 17:10:33 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numchrs(long n)
{
	int		i;

	i = 0;
	if (n <= 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*s;
	long	nb;

	i = -1;
	nb = n;
	len = ft_numchrs(nb);
	if (!(s = (char *)ft_calloc(len + 1, sizeof(char))))
		return (0);
	if (nb < 0)
	{
		s[0] = '-';
		nb *= -1;
		i++;
	}
	s[len] = '\0';
	while (--len > i)
	{
		s[len] = (nb % 10) + 48;
		nb /= 10;
	}
	return (s);
}
