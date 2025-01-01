/*
 * main.c
 *
 *  Created on: 11 sept. 2024
 *      Author: bdefossez
 */
#include <stdio.h>
#include <stdlib.h>

int main() {

	int entier;
	printf("Saisir un entier:");
	scanf("%d", &entier);
	if ((entier%2)==0) {
		printf("entier pair");
	}
	else{
		printf("entier impair");
	}
	return 0;
}

