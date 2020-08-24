/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_small_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 20:38:09 by vde-melo          #+#    #+#             */
/*   Updated: 2020/08/21 19:30:03 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int     ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != 0)
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}

int     ft_putchar(char c)
{
    return (write(1, &c, 1));
}

/*
**  unsigned int can store a positive number roughly twice as large
**  as the largest positive in int
**
**  it uses recursivity and prints the last digit using %, note that
**  48 == '0', and 48 + 7 == '7'
*/

void    ft_putnbr(int nb)
{
    unsigned int    nbr;

    if (nb < 0)
    {
        ft_putchar('-');
        nbr = nb * -1;
    }
    else
    {
        nbr = nb;
    }
    if (nbr >= 10)
    {
        ft_putnbr(nbr / 10);
    }
    ft_putchar(nbr % 10 + 48);
}

/*
**  ft_isdigit receives a int c == char c, and checks if '0' <= c <= '9',
**  if True returns 1 else 0
**
**  has_digit returns the position of the first char in the str tha isnt
**  a digit
*/

int     has_digit(int i, char *str)
{
    while (ft_isdigit(str[i]))
        i++;
    return (i);
}