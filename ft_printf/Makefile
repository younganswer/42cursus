# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 16:03:07 by younhwan          #+#    #+#              #
#    Updated: 2022/08/01 00:29:07 by younhwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_DIR = libft
LIBFT_NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

INCS_DIR = ./includes

SRCS_DIR = ./srcs
OBJS_DIR = ./objs

#SRCS_BONUS_DIR = ./srcs_bonus
#OBJS_BONUS_DIR = ./objs_bonus

SRCS = 	ft_print_char.c \
		ft_print_hex.c \
		ft_print_nbr.c \
		ft_print_ptr.c \
		ft_print_str.c \
		ft_print_unsigned_int.c \
		ft_printf.c

#SRCS_BONUS = 

SRCS := ${addprefix ${SRCS_DIR}/, ${SRCS}}
#SRCS_BONUS := ${addprefix ${SRC_BONUS_DIR}/, ${SRC_BONUS}}

OBJS = ${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}
#OBJS_BONUS = ${SRC_BONUS:${SRC_BONUS_DIR}/%.c=${OBJ_BONUS_DIR}/%.o}

ifdef WITH_BONUS
	OBJ_FILES = ${OBJS} ${OBJS_BONUS}
	OBJS_DIRS = ${OBJS_DIR} ${OBJS_BONUS_DIR}
else
	OBJ_FILES = ${OBJS}
	OBJS_DIRS = ${OBJS_DIR}
endif

#bonus:
#	WITH_BONUS=1 make all

all: ${NAME}

# ${OBJS_BONUS_DIR}:
# 	mkdir -p objs_bonus

${OBJS_DIR}:
	mkdir -p objs

${OBJ_FILES}: %.o: ${addsuffix .c,${subst obj,src,${%}}} | ${OBJS_DIRS}
	${CC} ${CFLAGS} -c ${patsubst %.o,%.c,${subst obj,src,$@}} -o $@ -I ${INCS_DIR}

${NAME}: ${OBJ_FILES}
	make -C ${LIBFT_DIR}
	cp ${LIBFT_DIR}/${LIBFT_NAME} .
	mv ${LIBFT_NAME} ${NAME}
	${AR} $@ $^

clean:
	make -C ${LIBFT_DIR} clean
	rm -rf ${OBJS_DIR}
#	rm -rf ${OBJS_BONUS_DIR}

fclean: clean
	${RM} ${NAME}
	${RM} ${LIBFT_DIR}/${LIBFT_NAME}

re:
	make fclean
	make all

.PHONY: all clean fclean re #bonus