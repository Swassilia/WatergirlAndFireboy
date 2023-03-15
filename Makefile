EXEC_NAME = bin/test 
OBJ_FILES =obj/mainTest.o obj/Bonus.o  obj/Obstacle.o obj/Personnage.o obj/Vect2.o

CC = g++
CFLAGS = -Wall -ggdb
INCLUDES = -I./extern/include

all: $(EXEC_NAME)


bin/test: obj/mainTest.o obj/Personnage.o  obj/Obstacle.o obj/Bonus.o obj/Vect2.o
	$(CC) -g  obj/mainTest.o obj/Personnage.o  obj/Obstacle.o obj/Bonus.o  obj/Vect2.o -o bin/test
	
obj/mainTest.o: src/core/mainTest.cpp obj/Personnage.o  obj/Obstacle.o obj/Bonus.o
	$(CC) $(CFLAGS) $(INCLUDES) -c src/core/mainTest.cpp -o obj/mainTest.o


obj/Bonus.o:  src/core/Bonus.h src/core/Bonus.cpp src/core/Vect2.h src/core/Type.h 
	$(CC) $(CFLAGS) $(INCLUDES)  -c src/core/Bonus.cpp  -o obj/Bonus.o

obj/Obstacle.o:  src/core/Obstacle.h src/core/Obstacle.cpp src/core/Vect2.h src/core/Type.h 
	$(CC) $(CFLAGS) $(INCLUDES)  -c src/core/Obstacle.cpp  -o obj/Obstacle.o


obj/Personnage.o: src/core/Personnage.cpp src/core/Personnage.h src/core/Vect2.h src/core/Type.h 
	$(CC) $(CFLAGS) $(INCLUDES) -c src/core/Personnage.cpp -o obj/Personnage.o 

obj/Vect2.o: src/core/Vect2.cpp src/core/Vect2.h
	$(CC) $(CFLAGS) $(INCLUDES) -c src/core/Vect2.cpp -o obj/Vect2.o





clean:
	rm $(OBJ_FILES)
	rm $(EXEC_NAME)
