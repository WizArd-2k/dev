#include "mp3.h"
#include <iostream>
#include <locale>

int main() {
    // Configurer l'encodage pour les accents
    setlocale(LC_ALL, "");

    std::string nomFichier;
    std::cout << "Entrez le nom du fichier MP3: ";
    std::getline(std::cin, nomFichier);

    // Vérifier l'extension .mp3
    if(nomFichier.size() < 4 || nomFichier.substr(nomFichier.size() - 4) != ".mp3") {
        nomFichier += ".mp3";
    }

    MP3 fichierMP3(nomFichier, READ_WRITE);

    if(!fichierMP3.litMetadonnees()) {
        std::cerr << "\nLe fichier ne contient pas de tags ID3v1.1 valides." 
                  << "\nVoulez-vous en creer de nouveaux? (o/n) ";
        
        char choix;
        std::cin >> choix;
        std::cin.ignore();
        
        if(choix != 'o' && choix != 'O') {
            return 0;
        }
    } else {
        fichierMP3.afficherMetadonnees();
    }

    std::cout << "\nVoulez-vous modifier les metadonnees? (o/n) ";
    char modifier;
    std::cin >> modifier;
    std::cin.ignore();
    
    if(modifier == 'o' || modifier == 'O') {
        fichierMP3.modifierMetadonnees();
        
        if(fichierMP3.ecritMetadonnees()) {
            std::cout << "\nMetadonnees mises a jour avec succes!" << std::endl;
        } else {
            std::cerr << "\nErreur lors de l'ecriture des metadonnees!" << std::endl;
        }
    }

    return 0;
}