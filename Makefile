CC = gcc
CFLAGS = -Wall -Wextra -g
SRCS = main.c shell.c prompt.c input.c executor.c
OBJS = $(SRCS:.c=.o)
TARGET = minishell

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c shell.h
	$(CC) $(CFLAGS) -c $<

run: all
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)