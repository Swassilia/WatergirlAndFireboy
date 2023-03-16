#include <iostream>
#include "WinTxt.h"
#include "JeuTxt.h"
#include "../core/Jeu.h"
#include <unistd.h>

int main(int argc, char** argv){
    termClear();
    //toto();
    Jeu jeu;
    MontxtBoucle(jeu);
    termClear();
/*
    
    termClear();
    WinTXT win (40, 40);
    win.print(5, 5, "toto");
    win.draw();
    sleep(1);
    termClear();
*/
    return 0;
}