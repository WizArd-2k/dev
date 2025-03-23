#include <iostream>
#include <string>  
#include "page.h"
using namespace std;

Page::Page(int lignes = 55){
    cout << "Classe Page construite" << endl;
    Page::lignes = lignes;
}

Page::~Page(void){
    cout << "Classe Page detruite" << endl;
}