# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/24 21:38:19 by vde-melo          #+#    #+#              #
#    Updated: 2020/08/24 22:06:15 by vde-melo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

F_LG	=	./logic

F_UTILS	=	./utils

F_LIBFT =	./libft

SRCS	=	ft_printf.c ${F_UTILS}/ft_printf_small_utils.c \
			${F_LG}/printc.c ${F_LG}/printdi.c ${F_LG}/printp.c \
			${F_LG}/printpercent.c ${F_LG}/prints.c \
			${F_LG}/printu.c ${F_LG}/printx.c ${F_UTILS}/ft_itoa_base.c \
			${F_UTILS}/ft_itoa_base2.c ${F_UTILS}/ft_putchar_x.c \
			${F_UTILS}/ft_str_until.c ${F_UTILS}/ft_cs.c ${F_UTILS}/r_str_x.c \
			${F_LIBFT}/ft_atoi.c ${F_LIBFT}/ft_calloc.c ${F_LIBFT}/ft_bzero.c \
			${F_LIBFT}/ft_itoa.c ${F_LIBFT}/ft_strdup.c ${F_LIBFT}/ft_strjoin.c \
			${F_LIBFT}/ft_strlen.c ${F_LIBFT}/ft_strmapi.c ${F_LIBFT}/ft_tolower.c \
			${F_LIBFT}/ft_toupper.c ${F_LIBFT}/ft_strchr.c ${F_LIBFT}/ft_isdigit.c 

OBJS	= 	ft_printf.o ft_printf_small_utils.o printc.o printdi.o printp.o \
			printpercent.o prints.o printu.o printx.o ft_itoa_base.o \
			ft_itoa_base2.o ft_putchar_x.o ft_str_until.o ft_cs.o r_str_x.o \
			ft_atoi.o ft_calloc.o ft_bzero.o ft_itoa.o ft_strdup.o ft_strjoin.o \
			ft_strlen.o ft_strmapi.o ft_toupper.o ft_tolower.o ft_strchr.o \
			ft_isdigit.o

CC = gcc

FLAGS = -Wall -Wextra -Werror -c

INCLUDES = ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)

$(OBJS): $(SRCS) $(INCLUDES)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all