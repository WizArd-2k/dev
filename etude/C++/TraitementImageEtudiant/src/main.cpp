/*
 * main.cpp
 *
 */

#include "fichiers.h"
#include "imagebmp.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

//Renaud main:
int main()
{
	ImageBMP imagebmp("oiseau.bmp",OPEN_IMG); // instanciation d'un nouvel objet image et appel au constructeur de la class ImageBMP

	imagebmp.sepia(0.88, 0.56, 0.16);

	ImageBMP newimagebmp("titi.bmp",CREATE_IMG);

	newimagebmp.setEntete(imagebmp.getEntete(),imagebmp.getTailleEntete());
	newimagebmp.setImage(imagebmp.getImage(), imagebmp.getTailleImage());

	newimagebmp.fermerFichier(); //fermeture du fichier
	imagebmp.fermerFichier(); //fermeture du fichier

	return 0;
}
