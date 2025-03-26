/*
 * fichiers.cpp
 *
 */

 #include "fichiers.h"

 Fichiers::Fichiers(string nom, access_t mode_acces)
 {
	 cheminFichier = nom;
 
	 switch(mode_acces) {
		 case READ_ONLY:
			 if(!ouvrirFichier())
				 cerr << "Erreur d'ouverture en lecture : " << cheminFichier << endl;
			 break;
		 case READ_WRITE:
			 if(!ouvrirFichier())
				 cerr << "Erreur d'ouverture en lecture/écriture : " << cheminFichier << endl;
			 break;
		 case CREATE_NEW:
			 if(!creerFichier())
				 cerr << "Erreur de création du fichier : " << cheminFichier << endl;
			 break;
	 }
 }
 
 Fichiers::~Fichiers()
 {
	 fermerFichier();
 }
 
 bool Fichiers::creerFichier()
 {
	 ptrFile = fopen(cheminFichier.c_str(), "wb+");
	 return ptrFile != NULL;
 }
 
 bool Fichiers::ouvrirFichier()
 {
	 ptrFile = fopen(cheminFichier.c_str(), "rb+");
	 return ptrFile != NULL;
 }
 
 bool Fichiers::fermerFichier()
 {
	 if(ptrFile == NULL) return false;
	 int result = fclose(ptrFile);
	 ptrFile = NULL;
	 return result == 0;
 }
 
 int Fichiers::lireDansFichier(void *buffer, int tailleBuff)
 {
	 return fread(buffer, 1, tailleBuff, ptrFile);
 }
 
 int Fichiers::ecrireDansFichier(void *buffer, int tailleBuff)
 {
	 return fwrite(buffer, 1, tailleBuff, ptrFile);
 }
 
 bool Fichiers::deplaceCurseurFichier(seek_position position, long decalage)
 {
	 int origin;
	 switch(position) {
		 case FROM_START: origin = SEEK_SET; break;
		 case FROM_END:   origin = SEEK_END; break;
		 default:        return false;
	 }
	 return fseek(ptrFile, decalage, origin) == 0;
 }
 
 string Fichiers::getChemin()
 {
	 return cheminFichier;
 }