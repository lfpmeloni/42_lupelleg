# Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Sources and objects
SRCS = main.c rush00.c rush01.c rush02.c rush03.c rush04.c ft_putchar.c
OBJS = $(SRCS:.c =.o)

# Output file
TARGET = main

# Default target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)