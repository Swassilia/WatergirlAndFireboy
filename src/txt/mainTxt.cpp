#include "WinTxt.h"
#include "JeuTxt.h"
#include "../core/Jeu.h"

int main(int argc, char** argv){
    termClear();
    Jeu jeu;
    txtBoucle(jeu);
    termClear();
    return 0;
}