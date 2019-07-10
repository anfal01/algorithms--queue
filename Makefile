SRC=$(wildcard *.c)
OBJS=$(SRC:.c=.o)
OUT=hw04
CC=gcc
CCOPTS=-std=c89 -pedantic -g -ggdb -c

all: $(SRC) $(OUT)

$(OUT): $(OBJS)
	@echo -n "Link "
	@echo $@
	$(CC) $(OBJS) -o $@

.c.o:
	@echo -n "Build source "
	@echo $<
	$(CC) $(CCOPTS) $< -o $@

clean:
	rm -f *.o
remake:
	make clean
	make

