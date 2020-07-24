/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:52:20 by vde-melo          #+#    #+#             */
/*   Updated: 2020/02/04 15:21:36 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr1;
	t_list	*ptr2;

	if (!del || !lst)
		return ;
	ptr1 = *lst;
	while (ptr1)
	{
		ptr2 = ptr1->next;
		del(ptr1->content);
		free(ptr1);
		ptr1 = ptr2;
	}
	*lst = 0;
}
