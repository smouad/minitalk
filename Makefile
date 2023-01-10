CC		= cc
CFLAGS	= -Wall -Wextra -Werror

all:
	cd ft_printf && make
	cd ../
	$(CC) server.c ft_printf/libftprintf.a -o server $(CFLAGS)
	$(CC) client.c ft_printf/libftprintf.a -o client $(CFLAGS)

bonus:
	cd ft_printf && make
	cd ../
	$(CC) server_bonus.c ft_printf/libftprintf.a -o server_bonus $(CFLAGS)
	$(CC) client_bonus.c ft_printf/libftprintf.a -o client_bonus $(CFLAGS)

clean:
	rm -rf server client

fclean: clean
	cd ft_printf && make fclean
re: clean all

.PHONY:all bonus clean fclean re