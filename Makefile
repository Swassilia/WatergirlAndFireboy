EXEC_NAME = bin/test 
OBJ_FILES = obj/mainTest obj/Bonus.o obj/Image.o obj/Jeu.o obj/Obstacle.o obj/Personnage.o obj/Pixel.o obj/Plateau.o obj/Vect2.o

CC = g++
CFLAGS = -Wall -ggdb
INCLUDES = -I./extern/include

all: $(EXEC_NAME)


bin/test: obj/mainTest.o obj/Image.o obj/Pixel.o 
	g++ -g obj/mainTest.o obj/Pixel.o obj/Image.o -o bin/test
	
obj/mainTest.o: src/mainTest.cpp src/core/Jeu.h src/core/Plateau.h
	$(CC) $(CFLAGS) $(INCLUDES) -c src/mainTest.cpp -o obj/mainTest.o

# obj/Bonus.o: src/core/
# 	$(CC) $(CFLAGS) $(INCLUDES) -c 
# obj/Image.o:
# 	$(CC) $(CFLAGS) $(INCLUDES) -c 
# obj/Jeu.o:
# 	$(CC) $(CFLAGS) $(INCLUDES) -c 
# obj/Obstacle.o:
# 	$(CC) $(CFLAGS) $(INCLUDES) -c 
# obj/Personnage.o:
# 	$(CC) $(CFLAGS) $(INCLUDES) -c 
# obj/Pixel.o:
# 	$(CC) $(CFLAGS) $(INCLUDES) -c 
# obj/Plateau.o:
# 	$(CC) $(CFLAGS) $(INCLUDES) -c 
# obj/Vect2.o:
# 	$(CC) $(CFLAGS) $(INCLUDES) -c 

clean:
	rm $(OBJ_FILES)
	rm $(EXEC_NAME)
