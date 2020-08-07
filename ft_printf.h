/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 22:25:08 by user42            #+#    #+#             */
/*   Updated: 2020/08/07 22:06:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# define ALL "cspdiuxX%-0.*"
# define SPECIFIERS "cspdiuxX%"
# define FLAGS "-0"

typedef struct s_specs
{
    int     minus;
    int     zero;
    char    type;
    int     precision;
    int     width;
    int     asterisk_width;
    int     asterisk_precision;
    int     len;
}               t_specs;

int             ft_printf(const char *format, ...);
int             ft_putstr(char *str);
int             ft_putchar(char c);
void            ft_putnb(int nb);
void            printc(t_specs *specs, va_list ap);
void            printdi(t_specs *specs, va_list ap);
void            printp(t_specs *specs, va_list ap);
void            prints(t_specs *specs, va_list ap);
void            printu(t_specs *specs, va_list ap);
void            printx(t_specs *specs, va_list ap);
void            printpercent(t_specs *specs, va_list ap);
int             ft_putchar_x(char c, unsigned int x);
char            *r_str_x(char c, unsigned int x);
int             has_digit(int i, char *str);
char            *ft_itoa_base(unsigned int value, size_t base);
char            *ft_itoa_base2(size_t value, size_t base);
int             ft_cs(char *str, int c, int x, int time);
int             get_nbr(int nbr);
char            *ft_str_until(char * str, int len, int until);

#endif