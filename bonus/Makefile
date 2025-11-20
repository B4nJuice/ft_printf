# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 10:16:41 by lgirard           #+#    #+#              #
#    Updated: 2025/11/20 09:05:28 by lgirard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -c -Wall -Wextra -I./includes -I./libft

SRCS = ft_printf.c \
ft_ptrtohex.c \
flags_utils.c \
ft_type_i_2.c \
ft_itobase.c \
ft_type_c.c \
ft_type_i.c \
ft_type_p.c \
ft_type_s.c \
ft_type_u.c \
ft_type_x.c \
ft_maths.c \
ft_utils.c \
ft_fill.c \
flags.c

OBJ = ${SRCS:.c=.o}

NAME = libftprintf.a

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

all : ${OBJ} ${LIBFT}
	cp ${LIBFT} ${NAME}
	ar rcs ${NAME} ${OBJ}
	@echo
	@echo
	@echo
	@echo
	@echo
	@echo
	@echo PENSE A REMETTRE LE FLAG WERROR
	@echo PENSE A REMETTRE LE FLAG WERROR
	@echo PENSE A REMETTRE LE FLAG WERROR

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

%.o : %.c Makefile ft_printf.h
	${CC} ${CFLAGS} $< -o $@

.PHONY : all clean fclean re libft