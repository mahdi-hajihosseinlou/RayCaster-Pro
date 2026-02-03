CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lraylib -lm

SOURCES = main.c raycaster.c map.c player.c
OBJECTS = $(SOURCES:.c=.o)
EXEC = raycaster

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXEC)
