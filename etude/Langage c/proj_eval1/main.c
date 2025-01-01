#include <stdio.h>

int main(){
    int n;
    printf("n:");
    scanf("%d",&n);
    int i = 0;
    int somme;
    somme = 0;
    while(i < n){
         i++;
        somme= somme + i; 
    }
    printf("somme : %d\n",somme);
}