NAME =	so_long

INC =	include

SRCS =	srcs/main.c 		\

MLX = /usr/local/lib/

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -g 
FLAGS_MLX= -lmlx -framework OpenGl -framework Appkit

all: $(NAME)

%.o:  %.c
	$(CC) $(CFLAGS) $< -I$(INC) -c -o $@

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(FLAGS_MLX) -o $(NAME) 

clean :
	$(RM) $(OBJS)

fclean : clean
	-make clean -C mlx_linux 
	$(RM) $(NAME)

re : fclean all

bonus : all
