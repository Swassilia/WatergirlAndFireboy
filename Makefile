EXEC_NAME = bin/test bin/text
OBJ_FILES =obj/mainTest.o obj/mainTxt.o obj/Bonus.o obj/Obstacle.o obj/Personnage.o obj/Vect2.o obj/Plateau.o obj/Jeu.o obj/JeuTxt.o obj/WinTxt.o

CC = g++
CFLAGS = -Wall -ggdb
INCLUDES = -I./extern/include

all: $(EXEC_NAME)

bin/test: obj/mainTest.o obj/Personnage.o  obj/Obstacle.o obj/Bonus.o obj/Vect2.o obj/Plateau.o obj/Jeu.o
	$(CC) -g  obj/mainTest.o obj/Personnage.o  obj/Obstacle.o obj/Bonus.o  obj/Plateau.o obj/Vect2.o -o bin/test

bin/text: obj/mainTxt.o obj/WinTxt.o obj/Vect2.o obj/Bonus.o obj/Personnage.o  obj/Obstacle.o obj/Plateau.o obj/Jeu.o obj/JeuTxt.o 
	$(CC) -g  obj/mainTxt.o obj/WinTxt.o obj/Vect2.o obj/Bonus.o obj/Personnage.o  obj/Obstacle.o obj/Plateau.o obj/Jeu.o obj/JeuTxt.o -o bin/text
	
obj/mainTest.o: src/core/mainTest.cpp obj/Personnage.o  obj/Obstacle.o obj/Bonus.o obj/Plateau.o obj/Jeu.o
	$(CC) $(CFLAGS) $(INCLUDES) -c src/core/mainTest.cpp -o obj/mainTest.o

obj/mainTxt.o: src/txt/mainTxt.cpp obj/WinTxt.o obj/JeuTxt.o 
	$(CC) $(CFLAGS) $(INCLUDES) -c src/txt/mainTxt.cpp -o obj/mainTxt.o

obj/JeuTxt.o: src/txt/JeuTxt.h src/txt/JeuTxt.cpp src/core/Jeu.h 
	$(CC) $(CFLAGS) $(INCLUDES) -c src/txt/JeuTxt.cpp -o obj/JeuTxt.o

obj/WinTxt.o: src/txt/WinTxt.h src/txt/WinTxt.cpp  
	$(CC) $(CFLAGS) $(INCLUDES) -c src/txt/WinTxt.cpp -o obj/WinTxt.o

obj/Jeu.o:  src/core/Jeu.h src/core/Jeu.cpp src/core/Vect2.h src/core/Type.h src/core/Obstacle.h src/core/Bonus.h src/core/Personnage.h 
	$(CC) $(CFLAGS) $(INCLUDES)  -c src/core/Jeu.cpp  -o obj/Jeu.o

obj/Plateau.o:  src/core/Plateau.h src/core/Plateau.cpp src/core/Vect2.h src/core/Type.h src/core/Obstacle.h src/core/Bonus.h
	$(CC) $(CFLAGS) $(INCLUDES)  -c src/core/Plateau.cpp  -o obj/Plateau.o

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
