/*
 * imagebmp.h
 *
 */
#ifndef IMAGEBMP_H_
#define IMAGEBMP_H_

#pragma pack(2) // alignement mémoire sur 2 octets nécessaire pour la structure
#include "fichiers.h"
#include <cmath>

// Structure de l'entête à compléter
typedef struct {


} structEnteteImgBmp;
// Fin de la structure de l'entête

class ImageBMP : public Fichiers
{
    private:
		structEnteteImgBmp enteteImage;
		unsigned char *ptrFinEntete;
		void *ptrEntete;
		unsigned char *ptrTabImage;

    public:
        ImageBMP(string,access_t);
        virtual ~ImageBMP();
        bool litEntete();
        bool litImage();
        bool niveauGris();
        uint32_t getTailleImage();
        uint32_t getTailleEntete();
        void *getEntete();
        unsigned char *getImage();
        void setImage(unsigned char * ptrLocalTabImage, int tailleTab);
        void setEntete(void *ptrTableau, int taille);
};

#endif /* IMAGEBMP_H_ */
