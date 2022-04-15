prog: code.o main.o
	gcc code.o main.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
 
main.o: main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
code.o: code.c
	gcc -c code.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
clean:
	rm -fr prog
execute:
	./prog

