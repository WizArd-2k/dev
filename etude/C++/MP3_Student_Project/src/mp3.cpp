/*
 * mp3.cpp
 *
 */
#include "mp3.h"
#include <iostream>
#include <fstream>
#include <cstring>

bool MP3::litMetadonnees() {
    if(!deplaceCurseurFichier(FROM_END, -128)) {
        cerr << "Erreur de positionnement dans le fichier" << endl;
        return false;
    }
    
    return lireDansFichier(&tagID3V, sizeof(ID3v1_1)) == sizeof(ID3v1_1)
           && strncmp(tagID3V.tag, "TAG", 3) == 0;
}

bool MP3::ecritMetadonnees() {
    if(!deplaceCurseurFichier(FROM_END, -128)) {
        cerr << "Erreur de positionnement dans le fichier" << endl;
        return false;
    }
    
    return ecrireDansFichier(&tagID3V, sizeof(ID3v1_1)) == sizeof(ID3v1_1);
}

void MP3::afficherMetadonnees() {
    cout << "Titre : " << tagID3V.title << "\n"
         << "Artiste : " << tagID3V.artist << "\n"
         << "Album : " << tagID3V.album << "\n"
         << "Année : " << tagID3V.year << "\n"
         << "Commentaire : " << tagID3V.comment << "\n"
         << "Piste : " << static_cast<int>(tagID3V.track) << "\n"
         << "Genre : " << LISTE_GENRE_MUSICAL[tagID3V.genre] << endl;
}

void MP3::modifierMetadonnees() {
    cout << "Nouveau titre : ";
    cin.getline(tagID3V.title, 30);
    /* ... autres champs ... */
}