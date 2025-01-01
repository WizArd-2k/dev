/*
 * main.c
 *
 *  Created on: 9 oct. 2024
 *      Author: bdefossez
 */


#include <stdio.h>

int main(){
	int varA=10, varB=20;
	int *ptr;
	ptr = &varA;
	printf("varA: Contenu=%d ; Adresse=%x\n",varA, &varA);
	printf("varB: Contenu=%d ; Adresse=%x\n",varB, &varB);
	printf("ptr: Contenu pointé=%d ; Contenu=%d ; Adresse=%x\n\n",*ptr, ptr, &ptr);
	ptr = &varB;
	printf("varA: Contenu=%d ; Adresse=%x\n",varA, &varA);
	printf("varB: Contenu=%d ; Adresse=%x\n",varB, &varB);
	printf("ptr: Contenu pointé=%d ; Contenu=%d ; Adresse=%x\n\n",*ptr, ptr, &ptr);
	*ptr = *ptr + 10;
	printf("varA: Contenu=%d ; Adresse=%x\n",varA, &varA);
	printf("varB: Contenu=%d ; Adresse=%x\n",varB, &varB);
	printf("ptr: Contenu pointé=%d ; Contenu=%d ; Adresse=%x\n\n",*ptr, ptr, &ptr);
	return 0;
}
