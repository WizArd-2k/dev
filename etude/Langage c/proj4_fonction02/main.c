/*
 * main.c
 *
 *  Created on: 18 sept. 2024
 *      Author: bdefossez
 */
#include <stdio.h>

int appels = 0;

void fonction(){
	appels++;
}

int main(){
	fonction();
	fonction();
	printf("Ce programme a réalisé %d appel(s) de fonction\n", appels);
	return 0;
}

