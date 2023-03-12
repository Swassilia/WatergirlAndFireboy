#include "JeumodeText.h"
#include <iostream>


using namespace std;

JeuTxt :: JeuTxt()
{

}
JeuTxt :: ~JeuTxt()
{
    
}

void AfficheTxt()
{
    cout << dimx << " " << dimy << endl;
    for(unsigned int y=0; y<dimy; ++y) {
        for(unsigned int x=0; x<dimx; ++x) {
            Pixel& pix = getPix(x,y);
            cout << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
        cout << endl;
    }
}
}
