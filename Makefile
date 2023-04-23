EXEC_NAME = bin/jeu bin/text bin/sdl bin/test
OBJ_FILES = obj/mainSdl.o obj/mainTest.o obj/mainTxt.o obj/Personnage.o obj/Vect2.o obj/Plateau.o obj/Jeu.o obj/JeuTxt.o obj/WinTxt.o obj/JeuSdl.o obj/Objet.o obj/MainMenu.o obj/Menu.o

CC = g++
CFLAGS = -Wall -ggdb
INCLUDES = -I./extern/include

all: $(EXEC_NAME)


bin/jeu: obj/MainMenu.o obj/Menu.o 
	$(CC) -g  obj/MainMenu.o obj/Menu.o -o bin/jeu

bin/text: obj/mainTxt.o obj/WinTxt.o obj/Vect2.o obj/Personnage.o obj/Plateau.o obj/Jeu.o obj/JeuTxt.o obj/Objet.o 
	$(CC) -g  obj/mainTxt.o obj/WinTxt.o obj/Vect2.o obj/Personnage.o obj/Plateau.o obj/Jeu.o obj/JeuTxt.o obj/Objet.o -o bin/text 
	
bin/sdl: obj/mainSdl.o obj/JeuSdl.o obj/Jeu.o obj/Vect2.o obj/Personnage.o obj/Plateau.o obj/Objet.o
	$(CC) -g obj/mainSdl.o obj/JeuSdl.o obj/Jeu.o obj/Vect2.o  obj/Personnage.o obj/Plateau.o obj/Objet.o -o bin/sdl -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -I/usr/include/SDL2

bin/test: obj/mainTest.o obj/Jeu.o obj/Vect2.o obj/Personnage.o obj/Plateau.o obj/Objet.o
	$(CC) -g obj/mainTest.o obj/Jeu.o obj/Vect2.o obj/Personnage.o obj/Plateau.o obj/Objet.o -o bin/test 

obj/mainTest.o: src/core/mainTest.cpp obj/Personnage.o obj/Plateau.o obj/Jeu.o obj/Objet.o
	$(CC) $(CFLAGS) $(INCLUDES) -c src/core/mainTest.cpp -o obj/mainTest.o

obj/mainTxt.o: src/txt/mainTxt.cpp obj/WinTxt.o obj/JeuTxt.o 
	$(CC) $(CFLAGS) $(INCLUDES) -c src/txt/mainTxt.cpp -o obj/mainTxt.o

obj/mainSdl.o: src/SDL/mainSdl.cpp obj/JeuSdl.o obj/Jeu.o obj/Vect2.o obj/Personnage.o obj/Plateau.o obj/Objet.o
	$(CC) $(CFLAGS) $(INCLUDES) -c src/SDL/mainSdl.cpp -o obj/mainSdl.o -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -I/usr/include/SDL2

obj/MainMenu.o: src/core/MainMenu.cpp src/core/Menu.h
	$(CC) $(CFLAGS) $(INCLUDES) -c src/core/MainMenu.cpp -o obj/MainMenu.o



obj/JeuTxt.o: src/txt/JeuTxt.h src/txt/JeuTxt.cpp src/core/Jeu.h 
	$(CC) $(CFLAGS) $(INCLUDES) -c src/txt/JeuTxt.cpp -o obj/JeuTxt.o

obj/WinTxt.o: src/txt/WinTxt.h src/txt/WinTxt.cpp  
	$(CC) $(CFLAGS) $(INCLUDES) -c src/txt/WinTxt.cpp -o obj/WinTxt.o

obj/JeuSdl.o: src/SDL/JeuSdl.h src/SDL/JeuSdl.cpp src/core/Jeu.h obj/Vect2.o obj/Personnage.o obj/Plateau.o obj/Objet.o
	$(CC) $(CFLAGS) $(INCLUDES) -c src/SDL/JeuSdl.cpp -o obj/JeuSdl.o -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -I/usr/include/SDL2

	

obj/Jeu.o:  src/core/Jeu.h src/core/Jeu.cpp src/core/Vect2.h src/core/Type.h  src/core/Personnage.h src/core/Plateau.h
	$(CC) $(CFLAGS) $(INCLUDES)  -c src/core/Jeu.cpp  -o obj/Jeu.o

obj/Personnage.o: src/core/Personnage.cpp src/core/Personnage.h src/core/Vect2.h src/core/Type.h src/core/Plateau.h 
	$(CC) $(CFLAGS) $(INCLUDES) -c src/core/Personnage.cpp -o obj/Personnage.o  
	
obj/Plateau.o: src/core/Plateau.cpp src/core/Plateau.h  src/core/NomCase.h src/core/Objet.h 
	$(CC) $(CFLAGS) $(INCLUDES)  -c src/core/Plateau.cpp  -o obj/Plateau.o 

obj/Objet.o: src/core/Objet.cpp src/core/Plateau.h src/core/Vect2.h src/core/Type.h
	$(CC) $(CFLAGS) $(INCLUDES) -c src/core/Objet.cpp -o obj/Objet.o

obj/Vect2.o: src/core/Vect2.cpp src/core/Vect2.h
	$(CC) $(CFLAGS) $(INCLUDES) -c src/core/Vect2.cpp -o obj/Vect2.o

# obj/Animation.o: src/core/Animation.cpp src/core/Animation.h
# 	$(CC) $(CFLAGS) $(INCLUDES) -c src/core/Animation.cpp -o obj/Animation.o

obj/Menu.o: src/core/Menu.cpp src/core/Menu.h
	$(CC) -c src/core/Menu.cpp -o obj/Menu.o



clean:
	rm $(OBJ_FILES)
	rm $(EXEC_NAME)
