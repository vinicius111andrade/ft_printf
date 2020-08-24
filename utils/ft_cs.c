/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 22:09:19 by user42            #+#    #+#             */
/*   Updated: 2020/08/24 21:06:11 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** isso aqui soh existe pra retornar uma static int
** q antes era passada direto pro ft_cs mas ai
** ele precisaria de 5 vars, o q a norma n permite
**
** static int is auto init to 0
*/

int get_nbr (int nbr) 
{
    static int  n;
    int         nu;

    if (nbr == 0)
    {
        nu = n;
        n = nu;
    }
    else
        n = nbr;
    return (n);
}

/*
** esse time eh o minus, ele diz se eh pra imprimir
** antes ou depois o "0" ou " "
** se pa mudar o nome dele mais tarde
*/

int ft_cs(char *str, int c, int x, int time) 
{
    int len;
    int nbr;

    nbr = get_nbr(0);
    len = 0;
    (nbr < 0 && x != 0)  ? x-- : 0;
    if (time == 0)
    {
        if (nbr < 0 && nbr >= -2147483647)
            len += ft_putchar('-');
        len += ft_putstr(str);
        len += ft_putchar_x(c, x);
    }
    else if (time == 1)
    {
        if (nbr < 0 && c == '0' && nbr >= -2147483647)
            len += ft_putchar('-');
        len += ft_putchar_x(c, x);
        if (nbr < 0 && nbr >= -2147483647 && c == ' ')
            len += ft_putchar('-');
        len += ft_putstr(str);
    }
    get_nbr(1);
    return (len);
}