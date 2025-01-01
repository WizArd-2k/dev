#include <stdio.h>
void changer_globales(void);
void changer_par_valeur(int, int);
void changer_par_adresse(int *, int *);
int varV = 30, varW = 40; // Variables globales
int main()
{
    int varX = 10, varY = 20; // Variables locales
    printf("Permutation des variables globales sans passage :\n");
    printf("Valeur avant permutation varV = %d ; varW =%d\n", varV, varW);
    changer_globales();
    printf("Valeur après permutation varV = %d ; varW =%d\n\n", varV, varW);
    printf("Permutation des variables locales avec passage par valeur :\n");
    printf("Valeur avant permutation varX = %d ; varY =%d\n", varX, varY);
    changer_par_valeur(varX, varY);
    printf("Valeur après permutation varX = %d ; varY =%d\n\n", varX, varY);
    printf("Permutation des variables locales avec passage par adresse :\n");
    printf("Valeur avant permutation varX = %d ; varY =%d\n", varX, varY);
    changer_par_adresse(&varX, &varY);
    printf("Valeur après permutation varX = %d ; varY =%d\n\n", varX, varY);
    return 0;
}
void changer_globales()
{
    int varC;
    varC = varV;
    varV = varW;
    varW = varC;
}
void changer_par_valeur(int varA, int varB)
{
    int varC;
    varC = varA;
    varA = varB;
    varB = varC;
}
void changer_par_adresse(int *varA, int *varB)
{
    int varC;
    varC = *varA;
    *varA = *varB;
    *varB = varC;
}