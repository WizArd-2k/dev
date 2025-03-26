/*
 * fichiers.h
 *
 */

 #ifndef FICHIERS_H_
 #define FICHIERS_H_
 
 #include <string>
 #include <iostream>
 
 enum access_t {
     READ_ONLY,     // Ouverture en lecture seule
     READ_WRITE,    // Ouverture en lecture/écriture
     CREATE_NEW     // Création d'un nouveau fichier
 };
 
 enum seek_position {
     FROM_START,
     FROM_END
 };
 
 using namespace std;
 
 class Fichiers
 {
     private:
         string cheminFichier;
         FILE *ptrFile;
 
     public:
         Fichiers(string, access_t);
         virtual ~Fichiers();
         bool creerFichier();
         bool ouvrirFichier();
         bool fermerFichier();
         int ecrireDansFichier(void *, int);
         int lireDansFichier(void *, int);
         bool deplaceCurseurFichier(seek_position, long decalage);
         string getChemin();
 };
 
 #endif /* FICHIERS_H_ */