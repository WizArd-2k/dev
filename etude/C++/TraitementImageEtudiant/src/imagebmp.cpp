/*
 * imagebmp.cpp
 *
 */

#include "imagebmp.h"

// constructeur de la classe
ImageBMP::ImageBMP(string nomFichier, access_t methode_acces):Fichiers(nomFichier,methode_acces)
{
	// Lecture des informations composant le fichier unique en lecture
	if(methode_acces == OPEN_IMG) {
		this->litEntete();
		this->litImage();
	}
}

// destructeur de la classe
ImageBMP::~ImageBMP()
{

}

// méthode de mise en niveau de gris de l'image (à compléter)
bool ImageBMP::niveauGris()
{
	unsigned char moyenne;
	unsigned char bleu, vert, rouge;
	unsigned char *ptrCopyTabImage;

	// récupération de l'adresse du début de l'image
	ptrCopyTabImage = ptrTabImage;

	// Ajouter les boucles pour calculer la moyenne des 3 couleurs



	// Fin d'ajout des boucles

	/*
		// Calcul et insertion des octets de bourrage pour avoir un multiple de 4 octets par ligne
		int octetParLigne = enteteImage.largeurImage * 3;
		if(octetParLigne%4 != 0 ){
			int nbreOctetAjouter = 4-(octetParLigne%4);
			cout << "Nombre d'octet à ajouter : " << nbreOctetAjouter << endl;
			ptrCopyTabImage = ptrCopyTabImage+nbreOctetAjouter;
		}
	*/
	return true;
}

// Méthode de lecture de l'entete dans le fichier (à compléter)
bool ImageBMP::litEntete() {
/*
	// compléter la condition pour placer le curseur de fichier au début du fichier (à compléter)
	if(                      ) {
		cout << "Problème de placement du curseur dans le fichier !" << endl;
		return false;
	}
	// compléter la condition pour lire le contenu de l'entête dans le fichier et la stocker dans la structure (à compléter)
	if(                                        ) != 0) {
		cout << "Signature = " << hex << enteteImage.signature << endl;
		cout << "Taille totale du fichier = " << dec << enteteImage.tailleTotaleFichier << " octets" << endl;
		cout << "Réservé = " << enteteImage.reserve << endl;
		cout << "Offset = " << hex << enteteImage.offset << " soit " << dec << enteteImage.offset << " octets" << endl;
		cout << "Taille de l'entête = " << dec << enteteImage.tailleEntete << " octets" << endl;
		cout << "Largeur de l'image = " << dec << enteteImage.largeurImage << " pixels" << endl;
		cout << "Hauteur de l'image = " << dec << enteteImage.hauteurImage << " pixels" << endl;
		cout << "Nombre de plan = " << dec << enteteImage.plan << endl;
		cout << "Profondeur de l'image = " << dec << enteteImage.profondeurImage << " bits" << endl;
		cout << "Méthode de compression = " << enteteImage.compress << endl;
		cout << "Taille de l'image = " << enteteImage.tailleImage << " octets" << endl;
		cout << "Résolution horizontale = " << enteteImage.resH << " pixels/m" << endl;
		cout << "Résolution verticale = " << enteteImage.resV << " pixels/m" << endl;
		cout << "Nombre de couleur = " << enteteImage.nbCouleur << endl;
		cout << "Nombre de couleur importante = " << enteteImage.important << endl;
		cout << "Début de l'entête lue correctement !" << endl;
	}
	else {
		cout << "Problème de lecture de début de l'entete !" << endl;
		return false;
	}

	// Stockage de la fin de l'entete dans un tableau de taille dynamique
	ptrFinEntete = new unsigned char[enteteImage.tailleImage];
	if(lireDansFichier(ptrFinEntete, enteteImage.offset - sizeof(structEnteteImgBmp)) != 0) {
		cout << "Lecture de la fin de l'entete réussie !" << endl;
		ptrEntete = &enteteImage;
	}
	else {
		cout << "Problème de lecture de la fin de l'entete !" << endl;
		return false;
	}
*/
	return true;
}


// Méthode de lecture des données de l'image (à compléter)
bool ImageBMP::litImage() {
/*
	// compléter la condition pour placer le curseur de fichier au début des données de l'image dans le fichier (à compléter)
	if(                            ) {
		cout << "Problème de placement du curseur dans le fichier !" << endl;
		return false;
	}
	ptrTabImage = new unsigned char[enteteImage.tailleImage];
	// compléter la condition pour lire le contenu des données de l'image dans le fichier (à compléter)
	if(                            ) != 0) {
		cout << "Lecture de l'image réussie !" << endl;
		return true;
	}
	else {
		cout << "Problème de lecture !" << endl;
		return false;
	}
*/
	return true;
}

void * ImageBMP::getEntete() {
	return ptrEntete;
}

unsigned char * ImageBMP::getImage() {
	return ptrTabImage;
}

uint32_t ImageBMP::getTailleImage() {
	cout << "Taille de l'image : " << enteteImage.tailleImage << endl;
	return enteteImage.tailleImage;
}

uint32_t ImageBMP::getTailleEntete() {
	cout << "Taille de l'entete totale : " << enteteImage.offset << endl;
	return enteteImage.offset;
}

void ImageBMP::setEntete(void *ptrTableau, int taille) {
	deplaceCurseurFichier(0);
	ecrireDansFichier(ptrTableau, taille);
}

void ImageBMP::setImage(unsigned char * ptrLocalTabImage, int tailleTab) {
	ecrireDansFichier(ptrLocalTabImage, tailleTab);
}
