CC=gcc
CFLAGS= -framework OpenGL
OBJS=tetris.o
BIN=build/main



all:$(BIN)

main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o main


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -r main *.o