/*
 * main.cpp
 *
 *  Traitement des informations textuelles d'un fichier mp3
 *
 */

#include "fichiers.h"
#include "mp3.h"

using namespace std;

int main()
{
	// A FAIRE : instancier un nouvel objet MP3 et renseigner le nom du fichier à ouvrir
	MP3 MP3File;
	MP3File::Title = "This_Is_The_Day.mp3";
	// A FAIRE : appel de la méthode pour modifier le tag du fichier mp3
	MP3File.ecritMetadonnees();
	//A FAIRE : fermeture du fichier

	return 0;
}


