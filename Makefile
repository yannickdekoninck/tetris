CC=gcc
CFLAGS= -framework OpenGL
BUILD_DIR = build
OBJS=$(BUILD_DIR)/tetris.o
BIN=$(BUILD_DIR)/main



all: build_dir $(BIN)

build_dir: $(BUILD_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN)


build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build