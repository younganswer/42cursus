SHELL		= /bin/bash
IDX			= 0

NAME		= bureaucrat
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -I${INCS_DIR} -std=c++98 -MD -O3
LDFLAGS		= 
RM			= rm -f

ifdef SANITIZE
	LDFLAGS += -fsanitize=address
endif

INCS_DIR	= incs
SRCS_DIR	= srcs
OBJS_DIR	= objs

SRCS =	main.cpp Bureaucrat.cpp


SRCS := ${addprefix ${SRCS_DIR}/, ${SRCS}}
OBJS := ${SRCS:${SRCS_DIR}/%.cpp=${OBJS_DIR}/%.o}
DEPS := ${OBJS:.o=.d}

SRCS_LEN	= ${shell echo ${SRCS} | wc -w}


all: ${NAME}


${NAME}: ${OBJS}
	@if [ ${IDX} -gt 0 ]; then\
		printf "\b"; echo "done ";\
	fi
	@${CXX} ${LDFLAGS} -o ${NAME} ${OBJS}
	@echo "Build ${NAME}: done"


${OBJS_DIR}/%.o: ${SRCS_DIR}/%.cpp | ${OBJS_DIR}
	${eval IDX = ${shell expr ${IDX} + 1}}
	@if [ ${IDX} = 1 ]; then\
		echo -n "Build dependencies in ${NAME} ...  ";\
	fi
	@printf "%3d%%\b\b\b\b" ${shell expr ${IDX} \* 100 / ${SRCS_LEN}}
	@${CXX} ${CXXFLAGS} -g -c $< -o $@


${OBJS_DIR}:
	@echo "Build ${NAME}"
	@mkdir -p ${OBJS_DIR}


clean:
	@echo "Remove dependencies in ${NAME}"
	@${RM} -r ${OBJS_DIR}


fclean:
	@echo "Remove dependencies in ${NAME}"
	@${RM} -r ${OBJS_DIR}
	@echo "Remove ${NAME}"
	@${RM} ${NAME}
	

re:
	@echo "Rebuild ${NAME}"
	@${MAKE} fclean
	@${MAKE} all


.PHONY: all clean fclean re


.NOTPARALLEL: all clean fclean re


-include ${DEPS}