#include <iostream>
#include "Personnage.h"
#include "Obstacle.h"
#include "Bonus.h"
#include "Jeu.h"
using namespace std;



int main(){
    Personnage p;
    Obstacle ob;
    Bonus b;
    Jeu jeu;
    cout<<b.getType()<<" "<<ob.getType()<<" "<<p.getPos().x<<endl;
    jeu.testRegression_Jeu();
    cout<<"test jeu"<<endl;

    return 0;
}