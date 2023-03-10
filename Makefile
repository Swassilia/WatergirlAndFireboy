EXEC_NAME = bin/test 
OBJ_FILES = obj/mainTest obj/Bonus.o obj/Image.o obj/Jeu.o obj/Obstacle.o obj/Personnage.o obj/Pixel.o obj/Plateau.o obj/Vect2.o

CC = g++
CFLAGS = -Wall -ggdb
INCLUDES = -I./extern/include

all: $(EXEC_NAME)


# bin/test: obj/mainTest.o obj/Jeu.o obj/Plateau.o 
# 	g++ -g obj/mainTest.o obj/Jeu.o obj/Plateau.o -o bin/test
	
obj/mainTest.o: src/mainTest.cpp src/core/Jeu.h src/core/Plateau.h
	$(CC) $(CFLAGS) $(INCLUDES) -c src/mainTest.cpp -o obj/mainTest.o

obj/Jeu.o: src/core/Jeu.cpp src/core/Jeu.h src/core/Personnage.h src/core/Obstacle.h src/core/Plateau.h src/core/Bonus.h src/core/Vect2.h 
	$(CC) $(CFLAGS) $(INCLUDES) -c src/core/Jeu.cpp -o obj/Jeu.o
 
obj/Plateau.o: src/core/Plateau.cpp src/core/Plateau.h src/core/Obstacle.h src/core/Bonus.h src/core/Personnage.h
	$(CC) $(CFLAGS) $(INCLUDES) -c src/core/Plateau.cpp -o obj/Plateau.o
 
obj/Personnage.o: src/core/Personnage.cpp src/core/Personnage.h src/core/Type.h src/core/Vect2.h src/core/Plateau.h
 	$(CC) $(CFLAGS) $(INCLUDES) -c src/core/Personnage.cpp -o obj/Personnage.o
 
obj/Obstacle.o: src/core/Obstacle.cpp src/core/Obstacle.h src/core/Type.h src/core/Vect2.h
 	$(CC) $(CFLAGS) $(INCLUDES) -c src/core/Obstacle.cpp -o obj/Obstacle.o
 
obj/Bonus.o: src/core/Bonus.cpp src/core/Bonus.h src/core/Type.h src/core/Vect2.h
 	$(CC) $(CFLAGS) $(INCLUDES) -c src/core/Bonus.cpp -o obj/Bonus.o
 
obj/Image.o: src/core/Image.cpp src/core/Image.h src/core/Pixel.h
 	$(CC) $(CFLAGS) $(INCLUDES) -c src/core/Image.cpp -o obj/Image.o
 
obj/Pixel.o: src/core/Pixel.cpp src/core/Pixel.h
 	$(CC) $(CFLAGS) $(INCLUDES) -c src/core/Pixel.cpp -o obj/Pixel.o
 
obj/Vect2.o: src/core/Vect2.cpp src/core/Vect2.h
 	$(CC) $(CFLAGS) $(INCLUDES) -c src/core/Vect2.cpp -o obj/Vect2.o

clean:
	rm $(OBJ_FILES)
	rm $(EXEC_NAME)
