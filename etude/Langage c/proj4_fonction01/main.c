/*
 * main.c
 *
 *  Created on: 18 sept. 2024
 *      Author: bdefossez
 */
#include <stdio.h>

void puissances(int n) {
	int n3;
	n = n*n;
	n3= n*n;
	printf("Le carré de ce nombre est : %d\n",n);
	printf("Le cube de ce nombre est : %d\n",n3);
}

int main(){
	int n=2;
	puissances(n);
	printf("La valeur de n après l'appel à la fonction est : %d\n",n);
	return 0;
}

