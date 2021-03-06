CC=gcc
CFLAGS= -l SDL2 -l SDL2_image -l SDL2_ttf
BUILD_DIR = build
ASSET_DIR = $(BUILD_DIR)/assets
OBJS=$(BUILD_DIR)/tetris.o $(BUILD_DIR)/graphics.o $(BUILD_DIR)/field.o $(BUILD_DIR)/blocks.o $(BUILD_DIR)/game_time.o $(BUILD_DIR)/game.o $(BUILD_DIR)/events.o $(BUILD_DIR)/players.o
GFX= $(ASSET_DIR)/tile_light_blue.png $(ASSET_DIR)/tile_light_brown.png $(ASSET_DIR)/tile_light_green.png  $(ASSET_DIR)/tile_dark_blue.png $(ASSET_DIR)/tile_dark_brown.png $(ASSET_DIR)/tile_dark_green.png $(BUILD_DIR)/assets/tile_dark.png $(BUILD_DIR)/assets/tile_light.png $(BUILD_DIR)/assets/minecrafter.ttf 
BIN=$(BUILD_DIR)/main



all: build_dir asset_dir graphics $(BIN)

build_dir: $(BUILD_DIR)

asset_dir: $(ASSET_DIR)

graphics: $(GFX)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(ASSET_DIR):
	mkdir -p $(ASSET_DIR)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN)


build/%.o: src/code/%.c
	$(CC) $(CFLAGS) -c $< -o $@

build/assets/%.png: src/assets/cpld/%.png
	cp $< $@

build/assets/%.ttf: src/assets/cpld/%.ttf
	cp $< $@

clean:
	rm -rf build

test: $(BIN)
	$(BUILD_DIR)/main