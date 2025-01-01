#include <stdio.h>

int main()
{
    int varA = 10, varB = 20, varC;
    int *ptrA, *ptrB, *ptrC;
    ptrA = &varA;
    ptrB = &varB;
    ptrC = &varC;
    printf("Contenu avant permutation : varA = %d ; varB = %d\n", varA, varB);

    *ptrC = *ptrA;
    *ptrA = *ptrB;
    *ptrB = *ptrC;
    printf("Contenu après permutation : varA = %d ; varB = %d\n", varA, varB);
    return 0;
}