CC=gcc
CFLAGS=-c -Wall -g
LDFLAGS=
SOURCES=llist.c main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
		$(CC) $(LDFLAGS) $(OBJECTS) -o $@
.c.o:
		$(CC) $(CFLAGS) $< -o $@
clean:
		rm -rf $(OBJECTS) $(EXECUTABLE)