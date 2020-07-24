# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-melo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 13:48:55 by vde-melo          #+#    #+#              #
#    Updated: 2020/02/12 11:52:59 by vde-melo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_memset.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_bzero.c \
	  ft_calloc.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strdup.c \
	  ft_strlcpy.c \
	  ft_strncmp.c \
	  ft_strnstr.c \
	  ft_substr.c \
	  ft_strjoin.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_strtrim.c \
	  ft_itoa.c \
	  ft_strmapi.c \
	  ft_split.c

SRC_BONUS = ft_lstnew.c			\
			ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstdelone.c		\
			ft_lstadd_back.c	\
			ft_lstadd_front.c	\
			ft_lstclear.c		\
			ft_lstmap.c			\
			ft_lstiter.c		\

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

all : $(NAME)

$(NAME): $(SRC) libft.h
	gcc -Wall -Wextra -Werror -I./ -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus:
	gcc -Wall -Wextra -Werror -I./ -c $(SRC) $(SRC_BONUS)
	ar rc $(NAME) $(OBJ) $(OBJ_BONUS)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
