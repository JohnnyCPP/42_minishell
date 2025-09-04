# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#              #
#    Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


## VARIABLE DECLARATIONS ##
###########################


NAME			= libft.a


PREF			= ft_
BIT_DIR			= ${PREF}bit
CHAR_DIR		= ${PREF}char
STR_DIR			= ${PREF}string
MEM_DIR			= ${PREF}memory
FD_DIR			= ${PREF}fd
FUNC_DIR		= ${PREF}function
LIST_DIR		= ${PREF}list
PRTF_DIR		= ${PREF}printf
GNL_DIR			= ${PREF}gnl
MATH_DIR		= ${PREF}math


INC_PATH		= ./include/
OBJ_PATH		= ./object/
SRC_PATH		= ./src/


CC				= cc
DEBUG_SYMBOLS	= -g3
CFLAGS			= -Wall -Wextra -Werror ${DEBUG_SYMBOLS}
INCLUDE			= -I ${INC_PATH}
MAKE_LIB		= make -sC


BIT_SRC_FILES	= ft_get_bit.c \
                  ft_split_binary.c \
				  ft_to_binary.c
CHAR_SRC_FILES	= ft_isalnum.c \
				  ft_isalpha.c \
				  ft_isascii.c \
				  ft_isbinary.c \
				  ft_isdigit.c \
				  ft_ishex.c \
				  ft_islower.c \
				  ft_isprint.c \
				  ft_issign.c \
				  ft_isspace.c \
				  ft_isupper.c \
				  ft_tolower.c \
				  ft_toupper.c
STR_SRC_FILES	= ft_atoi.c \
				  ft_ioverflow.c \
				  ft_itoa.c \
				  ft_ltoa.c \
				  ft_strchr.c \
				  ft_strdup.c \
				  ft_strlcat.c \
				  ft_strlen.c \
				  ft_strnstr.c \
				  ft_strtrim.c \
				  ft_atol.c \
				  ft_isbinarystr.c \
				  ft_loverflow.c \
				  ft_split.c \
				  ft_strcmp.c \
				  ft_strjoin.c \
				  ft_strlcpy.c \
				  ft_strncmp.c \
				  ft_strrchr.c \
				  ft_substr.c
MEM_SRC_FILES	= ft_bzero.c \
				  ft_calloc.c \
				  ft_memchr.c \
				  ft_memcmp.c \
				  ft_memcpy.c \
				  ft_memmove.c \
				  ft_memset.c
FD_SRC_FILES	= ft_putchar_fd.c \
				  ft_putendl_fd.c \
				  ft_putlong_fd.c \
				  ft_putnbr_fd.c \
				  ft_putstr_fd.c
FUNC_SRC_FILES	= ft_striteri.c \
				  ft_strmapi.c
LIST_SRC_FILES	= ft_list_add_back.c \
				  ft_list_add_front.c \
				  ft_list_clear.c \
				  ft_list_delete_one.c \
				  ft_list_iterate.c \
				  ft_list_last.c \
				  ft_list_map.c \
				  ft_list_new.c \
				  ft_list_size.c
PRTF_SRC_FILES	= ft_pf_char.c \
				  ft_pf_long.c \
				  ft_pf_ph_base.c \
				  ft_pf_ph_int.c \
				  ft_pf_ph_percentage.c \
				  ft_pf_ptr.c \
				  ft_pf_uns_int.c \
				  ft_printf.c \
				  ft_pf_int.c \
				  ft_pf_lower_hex.c \
				  ft_pf_ph_default.c \
				  ft_pf_ph_long.c \
				  ft_pf_ph_str.c \
				  ft_pf_str.c \
				  ft_pf_upper_hex.c
GNL_SRC_FILES	= ft_gnl.c \
                  ft_gnl_utils.c
MATH_SRC_FILES	= ft_abs.c \
                  ft_min.c \
				  ft_sqrt.c


BIT_SRCS		= $(addprefix ${SRC_PATH}${BIT_DIR}/, ${BIT_SRC_FILES})
CHAR_SRCS		= $(addprefix ${SRC_PATH}${CHAR_DIR}/, ${CHAR_SRC_FILES})
STR_SRCS		= $(addprefix ${SRC_PATH}${STR_DIR}/, ${STR_SRC_FILES})
MEM_SRCS		= $(addprefix ${SRC_PATH}${MEM_DIR}/, ${MEM_SRC_FILES})
FD_SRCS			= $(addprefix ${SRC_PATH}${FD_DIR}/, ${FD_SRC_FILES})
FUNC_SRCS		= $(addprefix ${SRC_PATH}${FUNC_DIR}/, ${FUNC_SRC_FILES})
LIST_SRCS		= $(addprefix ${SRC_PATH}${LIST_DIR}/, ${LIST_SRC_FILES})
PRTF_SRCS		= $(addprefix ${SRC_PATH}${PRTF_DIR}/, ${PRTF_SRC_FILES})
GNL_SRCS		= $(addprefix ${SRC_PATH}${GNL_DIR}/, ${GNL_SRC_FILES})
MATH_SRCS		= $(addprefix ${SRC_PATH}${MATH_DIR}/, ${MATH_SRC_FILES})
SRC_FILES		= ${BIT_SRCS} ${CHAR_SRCS} ${STR_SRCS} ${MEM_SRCS} ${FD_SRCS} ${FUNC_SRCS} ${LIST_SRCS} ${PRTF_SRCS} ${GNL_SRCS} ${MATH_SRCS}
OBJ_FILES		= $(patsubst ${SRC_PATH}%.c, ${OBJ_PATH}%.o, ${SRC_FILES})


CREATE_INDEX	= ranlib
CREATE_LIB		= ar rc
CREATE_PATH		= mkdir -p
DELETE_FILE		= rm -f
DELETE_PATH		= rm -fr


ALL				= all
DELETE			= delete_library
CLEAN			= clean
FCLEAN			= fclean
RE				= re


## RULES ##
###########


${ALL}: ${NAME}


# "$@" refers to the target (%.o)
# "$<" refers to the dependency (%.c)
${OBJ_PATH}%.o: ${SRC_PATH}%.c
	@${CREATE_PATH} $(dir $@)
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@


${NAME}: ${OBJ_FILES}
	@${CREATE_LIB} ${NAME} ${OBJ_FILES}
	@${CREATE_INDEX} ${NAME}
	@echo "The library \"${NAME}\" has been compiled."


${DELETE}:
	@if [ -e ${NAME} ]; then \
		${DELETE_FILE} ${NAME}; \
		echo "The library \"${NAME}\" has been deleted."; \
	fi


${CLEAN}:
	@if [ -d ${OBJ_PATH} ]; then \
		${DELETE_FILE} ${OBJ_FILES}; \
		${DELETE_PATH} ${OBJ_PATH}; \
		echo "The objects of library \"${NAME}\" have been deleted."; \
	fi


${FCLEAN}: ${CLEAN} ${DELETE}


${RE}: ${FCLEAN} ${ALL}


.PHONY: ${ALL} ${DELETE} ${CLEAN} ${FCLEAN} ${RE}
