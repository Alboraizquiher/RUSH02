CC = gcc
CFLAGS = -Wall -Werror -Wextra
TARGET = main
SRCS = main.c process.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
