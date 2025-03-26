#ifndef FICHIERS_H_
#define FICHIERS_H_

#include <string>
#include <iostream>

enum access_t {
    READ_ONLY,
    READ_WRITE,
    CREATE_NEW
};

enum seek_position {
    FROM_START,
    FROM_END
};

class Fichiers {
private:
    std::string cheminFichier;
    FILE* ptrFile;

public:
    Fichiers(std::string nom, access_t mode_acces);
    virtual ~Fichiers();
    bool creerFichier();
    bool ouvrirFichier(access_t mode);
    bool fermerFichier();
    size_t ecrireDansFichier(void* buffer, size_t taille);
    size_t lireDansFichier(void* buffer, size_t taille);
    bool deplaceCurseurFichier(seek_position position, long decalage);
    std::string getChemin() const;
    bool estOuvert() const;
};

#endif /* FICHIERS_H_ */