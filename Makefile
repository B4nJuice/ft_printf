# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgirard <lgirard@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 10:16:41 by lgirard           #+#    #+#              #
#    Updated: 2025/12/09 10:44:50 by lgirard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -c -Wall -Wextra -Werror -I./includes -I./libft

OBJ_PATH = ./srcs/
OBJ_BONUS_PATH = ./srcs_bonus/

SRCS = ${OBJ_PATH}ft_printf.c \
${OBJ_PATH}ft_ptrtohex.c \
${OBJ_PATH}flags_utils.c \
${OBJ_PATH}ft_type_i_2.c \
${OBJ_PATH}ft_type_p_2.c \
${OBJ_PATH}ft_type_x_2.c \
${OBJ_PATH}ft_itobase.c \
${OBJ_PATH}ft_type_c.c \
${OBJ_PATH}ft_type_i.c \
${OBJ_PATH}ft_type_p.c \
${OBJ_PATH}ft_type_s.c \
${OBJ_PATH}ft_type_u.c \
${OBJ_PATH}ft_type_x.c \
${OBJ_PATH}ft_maths.c \
${OBJ_PATH}ft_utils.c \
${OBJ_PATH}ft_fill.c \
${OBJ_PATH}flags.c

SRCS_BONUS = ${OBJ_BONUS_PATH}ft_printf_bonus.c \
${OBJ_BONUS_PATH}ft_ptrtohex_bonus.c \
${OBJ_BONUS_PATH}flags_utils_bonus.c \
${OBJ_BONUS_PATH}ft_type_i_2_bonus.c \
${OBJ_BONUS_PATH}ft_type_p_2_bonus.c \
${OBJ_BONUS_PATH}ft_type_x_2_bonus.c \
${OBJ_BONUS_PATH}ft_itobase_bonus.c \
${OBJ_BONUS_PATH}ft_type_c_bonus.c \
${OBJ_BONUS_PATH}ft_type_i_bonus.c \
${OBJ_BONUS_PATH}ft_type_p_bonus.c \
${OBJ_BONUS_PATH}ft_type_s_bonus.c \
${OBJ_BONUS_PATH}ft_type_u_bonus.c \
${OBJ_BONUS_PATH}ft_type_x_bonus.c \
${OBJ_BONUS_PATH}ft_maths_bonus.c \
${OBJ_BONUS_PATH}ft_utils_bonus.c \
${OBJ_BONUS_PATH}ft_fill_bonus.c \
${OBJ_BONUS_PATH}flags_bonus.c

OBJ = ${SRCS:.c=.o}

OBJ_BONUS = ${SRCS_BONUS:.c=.o}

NAME = libftprintf.a

LIBFT_PATH = ./libft

LIBFT = ${LIBFT_PATH}/libft.a

all : ${OBJ} ${LIBFT}
	cp ${LIBFT} ${NAME}
	ar rcs ${NAME} ${OBJ}

clean :
	make -C $(LIBFT_PATH) clean
	rm -f ${OBJ}
	rm -f ${OBJ_BONUS}

fclean : clean
	make -C $(LIBFT_PATH) fclean
	rm -f ${NAME}

re : fclean all

libft : ${LIBFT}

bonus : ${OBJ_BONUS} ${LIBFT}
	cp ${LIBFT} ${NAME}
	ar rcs ${NAME} ${OBJ_BONUS}

${LIBFT}:
	make -C $(LIBFT_PATH) all

${NAME} : all

%.o : %.c Makefile srcs/ft_printf.h srcs_bonus/ft_printf_bonus.h
	${CC} ${CFLAGS} $< -o $@

.PHONY : all clean fclean re libft