/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 23:17:53 by vde-melo          #+#    #+#             */
/*   Updated: 2020/08/24 23:22:58 by vde-melo         ###   ########.fr       */
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

typedef struct	s_spec
{
	int		minus;
	int		zero;
	char		type;
	int		precision;
	int		width;
	int		asterisk_width;
	int		asterisk_precision;
	int		len;
}				t_spec;

int			ft_printf(const char *format, ...);
int			ft_putstr(char *str);
int			ft_putchar(char c);
void			ft_putnb(int nb);
void			printc(t_spec *specs, va_list ap);
void			printdi(t_spec *specs, va_list ap);
void			printp(t_spec *specs, va_list ap);
void			prints(t_spec *specs, va_list ap);
void			printu(t_spec *specs, va_list ap);
void			printx(t_spec *specs, va_list ap);
void			printpercent(t_spec *specs, va_list ap);
int			ft_putchar_x(char c, unsigned int x);
char			*r_str_x(char c, unsigned int x);
int			has_digit(int i, char *str);
char			*ft_itoa_base(unsigned int value, size_t base);
char			*ft_itoa_base2(size_t value, size_t base);
int			ft_cs(char *str, int c, int x, int time);
int			get_nbr(int nbr);
char			*ft_str_until(char *str, int len, int until);

#endif
