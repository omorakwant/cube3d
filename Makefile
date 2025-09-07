CC = cc
FLAGS = -Werror -Wextra -Wall -lmlx -lXext -lX11 -lm -lz
NAME = cube3d

SRCS = main.c  minimap.c utils.c events.c map_init.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -I./includes


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re