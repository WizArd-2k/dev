#include <stdio.h>
int main(){
char unePhrase[] = "Bonjour tout le monde !";
char *ptr;
char compteur = 0;
ptr = unePhrase;
printf("Affichage de la phrase :\n");
while(*ptr != '\0') {
printf("%c", *ptr);
ptr++;
}
return 0;
}