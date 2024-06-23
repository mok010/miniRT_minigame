NAME	=	so_long

SRCS	=	src/so_long.c\
			src/get_next_line.c\
			src/get_next_line_util.c\
			src/map_check.c\
			src/map_draw.c\
			src/map_draw_util1.c\
			src/map_draw_util2.c\
			src/map_draw_util3.c\
			src/map_draw_util4.c\
			src/map_ani_ply.c\
			src/map_ani_ene.c\
			src/so_long_util.c\
			src/so_long_util2.c\
			src/so_long_util3.c\
			src/map_check_util.c\
			src/print_score.c

OBJS = $(SRCS:%.c=%.o)

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
CLIB	=	-lmlx -framework OpenGL -framework Appkit -Imlx

all		: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME)

%.o	:%.c
	$(CC) $(CFLAGS)  -c $< -o $@

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf	$(NAME)

re		: fclean all
