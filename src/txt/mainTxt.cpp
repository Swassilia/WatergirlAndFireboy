#include <iostream>
#include "WinTxt.h"
#include "JeuTxt.h"
#include "../core/Jeu.h"
#include <unistd.h>

int main(int argc, char** argv){
    termClear();
    Jeu jeu;
    MontxtBoucle(jeu);

    return 0;
}