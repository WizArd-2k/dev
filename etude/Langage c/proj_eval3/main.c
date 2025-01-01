#include <stdio.h>

int main() {
    int sapin;
    int etage;
    int espace;
    int etoile;
    printf("nombre d'étage du sapin :");
    scanf("%d",&sapin);
    for ( etage = 1;etage <= sapin;etage++){
        for (espace = 0 ; espace < sapin - etage ; espace ++){
            printf(" ");
        }
        for (etoile = 0 ; etoile < 2* etage -1; etoile++ ){
            printf("*");
        }
        printf("\n");
        
    }
}