/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 22:37:52 by user42            #+#    #+#             */
/*   Updated: 2020/08/07 22:06:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  sort_specs reads my specs struct a calls the right print function
*/

static void     sort_specs(t_specs *specs, va_list ap)
{
    if (ft_strchr(SPECIFIERS, specs->type))
    {
        if  (specs->type == 'c')
            printc(specs, ap);
        else if  (specs->type == 's')
            prints(specs, ap);
        else if  (specs->type == 'p')
            printp(specs, ap);
        else if  (specs->type == 'd' || specs->type == 'i')
            printdi(specs, ap);
        else if  (specs->type == 'u')
            printu(specs, ap);
        else if  (specs->type == 'x' || specs->type == 'X')
            printx(specs, ap);
        else if  (specs->type == '%')
            printpercent(specs, ap);

    }
}

/*
**  get_digit_aster finds the digits of precision or width, and sets aster
**  to 1 if a * is found instead
**
**  has_digit is called a first time by find_format to look for width,
**  it uses atoi to get the number if no number is found atoi returns 0,
**  if a * is found it sets specs_asterisk_widht to 1 and inscreases,
**  else it does nothing. Either way it returns i so that it can be called
**  one more time to look for precision. ("width.precision" is the pattern)
**
**  The second time find_format calls this function it receives an i that
**  is the position of the char right after a '.', and does a similar
**  thing that it did to find width. When it`s done the second time
**  i is also returned but it`s no longer used in find_format.
*/

static int      get_digit_aster(char *str, t_specs *specs, int i)
{
    if (str[i - 1] == '.')
    {
        specs->precision = ft_atoi(&str[i]);
        specs->asterisk_precision = (str[i] == '*') ? 1 && i++ : 0;
    }
    else
    {
        specs->width = ft_atoi (&str[i]);
        specs->asterisk_width = (str[i] == '*') ? 1 && i++ : 0;
    }
    i = has_digit(i, str);
    return (i);
}

/*
**  create_specs initializes a struct with all properties set to 0
**  except for precision that is initialized with -1, because...
*/

static t_specs  *create_specs(t_specs *specs)
{
    if (!(specs = malloc(sizeof(t_specs))))
        return (0);
    specs->asterisk_precision = 0;
    specs->asterisk_width = 0;
    specs->minus = 0;
    specs->precision = -1;
    specs->type = 0;
    specs->zero = 0;
    specs->width = 0;
    specs->len = 0;
    return (specs);
}

/*
**  find_format looks for a %, when foud it uses a struct to store
**  to desired formatation and then return that struct.
**
**  If it never finds a % it returns 0.
*/

static  t_specs *find_format(char *str, t_specs *specs)
{
    static int i;
    specs = create_specs(specs);
    while (str[i])
    {
        if (!(str[i] == '%'))
            specs->len += ft_putchar(str[i++]);
        else
        {
            i++;
            while (ft_strchr(FLAGS, str[i]))
            {
                (str[i] == '-') ? specs->minus = 1 : 0;
                (str[i++] == '0') ? specs->zero = 1 : 0;
            }
            i = get_digit_aster(str, specs, i);
            (str[i] == '.') ? i = get_digit_aster(str, specs, ++i) : 0;
            specs->type = str[i++];
            (specs->type == '\0') ? specs = 0 : 0;
        }
        return (specs);
    }
    i = 0; //isso aqui faz alguma coisa? acho q n mas to com medo kkk
    return (0);
}

/*
**  ft_printf is the core of it all.
**
**  find_format looks for a % if not found it prints a char and adds to
**  specs->len, when something is found it returns the specs struct.
**  If nothing is ever found returns 0.
**
**  sort_specs is then called everytime a % is found and the proper
**  print is called, then len is actualized and specs freed.
**
**  At the end va_end is called and len is returned.
*/

int             ft_printf(const char *orig_str, ...)
{
    char    *str;
    int     len;
    va_list ap;
    t_specs *specs;

    len = 0;
    specs = 0;
    str = (char *)orig_str;
    va_start(ap, orig_str);
    while (specs = find_format(str, specs)) //quando q esse loop para?
    {
        sort_specs(specs, ap);
        len += specs->len;
        free(specs);
    }
    va_end(ap);
    return (len);
}