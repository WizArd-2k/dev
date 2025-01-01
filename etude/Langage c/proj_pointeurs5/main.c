#include <stdio.h>
int main(){
    char unePhrase[] ="Bonjour tout le monde!";
    char *ptr;
    int compteur=0;
    ptr=unePhrase;
    printf("Affichage de la phrase :\n");
    while(*ptr!='\0'){
        printf("%c",*ptr);
        ptr++;
    }
    printf("\n\nRecherche  du nombre de 'o':\n");
    ptr = unePhrase;
    while (*ptr!='\0'){
        if (*ptr == 'o') {
            compteur+=1;
         }
        ptr++;
    }
    printf("\n il y a %d lettres o\n",compteur);
    
    ptr =  unePhrase;
    while (*ptr != '\0')
    {
        if (*ptr == 'o'){
            *ptr = 'O';
        }
        printf("%c",*ptr);
        ptr++;   
    }
    
    
    return 0;
}