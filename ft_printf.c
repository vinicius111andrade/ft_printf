/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 22:37:52 by user42            #+#    #+#             */
/*   Updated: 2020/08/24 23:23:24 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  sort_spec reads my spec struct a calls the right print function
*/

static void		sort_spec(t_spec *spec, va_list ap)
{
	if (ft_strchr(SPECIFIERS, spec->type))
	{
		if (spec->type == 'c')
			printc(spec, ap);
		else if (spec->type == 's')
			prints(spec, ap);
		else if (spec->type == 'p')
			printp(spec, ap);
		else if (spec->type == 'd' || spec->type == 'i')
			printdi(spec, ap);
		else if (spec->type == 'u')
			printu(spec, ap);
		else if (spec->type == 'x' || spec->type == 'X')
			printx(spec, ap);
		else if (spec->type == '%')
			printpercent(spec, ap);
	}
}

/*
**  get_digit_aster finds the digits of precision or width, and sets aster
**  to 1 if a * is found instead
**
**  has_digit is called a first time by find_format to look for width,
**  it uses atoi to get the number if no number is found atoi returns 0,
**  if a * is found it sets spec_asterisk_widht to 1 and inscreases,
**  else it does nothing. Either way it returns i so that it can be called
**  one more time to look for precision. ("width.precision" is the pattern)
**
**  The second time find_format calls this function it receives an i that
**  is the position of the char right after a '.', and does a similar
**  thing that it did to find width. When it`s done the second time
**  i is also returned but it`s no longer used in find_format.
*/

static int		get_digit_aster(char *str, t_spec *spec, int i)
{
	if (str[i - 1] == '.')
	{
		spec->precision = ft_atoi(&str[i]);
		spec->asterisk_precision = (str[i] == '*') ? 1 && i++ : 0;
	}
	else
	{
		spec->width = ft_atoi(&str[i]);
		spec->asterisk_width = (str[i] == '*') ? 1 && i++ : 0;
	}
	i = has_digit(i, str);
	return (i);
}

/*
**  create_spec initializes a struct with all properties set to 0
**  except for precision that is initialized with -1, because precision
**  can have value equal to 0, so -1 means there is no precision value.
*/

static t_spec	*create_spec(t_spec *spec)
{
	if (!(spec = malloc(sizeof(t_spec))))
		return (0);
	spec->asterisk_precision = 0;
	spec->asterisk_width = 0;
	spec->minus = 0;
	spec->precision = -1;
	spec->type = 0;
	spec->zero = 0;
	spec->width = 0;
	spec->len = 0;
	return (spec);
}

/*
**  find_format looks for a %, when foud it uses a struct to store
**  to desired formatation and then return that struct.
**
**  If it never finds a % it returns 0.
*/

static t_spec	*find_format(char *str, t_spec *spec)
{
	static int	i;

	spec = create_spec(spec);
	while (str[i])
	{
		if (!(str[i] == '%'))
			spec->len += ft_putchar(str[i++]);
		else
		{
			i++;
			while (ft_strchr(FLAGS, str[i]))
			{
				(str[i] == '-') ? spec->minus = 1 : 0;
				(str[i++] == '0') ? spec->zero = 1 : 0;
			}
			i = get_digit_aster(str, spec, i);
			(str[i] == '.') ? i = get_digit_aster(str, spec, ++i) : 0;
			spec->type = str[i++];
			(spec->type == '\0') ? spec = 0 : 0;
		}
		return (spec);
	}
	i = 0;
	return (0);
}

/*
**  ft_printf is the core of it all.
**
**  find_format looks for a % if not found it prints a char and adds to
**  spec->len, when something is found it returns the spec struct.
**  If nothing is ever found returns 0.
**
**  sort_spec is then called everytime a % is found and the proper
**  print is called, then len is actualized and spec freed.
**
**  At the end va_end is called and len is returned.
*/

int				ft_printf(const char *orig_str, ...)
{
	char	*str;
	int		len;
	va_list	ap;
	t_spec	*spec;

	len = 0;
	spec = 0;
	str = (char *)orig_str;
	va_start(ap, orig_str);
	while ((spec = find_format(str, spec)))
	{
		sort_spec(spec, ap);
		len += spec->len;
		free(spec);
	}
	va_end(ap);
	return (len);
}
