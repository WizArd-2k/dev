/*
 * main.c
 *
 *  Created on: 11 sept. 2024
 *      Author: bdefossez
 */
#include <stdio.h>
#include <stdlib.h>

int main() {

	int nbrEnfants;
	printf("Combien avez-vous d'enfants ? : ");
	scanf("%d",&nbrEnfants);
	if (nbrEnfants>=3) {
		printf("Vous avez droit à une prime!");
	}

	return 0;

}


