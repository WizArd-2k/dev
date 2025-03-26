/*
 * fichiers.cpp
 *
 */

#include "fichiers.h"

// constructeur de la classe
Fichiers::Fichiers(string nom, access_t methode_acces)
{
	cheminFichier = nom;

	if(methode_acces==OPEN_IMG)
    {
		if(!ouvrirFichier())
			cerr << "Erreur d'ouverture du fichier : " << cheminFichier << endl;
		else
			cout << "Ouverture du fichier : " << cheminFichier << endl;
    }
	if(methode_acces==CREATE_IMG)
    {
        if(!creerFichier())
			cerr << "Erreur de création du fichier : " << cheminFichier << endl;
		else
			cout << "Création du fichier : " << cheminFichier << " réussie." << endl;
    }

}

// destructeur de la classe
Fichiers::~Fichiers()
{
	fermerFichier();
}

// méthode d'ouverture du fichier en ecriture, le fichier est vidé
bool Fichiers::creerFichier()
{
	this->ptrFile = fopen (this->cheminFichier.c_str(),"w");
	if(this->ptrFile == NULL)
		return false;
	return true;
}

// méthode d'ouverture du fichier en lecture
bool Fichiers::ouvrirFichier()
{
	this->ptrFile = fopen (this->cheminFichier.c_str(),"r+");
	if(this->ptrFile == NULL)
		return false;
	return true;
}

// méthode de fermeture du fichier
bool Fichiers::fermerFichier()
{
	if(this->ptrFile == NULL)
		return false;
	if(fclose(this->ptrFile)!=0)
		return false;
	this->ptrFile = NULL;
	return true;
}

// méthode pour lire dans le fichier
int Fichiers::lireDansFichier(void *buffer, int tailleBuff)
{
	return fread(buffer, 1, tailleBuff, ptrFile);
}

// méthode pour écrire dans le fichier
int Fichiers::ecrireDansFichier(void *buffer, int tailleBuff)
{
	return fwrite(buffer, 1, tailleBuff, ptrFile);
}

// méthode pour déplacer le curseur à l'emplacement précis dans le fichier depuis le début
bool Fichiers::deplaceCurseurFichier(debutPosLecture position, unsigned long int decalage)
{
	if(position == POS_DEBUT) {
		if(fseek(ptrFile, decalage, SEEK_SET) != 0)
			return false;
	}
	else if(position == POS_FIN){
		if(fseek(ptrFile, -decalage, SEEK_END) != 0)
			return false;
	}
	else
		return false;
	return true;
}

// méthode pour donner le chemin du fichier dans l'arborescence
string Fichiers::getChemin()
{
	return this->cheminFichier;
}

