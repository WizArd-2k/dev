#include <stdio.h>

int main(){
    int tab[] = {1,2,3,4,5,6};
    int *ptr;
    ptr = tab;
    printf("Affichage du contenu du tableau : \n");
    int i;
    for (i = 0;i<7;i++){
        printf("Case[%d] = %d\n", i, *ptr);
        ptr++;
    }
    return 0;
}