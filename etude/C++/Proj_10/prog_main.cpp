#include "livre.h"

int main(void){
    Livre *Livre1 = new Livre("Suzanne Collins", "Hunger Games (Les jeux de la faim)", 15.85, "EUR");
    Livre1->afficher_livre();

    Livre *Livre2 = new Livre("Franck Herbert", "Dune", 10.95, "EUR");
    Livre2->afficher_livre();

    delete Livre1;

    delete Livre2;
    
    return 0;
}


//Livre texte("Suzanne Collins", "Hunger Games (Les jeux de la faim)", 15.85, "EUR");

//texte.afficher_livre();
