/*
 * fichiers.h
 *
 */

#ifndef FICHIERS_H_
#define FICHIERS_H_

#include <string>
#include <iostream>

enum access_t {OPEN_IMG,CREATE_IMG};
enum debutPosLecture {POS_DEBUT, POS_FIN};

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
        bool deplaceCurseurFichier(debutPosLecture, unsigned long int);
        string getChemin();
};


#endif /* FICHIERS_H_ */
