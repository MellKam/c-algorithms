BUILD_DIR = build
CC = gcc

build_dir:
	if [ ! -d $(BUILD_DIR) ]; then mkdir $(BUILD_DIR); fi

matrix.o: ./src/matrix/matrix.c ./src/matrix/matrix.h build_dir
	$(CC) -c ./src/matrix/matrix.c -o ./$(BUILD_DIR)/matrix.o

main: matrix.o build_dir
	$(CC) -o ./$(BUILD_DIR)/target ./src/main.c ./$(BUILD_DIR)/matrix.o

build: main

run: build
	./$(BUILD_DIR)/target

clean:
	rm -r ./$(BUILD_DIR)/*