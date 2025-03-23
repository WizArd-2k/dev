#include <iostream>
#include <string>  
#include "livre.h"

using namespace std;

Livre::Livre(string auteur, string titre, float prix, string devise): Couverture(titre), Page(60), auteur(auteur), prix(prix), devise(devise){
    Livre::auteur.reserve(256);
    Livre::devise.reserve(4);
    Livre::auteur = auteur;
    Livre::titre = titre;
    Livre::prix = prix;
    Livre::devise = devise;
    cout << "Classe Livre construite" << endl;
};

Livre::~Livre(void){
    Livre::auteur.clear();
    Livre::devise.clear();
    cout << "Classe Livre detruite" << endl;
}

void Livre::afficher_livre(void){
    cout << titre << endl;
    cout << auteur << "\t\t" << prix << " " << devise << endl;
}