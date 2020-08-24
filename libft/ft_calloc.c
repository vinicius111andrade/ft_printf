/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 21:58:29 by vde-melo          #+#    #+#             */
/*   Updated: 2020/08/24 23:13:33 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_calloc(unsigned long int count, unsigned long int size)
{
	void				*ptr;
	unsigned long int	maxlen;

	maxlen = count * size;
	if (!(ptr = malloc(maxlen)))
		return (0);
	ft_bzero(ptr, maxlen);
	return (ptr);
}
