CC = gcc
CFLAGS = -Wall
OBJS = fm350-tools.o

all: fm350-tools

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

fm350-tools: $(OBJS)
	$(CC) -o $@ $(OBJS)

clean:
	rm -f fm350-tools *.o
