#include <iostream>
#include "Personnage.h"
#include "Plateau.h"
#include "Jeu.h"
using namespace std;


/**
 * @brief crée une instance de la classe Jeu appelée jeu 
 * @brief elle appelle la méthode testRegressionJeu() de l'objet jeu, qui est utilisée pour tester certaines fonctionnalités du jeu.
*/
int main(){
    Jeu jeu;
    jeu.testRegressionJeu();
    cout<<"test jeu"<<endl;

    return 0;
}