# WaterGirl & FireBoy



## Etudiants

p2100663 Wassila Said Karim

p2018499 Acil Kasraoui

p2103289 Esra Colmek
## Présentation du projet 

Création d'un jeu d’arcade destiné à un public de plus de 10 ans. Il est inspiré du fameux jeu FireBoy And WaterGirl de Oslo Albet. Avec un délais de 9 semaines, nous avons essayé de finaliser au plus le code de notre jeu pour un rendu similaire au jeu d'origine et des fonctionnalitées suffisantes pour permettre une bonne partie de jeu.



#### Les règles du jeu

Le jeu peut se jouer à deux.Un des joueurs représente l’eau (WaterGirl) et le deuxième le feu (FireBoy).Ces deux éléments vont devoirs traverser le labyrinthe pour arriver à la fin où ils devront se placer sur les portes attribuées pour chacun des personnages. Des obstacles seront disposés dans le parcours, ils devront les franchir sans mourir tout en essayant de gagner le plus de points possibles grâce aux diamants récupérables.

#### Quelques détails sur les éléments du parcours

Le personnage feu ne doit pas toucher les obstacles de type eau et de type acide, cependant il peut passer à travers une rivière de lave et récuperer les diamants rouges.
Le personnage eau, lui, ne doit pas toucher les obstacles de type feu et de type acide, cependant il peut passer à traver une rivière d'eau et récuperer les diamants bleus.

## Organisation de l'archive

#### La Librairie
L'utilisation de la librairie SDL (Simple DirectMedia Layer) nous permet ici d'afficher une représentation 2D de notre jeu dans une fenêtre de taille définie. De plus, elle nous donne accès au clavier pour qu'on puisse gérer les mouvements et utiliser les fonctionnalités de notre jeu.

## Les répertoires

L'archive WaterGirl_FireBoy__12100663_12018499_12103289.tar.gz contient contient un **Makefile**, un **Readme** et 5 répertoires:

**bin** contient les exécutables des
programmes principaux qui seront utiliser pour afficher le jeu: *sdl*, *text*, *jeu* et *test*.

**data** contient les images sous format PNG à utiliser par le programme. 

**doc** contient le fichier de configuration du doxygen *jeulabyrinthe.doxy*, le diagramme de Gantt, le diagramme des classes (format PNG), et la présentation orale du projet (format pdf).

**obj** contient les fichiers objets crées par le Makefile: 

    -Jeu.o 
    -JeuSdl.o 
    -Jeu.txt 
    -MainMenu.o 
    -mainSdl.o 
    -mainTest.o 
    -mainTxt.o 
    -Menu.o 
    -Objet.o 
    -Personnage.o
    -Plateau.o 
    -Vect2.o 
    -WinTxt.o *

**src** contient les fichiers sources du programme. Ce répertoire est lui même constitué de plusieurs sous-répertoires:

- **core** contient le noyau du programme, c'est à dire les fichiers .h et .cpp des classes essentielles du programme.
- **SDL** contient les fichiers nécessaires à l'affichage SDL du jeu, c'est dans ces fichiers que l'on appelle la libraire SDL et que l'on charge les images nécessaires au rendu voulu.
- **txt** contient les fichiers nécessaire à l'affiche en mode texte du jeu.

## Compiler et Exécuter le programme

Pour compiler, le fichier Makefile crée les exécutables de la forme "./bin/fonction" correspondants aux 4 fonctions main que l'on va appeler pour afficher notre jeu, 13 fichiers objets de la forme "obj/fonction.o" qui vont permettre de créer ces exécutables (dans l'orde):

    - bin/jeu: obj/MainMenu.o obj/Menu.o 
        g++ -g  obj/MainMenu.o obj/Menu.o -o bin/jeu
    - bin/text: (du même type que bin/jeu)
    - bin/sdl: (du même type que bin/jeu)
    - bin/test: (du même type que bin/jeu)
    
    - obj/mainTest.o: src/core/mainTest.cpp obj/Personnage.o obj/Plateau.o obj/Jeu.o obj/Objet.o
        g++ -Wall -ggdb -I./extern/include -c src/core/mainTest.cpp -o obj/mainTest.o
    - obj/mainTxt.o: (du même type que obj/mainTest.o)
    - obj/mainSdl.o: (du même type que obj/mainTest.o)
    - obj/mainMenu.o: (du même type que obj/mainTest.o)

    - obj/JeuTxt.o: src/txt/JeuTxt.h src/txt/JeuTxt.cpp src/core/Jeu.h 
        g++ -Wall -ggdb -I./extern/include -c src/txt/JeuTxt.cpp -o obj/JeuTxt.o
    - obj/WinTxt.o: (du même type que obj/JeuTxt.o)
    - obj/JeuSdl.o: (du même type que obj/JeuTxt.o)

    - obj/Jeu.o:  src/core/Jeu.h src/core/Jeu.cpp src/core/Vect2.h src/core/Type.h  src/core/Personnage.h src/core/Plateau.h
        g++ -Wall -ggdb -I./extern/include -c src/core/Jeu.cpp  -o obj/Jeu.o
    - obj/Personnage.o: (du même type que obj/Jeu.o)
    - obj/Plateau.o: (du même type que obj/Jeu.o)
    - obj/Objet.o: (du même type que obj/Jeu.o)
    - obj/Vect2.o: (du même type que obj/Jeu.o)
    - obj/Menu.o: (du même type que obj/Jeu.o)
