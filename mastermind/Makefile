CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -O0 

SOURCES = my_mastermind.c my_game.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = my_mastermind

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ 


.PHONY: clean

clean:
	@rm -f $(TARGET) $(OBJECTS) core