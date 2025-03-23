all: build/main.out clean

build/main.out: src/main.c src/input.c
	@mkdir -p build
	gcc src/main.c src/input.c src/charmap.c -o build/main.out
	@./build/main.out

clean:
	@find build/ -name "*.out" -delete