#include "livre.h"

int main(void){
    Livre texte("Suzanne Collins", "Hunger Games (Les jeux de la faim)", 15.85, "EUR");

    texte.afficher_livre();

    return 0;
}