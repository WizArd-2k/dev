/*
 * mp3.cpp
 *
 */
#include <iostream>
#include <vector>
#include "mp3.h"

// constructeur de la classe
MP3::MP3(string nomFichier, access_t methode_acces):Fichiers(nomFichier,methode_acces) {
	// Lecture des informations composant le fichier unique en lecture
	if(methode_acces == OPEN_IMG) {
		this->litMetadonnees();
	}
}

// destructeur de la classe
MP3::~MP3() {

}

// A FAIRE : Méthode de lecture de l'entete dans le fichier
bool MP3::litMetadonnees() {

	return true;
}

// A FAIRE : Méthode d'écriture de l'entete dans le fichier
bool MP3::ecritMetadonnees() {

	return true;
}


