CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LIBPRINTF = ft_printf/libftprintf.a


all: server client

bonus: server_bonus client_bonus

$(LIBPRINTF):
	make -C ft_printf

server: $(LIBPRINTF) server.c
	$(CC) server.c ft_printf/libftprintf.a -o server $(CFLAGS)

server_bonus: $(LIBPRINTF) server_bonus.c
	$(CC) server_bonus.c ft_printf/libftprintf.a -o server $(CFLAGS)

client: $(LIBPRINTF) client.c
	$(CC) client.c ft_printf/libftprintf.a -o client $(CFLAGS)

client_bonus: $(LIBPRINTF) client_bonus.c
	$(CC) client_bonus.c ft_printf/libftprintf.a -o client $(CFLAGS)

clean:
	make clean -C ft_printf
	rm -rf server client

fclean: clean
	make fclean -C ft_printf

re: fclean all

.PHONY:all bonus clean fclean re