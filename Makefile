NAME =	so_long

INC =	include

SRCS =	srcs/main.c 		\

MLX = mlx_linux

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -g 
FLAGS_MLX=-L/usr/lib -lXext -lX11 -lm

all: $(NAME)

%.o:  %.c
	$(CC) $(CFLAGS) $< -I$(INC) -c -o $@

$(NAME) : $(OBJS) 
	-make -C mlx_linux
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux $(FLAGS_MLX) -Imlx_linux -o $(NAME) 

clean :
	$(RM) $(OBJS)

fclean : clean
	-make clean -C mlx_linux 
	$(RM) $(NAME)

re : fclean all

bonus : all
