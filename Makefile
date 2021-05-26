# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/11 11:23:45 by bmangin           #+#    #+#              #
#    Updated: 2021/04/24 22:24:46y bmangin          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = Cub3d

L_PATH		= libft
M_PATH		= minilibx
I_PATH		= includes
S_PATH		= srcs
T_PATH		= textures
B_PATH		= bin

VPATH		= ${OBJS1}
#Parsing \
#Raycasting \
#Error \
#Windows \
#Main

FILES_P		= ft_read_file.c ft_init_struct.c

FILES_R		= raycasting.c

FILES_E		= test.c ft_error.c

FILES_W		= ft_windows.c key_event_move.c minimap.c move.c init_texture.c

FILES_M		= cub3d.c main.c tools.c mlx_tools.c drawline.c

FILES		= ${addprefix Parsing/, ${FILES_P}} \
			${addprefix Raycasting/, ${FILES_R}} \
			${addprefix Error/, ${FILES_E}} \
			${addprefix Windows/, ${FILES_W}} \
			${addprefix Main/, ${FILES_M}}
SRCS		= ${addprefix ${S_PATH}/, ${FILES}}
OBJS		= ${addprefix ${B_PATH}/, ${notdir ${SRCS:.c=.o}}}
OBJS1		= ${addprefix srcs/, Parsing} \
			${addprefix srcs/, Raycasting} \
			${addprefix srcs/, Error} \
			${addprefix srcs/, Windows} \
			${addprefix srcs/, Main}

TEST		= ${addprefix ${SRCS}, ${dir ${FILES}}} 

INC_FILES = cub3d.h
INC			= ${addprefix ${I_PATH}/, ${INC_FILES}}

LIBFT_NAME	= libft.a
LIBFT		= ${addprefix ${L_PATH}/, ${LIBFT_NAME}}

MINI_NAME	= libmlx.dylib
MINI_INC	= mlx.h
MINILIBX	= ${addprefix ${M_PATH}/, ${MINI_NAME}}
INC_MLX		= ${addprefix ${M_PATH}/, ${MINI_INC}}

CC			= clang
FLAGS		= -Wall -Wextra -Werror -g
FLAGS_FS	= -Wall -Wextra -Werror -g3 -fsanitize=address
FLAGS_O		= -Wall -Wextra -Werror -O3
FSANIT		= -g3 -fsanitize=address
MLX			= -L ${M_PATH} -lmlx
MAKE		= make -C
CP			= cp 
RM			= rm -rf

all:		lib ${NAME}

lib:		crea_b
		${MAKE} ${M_PATH}
		${MAKE} ${L_PATH}
		${CP} ${MINILIBX} .
		${CP} ${LIBFT} .

${B_PATH}/%.o:	%.c ${INC} ${INC_MLX} 
		${CC} ${FLAGS} -I ${M_PATH} -I ${I_PATH} -c $< -o $@

${NAME}:	${OBJS} ${INC}
		${CC} ${FLAGS} -I ${M_PATH} -I ${I_PATH} ${MLX} ${LIBFT} ${OBJS} -o $@

opti:		${SRCS} ${INC} ${INC_MLX}
		${CC} ${FLAGS_O} -I ${M_PATH} -I ${I_PATH} ${MLX} ${LIBFT} ${SRCS} -o ${NAME}

fs:			${SRCS} ${INC} ${INC_MLX}
		${CC} ${FLAGS_FS} -I ${M_PATH} -I ${I_PATH} ${MLX} ${LIBFT} ${SRCS} -o ${NAME}

crea_b :
		${shell mkdir -p ${B_PATH}}
	
clean:
		${RM} ${B_PATH}

fclean:		clean
		${MAKE} ${L_PATH} fclean
		${MAKE} ${M_PATH} clean	
		${RM} ${LIBFT_NAME}
		${RM} ${MINI_NAME}
		${RM} ${NAME}

minitruc :
		@echo("_______ _____ __   _ _____")
		@echo("|  |  |   |   | \  |   |")
		@echo("|  |  | __|__ |  \_| __|__")
		@echo("__________________________")
		@echo("      _____ _____  _     _")
		@echo("|       |   |____]  \___/")
		@echo("|____ __|__ |____] _/   \_")
		@echo("  			 is ready !!!")

re:			fclean all

seg:		fclean lib fs

oreo:		fclean lib opti

.PHONY: all lib op opti fsanit fs clean fclean re bonus