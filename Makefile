INC   = include/
LIBS  = -lraylib -lopengl32 -lgdi32 -lwinmm
FLAGS = -O1 -Wall -std=c99 -Wno-missing-braces
FILES = main.c particleBuffer.c
build:
	gcc $(FILES) -o output/particles.exe $(FLAGS)  -I include/ -L lib/ $(LIBS)
run: build
	./output/particles.exe
clean:
	rm -rf output/*.exe
	rm -rf output/*.o