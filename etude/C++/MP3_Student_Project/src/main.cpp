/*
 * main.cpp
 *
 */
#include "mp3.h"
#include <iostream>

int main() {
    string nomFichier;
    cout << "Nom du fichier MP3 : ";
    getline(cin, nomFichier);

    MP3 fichierMP3(nomFichier, READ_WRITE);
    
    if (!fichierMP3.litMetadonnees()) {
        cerr << "Erreur lecture métadonnées" << endl;
        return 1;
    }
    
    fichierMP3.afficherMetadonnees();
    fichierMP3.modifierMetadonnees();
    
    if (!fichierMP3.ecritMetadonnees()) {
        cerr << "Erreur écriture métadonnées" << endl;
        return 1;
    }
    
    cout << "Métadonnées mises à jour !" << endl;
    return 0;
}