NAME		= cub3D

SRC			= 	main.c	\
				mlx_utils.c	\
				mlx_hook_utils1.c \
				mlx_hook_utils2.c \
				init_cub3d.c	\
				init_buf.c \
				init_dir.c \
				init_user_pos.c \
				clean.c	\
				param_parsing.c \
				map_parsing0.c	\
				map_parsing1.c	\
				map_parsing2.c	\
				map_parsing3.c	\
				map_parsing4.c	\
				rgb_parsing_c.c \
				rgb_parsing_f.c \
				quit.c	\
				draw_pixel.c	\
				game.c	\
				dda.c \
				raycast.c	\
				time.c	\

SRCSPATH 	= srcs

INCLUDES	= ./includes/ 

OBJDIR		= all_o

CC			= gcc

LIBFT		=	libft/libft.a

CFLAGS		= -Werror -Wall -Wextra -g3

MLX			=	-L ./mlx/ -lmlx -lXext -lX11 -lm -O3

RM			= rm -rf

SRCS 		= $(addprefix $(SRCSPATH)/,$(SRC))

OBJS        = $(addprefix $(OBJDIR)/,${SRC:.c=.o})

$(OBJDIR)/%.o: $(SRCSPATH)/%.c
	@printf "$(_ORANGE)Compiling : %s\n" $<
	@mkdir -p $(OBJDIR)
	@${MAKE} -C libft > /dev/null
	@${MAKE} -C mlx >/dev/null
	@$(CC) $(CFLAGS) -I $(INCLUDES) -I libft/includes -I mlx -c $< -o $@

all: ${NAME}

${NAME}:	${OBJS}
	@${CC} ${CFLAGS} -I $(INCLUDES) -I libft/includes -I mlx ${OBJS} -o ${NAME} ${LIBFT} ${MLX}
	@printf "$(_GREEN)Compiling DONE !\n"

clean:
	@printf "$(_RED)Removing objects...\n"
	@${RM} ${OBJS} ./all_o/*.o
	@${MAKE} -C libft fclean >/dev/null
	@${MAKE} -C mlx clean >/dev/null

fclean:	clean
	@printf "$(_RED)Removing $(NAME)...\n"
	@${RM} ${NAME} ./all_o/*.o all_o

re: fclean
	make all

################################################# colors

_WHITE = \e[97m
_GREEN = \e[38;5;118m
_ORANGE = \e[38;5;208m
_RED = \e[38;5;196m
_R = \e[0m

#################################################

.PHONY: all clean fclean re
