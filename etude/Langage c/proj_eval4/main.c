#include <stdio.h>

char carNonChiffre[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char carChiffre[26]={'N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M'};

int main(){
    char Nonchiffre[] = "CE PROBLEME EST SIMPLE";
    int i;

    printf("Message original : %s\n", Nonchiffre);

    for(i = 0; Nonchiffre[i]; i++){
        if(Nonchiffre[i] >= 'A' && Nonchiffre[i] <= 'Z'){ // Vérification si le caractère est une lettre majuscule
            int indice = Nonchiffre[i] - 'A';
            Nonchiffre[i] = carChiffre[indice];
        }
    }

    printf("Message chiffré : %s\n", Nonchiffre);
    char c[] ="";
    scanf("%s",&c);
        for(i = 0; c ;  i++){
            if(c[i] >= 'A' && c[i]<= 'Z'){ // Vérification si le caractère est une lettre majuscule
            int indice = c + 'A';
            c[i] = carChiffre[indice];
            }
        }
    printf("%s\n",c);
    return 0;
}