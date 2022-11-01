# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younhwan <younhwan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 16:03:07 by younhwan          #+#    #+#              #
#    Updated: 2022/10/22 17:19:45 by younhwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL	= /bin/bash
SPINNER	= /-\|/
IDX		= 0

NAME	= Repetitive\ work

CC			= clang++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -O2
LDFLAGS		= -fsanitize=address -g3
AR			= ar rcs
RM			= rm -f

INCS_DIR	= ./incs
SRCS_DIR	= ./srcs
OBJS_DIR	= ./objs

SRCS =	main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp
		
SRCS := ${addprefix ${SRCS_DIR}/, ${SRCS}}
OBJS = ${SRCS:${SRCS_DIR}/%.cpp=${OBJS_DIR}/%.o}
DEPS = ${OBJS:.o=.d}


all: ${NAME}


${OBJS_DIR}:
	@echo "Build ${NAME}"
	@mkdir -p objs
	@mkdir -p objs/replace
	@mkdir -p objs/utils


${NAME}: ${OBJS}
	@printf "\bdone\n"
	@${CC} ${CXXFLAGS} ${LDFLAGS} -g -o ${NAME} ${OBJS} -I ${INCS_DIR}
	@echo "Build ${NAME}: done"


${OBJS_DIR}/%.o: ${SRCS_DIR}/%.cpp | ${OBJS_DIR}
	${eval IDX = ${shell expr ${IDX} + 1}}
	${eval T_IDX = ${shell expr ${IDX} % 32}}
	${eval T_IDX = ${shell expr ${T_IDX} / 8 + 1}}
	${eval CHR = ${shell echo ${SPINNER} | cut -c ${T_IDX}}}
	@if [ ${IDX} = 1 ]; then\
		echo -n "Build dependencies in ${NAME} ...  ";\
	fi
	@printf "\b${CHR}"
	@${CC} ${CXXFLAGS} -g -c $< -o $@ -I ${INCS_DIR} -MD


clean:
	@echo "Remove dependencies in ${NAME}"
	@rm -rf ${OBJS_DIR}


fclean: clean
	@echo "Remove ${NAME}"
	@${RM} ${NAME}
	

re:
	@make fclean
	@make all


.PHONY: all clean fclean re

-include ${DEPS}