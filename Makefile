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

SRCS_BONUS =	srcs_bonus/main.c 								\
		srcs_bonus/main2.c										\
		srcs_bonus/main_utils.c									\
		srcs_bonus/map_parsing/get_next_line_utils.c			\
		srcs_bonus/map_parsing/get_next_line.c					\
		srcs_bonus/map_parsing/mapname.c 						\
		srcs_bonus/map_parsing/parse_content.c					\
		srcs_bonus/map_parsing/character_pos.c					\
		srcs_bonus/map_parsing/parse.c							\
		srcs_bonus/map_parsing/parse_utils.c					\
		srcs_bonus/movement/movement_handler.c					\
		srcs_bonus/movement/check_colision.c					\
		srcs_bonus/collectible/collectible_replace.c			\
		srcs_bonus/end/success.c								\
		srcs_bonus/error.c										\
		srcs_bonus/putimg.c										\

MLX = /usr/local/lib/

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

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
	$(RM) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

bonus : $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) $(FLAGS_MLX) -o $(NAME)