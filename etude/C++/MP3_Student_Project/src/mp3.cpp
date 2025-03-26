#include "mp3.h"
#include <iostream>
#include <limits> // Pour numeric_limits
#include <cstring>

MP3::MP3(std::string filename, access_t mode) : Fichiers(filename, mode) {
    memset(&tagID3V, 0, sizeof(ID3v1_1));
}

MP3::~MP3() {}

bool MP3::litMetadonnees() {
    if (!estOuvert() && !ouvrirFichier(READ_ONLY)) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier en lecture" << std::endl;
        return false;
    }

    if (!deplaceCurseurFichier(FROM_END, -128)) {
        std::cerr << "Erreur: Positionnement dans le fichier impossible" << std::endl;
        return false;
    }

    if (lireDansFichier(&tagID3V, sizeof(ID3v1_1)) != sizeof(ID3v1_1)) {
        std::cerr << "Erreur: Lecture des métadonnées échouée" << std::endl;
        return false;
    }

    if (strncmp(tagID3V.tag, "TAG", 3) != 0) {
        std::cerr << "Aucune balise ID3v1.1 trouvée." << std::endl;
        return false;
    }
    return true;
}

bool MP3::ecritMetadonnees() {
    if (!estOuvert() && !ouvrirFichier(READ_WRITE)) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier en écriture" << std::endl;
        return false;
    }

    // S'assurer que le fichier est assez grand
    if (!deplaceCurseurFichier(FROM_END, -128)) {
        // Si pas de tag existant, écrire à la fin
        if (!deplaceCurseurFichier(FROM_END, 0)) {
            std::cerr << "Erreur: Impossible de se positionner en fin de fichier" << std::endl;
            return false;
        }
    }

    // Écrire le tag
    strncpy(tagID3V.tag, "TAG", 3);
    if (ecrireDansFichier(&tagID3V, sizeof(ID3v1_1)) != sizeof(ID3v1_1)) {
        std::cerr << "Erreur: Écriture des métadonnées échouée" << std::endl;
        return false;
    }

    return true;
}

void MP3::afficherMetadonnees() {
    std::cout << "Titre : " << tagID3V.title << "\n"
              << "Artiste : " << tagID3V.artist << "\n"
              << "Album : " << tagID3V.album << "\n"
              << "Année : " << tagID3V.year << "\n"
              << "Commentaire : " << tagID3V.comment << "\n"
              << "Piste : " << static_cast<int>(tagID3V.track) << "\n"
              << "Genre : " << LISTE_GENRE_MUSICAL[static_cast<int>(tagID3V.genre)] << std::endl;
}

void MP3::modifierMetadonnees() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Nettoyage initial
    
    std::cout << "Entrez le nouveau titre : ";
    std::cin.getline(tagID3V.title, sizeof(tagID3V.title));
    
    std::cout << "Entrez le nouvel artiste : ";
    std::cin.getline(tagID3V.artist, sizeof(tagID3V.artist));
    
    std::cout << "Entrez le nouvel album : ";
    std::cin.getline(tagID3V.album, sizeof(tagID3V.album));
    
    std::cout << "Entrez l'année : ";
    std::cin.getline(tagID3V.year, sizeof(tagID3V.year));
    
    std::cout << "Entrez un commentaire : ";
    std::cin.getline(tagID3V.comment, sizeof(tagID3V.comment));
    
    // Lecture sécurisée du numéro de piste
    std::cout << "Entrez le numéro de la piste : ";
    int track;
    while (true) {
        if (std::cin >> track && track >= 0 && track <= 255) {
            tagID3V.track = static_cast<char>(track);
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Valeur invalide. Entrez un numéro entre 0 et 255 : ";
    }
    
    // Lecture sécurisée du genre
    std::cout << "Entrez le genre (0-79) : ";
    int genre;
    while (true) {
        if (std::cin >> genre && genre >= 0 && genre <= 79) {
            tagID3V.genre = static_cast<char>(genre);
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Valeur invalide. Entrez un numéro entre 0 et 79 : ";
    }
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Nettoyage final
}