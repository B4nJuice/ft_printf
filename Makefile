# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 10:16:41 by lgirard           #+#    #+#              #
#    Updated: 2025/11/15 14:48:35 by lgirard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -c -Wall -Wextra -Werror -I./includes -I./libft

SRCS = ft_printf.c \
ft_itobase.c \
ft_ptrtohex.c \
ft_type_c.c \
ft_type_i.c \
ft_type_p.c \
ft_type_s.c \
ft_type_u.c \
ft_type_x.c

OBJ = ${SRCS:.c=.o}

NAME = libftprintf.a

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

all : ${OBJ} ${LIBFT}
	cp ${LIBFT} ${NAME}
	ar rcs ${NAME} ${OBJ}

clean :
	make -C $(LIBFT_PATH) clean
	rm -f ${OBJ}

fclean : clean
	make -C $(LIBFT_PATH) fclean
	rm -f ${NAME}

re : fclean all

libft : ${LIBFT}

${LIBFT}:
	make -C $(LIBFT_PATH) all

${NAME} : all

%.o : %.c Makefile includes/ft_printf.h
	${CC} ${CFLAGS} $< -o $@

.PHONY : all clean fclean re libft