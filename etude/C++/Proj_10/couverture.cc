#include <iostream>
#include <string>  
#include "couverture.h"
using namespace std;


Couverture::Couverture(string titre){
    Couverture::titre.reserve(256);
    Couverture::titre = titre;
    cout << "Classe Couverture construite" << endl;
}

Couverture::~Couverture(void){
    Couverture::titre.clear();
    cout << "Classe Couverture detruite" << endl;
}