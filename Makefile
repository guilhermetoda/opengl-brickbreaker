CC =g++
CFLAGS=-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
LIBS=/usr/local/lib/libglfw.3.dylib

default: main

%.o: src/%.cpp
	$(CC) -c  $<

main: breaker.o player.o renderer.o game.o block.o
	$(CC) -Wall -o main src/main.cpp breaker.o player.o renderer.o game.o block.o $(LIBS) $(CFLAGS)


clean:
	rm -f *.o 
	rm main
