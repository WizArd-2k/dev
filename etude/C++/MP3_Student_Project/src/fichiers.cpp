#include "fichiers.h"
#include <cstdio>
#include <cerrno>
#include <cstring>

Fichiers::Fichiers(std::string nom, access_t mode_acces) 
    : cheminFichier(nom), ptrFile(nullptr) {
    switch(mode_acces) {
        case READ_ONLY:
            ptrFile = fopen(cheminFichier.c_str(), "rb");
            break;
        case READ_WRITE:
            ptrFile = fopen(cheminFichier.c_str(), "rb+");
            break;
        case CREATE_NEW:
            ptrFile = fopen(cheminFichier.c_str(), "wb+");
            break;
    }

    if(!ptrFile) {
        std::cerr << "Erreur (" << errno << "): " << strerror(errno) 
                  << " - Fichier: " << cheminFichier << std::endl;
    }
}

Fichiers::~Fichiers() {
    fermerFichier();
}

bool Fichiers::creerFichier() {
    if(ptrFile) fermerFichier();
    ptrFile = fopen(cheminFichier.c_str(), "wb+");
    return ptrFile != nullptr;
}

bool Fichiers::ouvrirFichier(access_t mode) {
    if(ptrFile) fermerFichier();
    switch(mode) {
        case READ_ONLY: ptrFile = fopen(cheminFichier.c_str(), "rb"); break;
        case READ_WRITE: ptrFile = fopen(cheminFichier.c_str(), "rb+"); break;
        default: return false;
    }
    return ptrFile != nullptr;
}

bool Fichiers::fermerFichier() {
    if(!ptrFile) return true;
    int result = fclose(ptrFile);
    ptrFile = nullptr;
    return result == 0;
}

size_t Fichiers::ecrireDansFichier(void* buffer, size_t taille) {
    if(!ptrFile) return 0;
    return fwrite(buffer, 1, taille, ptrFile);
}

size_t Fichiers::lireDansFichier(void* buffer, size_t taille) {
    if(!ptrFile) return 0;
    return fread(buffer, 1, taille, ptrFile);
}

bool Fichiers::deplaceCurseurFichier(seek_position position, long decalage) {
    if(!ptrFile) return false;
    int origin = (position == FROM_START) ? SEEK_SET : SEEK_END;
    return fseek(ptrFile, decalage, origin) == 0;
}

std::string Fichiers::getChemin() const {
    return cheminFichier;
}

bool Fichiers::estOuvert() const {
    return ptrFile != nullptr;
}