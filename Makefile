NAME =	so_long

INC =	include

SRCS =	srcs/main.c 								\
		srcs/main2.c								\
		srcs/main_utils.c							\
		srcs/map_parsing/get_next_line_utils.c		\
		srcs/map_parsing/get_next_line.c			\
		srcs/map_parsing/mapname.c 					\
		srcs/map_parsing/parse_content.c			\
		srcs/map_parsing/character_pos.c			\
		srcs/map_parsing/parse.c					\
		srcs/map_parsing/parse_utils.c				\
		srcs/movement/movement_handler.c			\
		srcs/movement/check_colision.c				\
		srcs/collectible/collectible_replace.c		\
		srcs/end/success.c							\
		srcs/error.c								\
		srcs/putimg.c								\

MLX = /usr/local/lib/

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra 
FLAGS_MLX= -lmlx -framework OpenGl -framework Appkit

all: $(NAME)

%.o:  %.c
	$(CC) $(CFLAGS) $< -I$(INC) -c -o $@

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(FLAGS_MLX) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

bonus : all
