/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 21:58:58 by vde-melo          #+#    #+#             */
/*   Updated: 2020/08/24 21:59:09 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, unsigned long int n)
{
	unsigned char		*str;
	unsigned long int	i;

	i = 0;
	str = (unsigned char*)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}