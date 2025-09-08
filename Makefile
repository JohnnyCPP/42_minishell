# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+         #
#        tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#              #
#    Updated: 2025/08/22 17:17:22 by jonnavar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


## VARIABLE DECLARATIONS ##
###########################

INC_PATH		= ./include/
OBJ_PATH		= ./object/
SRC_PATH	    = ./src/
LEX_PATH		= ${SRC_PATH}lexical_analysis/
TOKEN_PATH		= ${SRC_PATH}token/
LIB_PATH		= ${SRC_PATH}lib/
SIGNAL_PATH		= ${SRC_PATH}signal/
BUILTIN_PATH	= ${SRC_PATH}builtin/
ENV_PATH		= ${SRC_PATH}env/
STR_PATH		= ${SRC_PATH}string/
EXT_PATH		= ${SRC_PATH}external/
HIST_PATH		= ${SRC_PATH}history/
RESRC_PATH		= ${SRC_PATH}resources/
LIBFT_PATH		= ${LIB_PATH}libft/
LIBFT_INC_PATH	= ${LIBFT_PATH}include/


LIBFT_FILE		= libft.a
LIBFT_NAME		= ${LIBFT_PATH}${LIBFT_FILE}
NAME			= minishell


CC				= cc
DEBUG_SYMBOLS	= -g3
# I'm not sure if -std=gnu99 flag is allowed
CFLAGS			= -Wall -Wextra -Werror ${DEBUG_SYMBOLS}
GDB				= gdb
# both "-g" or "-g3" flags can be used.
# "-g3" includes everything included with "-g", but with 
# additional information to debug preprocessor directives
SANITIZE_FLAGS	= -fsanitize=address
# "--track-origin=yes" tracks the origin of uninitialized values
# "-s" display a summary of the results directly in the terminal
# "--leak-check=full" enable detailed memory leak detection, and 
#                     report every possible memory leak
VALGRIND_FLAGS	= --track-origins=yes -s --leak-check=full --show-leak-kinds=all
# "-I <path>" instructs the compiler where to look for header files
# "-L <path>" instructs the linker where to look for static (.a) or 
#             shared (.so) libraries
# "-l<file>" instructs the linker to add a specific library by its name.
#            the linker will consider the "lib" prefix and ".a"/".so" sufix.
#            e.g. "-lft" links against "libft.a" or "libft.so".
#            note: this flag can't have a space in between, it's 
#                  processed as a single token
LIB_RLINE		= -l readline
INCLUDE_LIBFT	= -I ${LIBFT_INC_PATH}
INCLUDE			= -I ${INC_PATH} ${INCLUDE_LIBFT}
MAKE_LIB		= make -sC


ALL				= all
DELETE			= delete_library
CLEAN			= clean
FCLEAN			= fclean
RE				= re
BONUS			= bonus
HELP			= help
CC_SANITIZER	= sanitize
B_CC_SANITIZER	= sanitize_bonus
VALGRIND		= valgrind
PREFIX_LIB		= lib_
LIB_DELETE		= ${PREFIX_LIB}${DELETE}
LIB_CLEAN		= ${PREFIX_LIB}${CLEAN}
LIB_FCLEAN		= ${PREFIX_LIB}${FCLEAN}
LIB_RE			= ${PREFIX_LIB}${RE}


PHONY			= .PHONY
STD_PHONY		= ${ALL} ${CLEAN} ${FCLEAN} ${RE} ${BONUS} ${HELP}
DEBUG_PHONY		= ${CC_SANITIZER} ${B_CC_SANITIZER} ${VALGRIND} ${GDB}
CLIENT_PHONY	= ${CLIENT_DELETE} ${CLIENT_CLEAN} ${CLIENT_FCLEAN} ${CLIENT_RE}
LIB_PHONY		= ${LIB_DELETE} ${LIB_CLEAN} ${LIB_FCLEAN} ${LIB_RE}


MAKE_CLIENT		= ${MAKE_LIB} ${CLIENT_PATH}
DELETE_CLIENT	= ${MAKE_CLIENT} delete_client
CLEAN_CLIENT	= ${MAKE_CLIENT} ${CLEAN}
BONUS_CLIENT	= ${MAKE_CLIENT} ${BONUS}


MAKE_LIBFT		= ${MAKE_LIB} ${LIBFT_PATH}
DELETE_LIBFT	= ${MAKE_LIBFT} ${DELETE}
CLEAN_LIBFT		= ${MAKE_LIBFT} ${CLEAN}
FCLEAN_LIBFT	= ${MAKE_LIBFT} ${FCLEAN}
RE_LIBFT		= ${MAKE_LIBFT} ${RE}


ROOT_SRC_FILES	= ms_main.c \
				  ms_repl.c
LEX_SRC_FILES	= ms_char.c \
				  ms_get_tokens.c \
				  ms_lexical_analysis.c \
				  ms_redirection_analysis.c
TOKEN_SRC_FILES	= ms_get_var_len.c \
				  ms_get_var_value.c \
				  ms_strip_quotes.c \
				  ms_token.c \
				  ms_token_validation.c
SGNAL_SRC_FILES	= ms_configure_signals.c \
				  ms_g_signal.c
BLTIN_SRC_FILES	= ms_cd.c \
				  ms_echo.c \
				  ms_env.c \
				  ms_exit.c \
				  ms_export.c \
				  ms_is_builtin.c \
				  ms_pwd.c \
				  ms_run_builtin.c \
				  ms_unset.c
ENV_SRC_FILES	= ms_envlen.c \
				  ms_free_env.c \
				  ms_get_var.c \
				  ms_init_env.c \
				  ms_is_validenv.c \
				  ms_set_var.c \
				  ms_unset_var.c
STR_SRC_FILES	= ms_concat.c \
				  ms_free_strings.c \
				  ms_is_path.c \
				  ms_puterr.c
EXT_SRC_FILES	= ms_get_path.c \
				  ms_run_external.c \
				  ms_to_argv.c
HIST_SRC_FILES	= ms_get_history_path.c \
				  ms_init_history.c \
				  ms_load_history.c \
				  ms_save_history.c
RESRC_SRC_FILES	= ms_free_resources.c \
				  ms_init_resources.c
ROOT_SRCS		= $(addprefix ${SRC_PATH}, ${ROOT_SRC_FILES})
LEX_SRCS		= $(addprefix ${LEX_PATH}, ${LEX_SRC_FILES})
TOKEN_SRCS		= $(addprefix ${TOKEN_PATH}, ${TOKEN_SRC_FILES})
SIGNAL_SRCS		= $(addprefix ${SIGNAL_PATH}, ${SGNAL_SRC_FILES})
BUILTIN_SRCS	= $(addprefix ${BUILTIN_PATH}, ${BLTIN_SRC_FILES})
ENV_SRCS		= $(addprefix ${ENV_PATH}, ${ENV_SRC_FILES})
STR_SRCS		= $(addprefix ${STR_PATH}, ${STR_SRC_FILES})
EXT_SRCS		= $(addprefix ${EXT_PATH}, ${EXT_SRC_FILES})
HIST_SRCS		= $(addprefix ${HIST_PATH}, ${HIST_SRC_FILES})
RESRC_SRCS		= $(addprefix ${RESRC_PATH}, ${RESRC_SRC_FILES})
SRC_FILES		= ${ROOT_SRCS} \
				  ${LEX_SRCS} \
				  ${TOKEN_SRCS} \
				  ${SIGNAL_SRCS} \
				  ${BUILTIN_SRCS} \
				  ${ENV_SRCS} \
				  ${STR_SRCS} \
				  ${EXT_SRCS} \
				  ${HIST_SRCS} \
				  ${RESRC_SRCS}
# "patsubst": pattern substitution
# parameters: pattern, replacement, text
#
# pattern: the pattern to match. Supports wildcards
# replacement: the string to replace the pattern with. By using wildcards, 
#              Make keeps the original text matched by the same 
#              wildcard in the pattern
# text: the list of strings on which the substitution will be performed
OBJ_FILES		= ${patsubst ${SRC_PATH}%.c, ${OBJ_PATH}%.o, ${SRC_FILES}}


CREATE_PATH		= mkdir -p
DELETE_FILE		= rm -f
DELETE_PATH		= rm -fr


## RULES ##
###########


${ALL}: ${NAME}


# "$@" refers to the target (%.o)
# "$<" refers to the dependency (%.c)
${OBJ_PATH}%.o: ${SRC_PATH}%.c
	@${CREATE_PATH} $(dir $@)
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@


${NAME}: ${LIBFT_NAME} ${OBJ_FILES}
	@${CC} ${CFLAGS} ${OBJ_FILES} ${LIBFT_NAME} ${LIB_RLINE} -o ${NAME}
	@echo "The program \"${NAME}\" has been compiled."


${CLEAN}: ${LIB_CLEAN}
	@${DELETE_FILE} ${OBJ_FILES}
	@${DELETE_PATH} ${OBJ_PATH}
	@echo "The objects of program \"${NAME}\" have been deleted."


${FCLEAN}: ${LIB_CLEAN} ${LIB_DELETE} ${CLEAN}
	@${DELETE_FILE} ${LIBFT_NAME}
	@${DELETE_FILE} ${NAME}
	@echo "The program \"${NAME}\" has been deleted."


${RE}: ${FCLEAN} ${ALL}


#${BONUS}: ${LIBFT_NAME} ${BONUS_OBJECTS}
#	@if [ ! -e ${NAME} ]; then \
#		${BONUS_CLIENT}; \
#		${CC} ${CFLAGS} ${BONUS_OBJECTS} ${LIBFT_NAME} -o ${NAME}; \
#		echo "The program \"${NAME}\" has been compiled including bonus."; \
#	else \
#		echo "The program \"${NAME}\" already exists. Skipping compilation."; \
#	fi


${CC_SANITIZER}: ${LIBFT_NAME} ${OBJ_FILES}
	@${CC} ${CFLAGS} ${SANITIZE_FLAGS} ${OBJ_FILES} ${LIBFT_NAME} ${LIB_RLINE} -o ${NAME}
	@echo "C compiler's sanitizer has been added to debug memory issues."


${VALGRIND}:
	@${VALGRIND} ${VALGRIND_FLAGS} ./${NAME}


${GDB}:
	@${GDB} ./${NAME}


${HELP}:
	@echo "Available targets:"
	@echo "    all            - Build the project (default)"
	@echo "    clean          - Remove object files"
	@echo "    fclean         - Remove object files and the executable"
	@echo "    re             - Rebuild the project"
	@echo "    sanitize       - Build with address sanitizer for debugging"
	@echo "    valgrind       - Run the program with valgrind"
	@echo "    gdb            - Run the program with gdb"


# library rules
# #############


${LIBFT_NAME}:
	@${MAKE_LIBFT}


${LIB_DELETE}:
	@${DELETE_LIBFT}


${LIB_CLEAN}:
	@${CLEAN_LIBFT}


${LIB_FCLEAN}:
	@${FCLEAN_LIBFT}


${LIB_RE}:
	@${RE_LIBFT}


${PHONY}: ${STD_PHONY} ${DEBUG_PHONY} ${CLIENT_PHONY} ${LIB_PHONY}


# about compile_commands.json
# ###########################


# Build EAR (bear) command has been used with the default target of this Makefile:
# "bear -- make"
#
# "compile_commands.json" is the product of executing this command, and records every compilation step
#
# Finally, during development, Clangd reads this file to provide smart features
