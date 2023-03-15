#include <iostream>
#include "Personnage.h"
#include "Obstacle.h"
#include "Bonus.h"
using namespace std;



int main(){
    Personnage p;
    Obstacle ob;
    Bonus b;
    cout<<b.getType()<<" "<<ob.getType()<<" "<<p.getPos().x<<endl;

    return 0;
}