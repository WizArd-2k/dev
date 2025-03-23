#ifndef LIVRE_H_
#define LIVRE_H_
#include <string>
#include "couverture.h"
#include "page.h"
using namespace std;

class Livre: public Couverture, public Page{
    public:
        Livre(string auteur, string titre, float prix, string devise);
        ~Livre(void);

        void afficher_livre(void);

    protected:
        string auteur;
        float prix;
        string devise;
};

#endif // LIVRE_H_