/*
 * main.c
 *
 *  Created on: 17 sept. 2024
 *      Author: bdefossez
 */
#include <stdio.h>

int main(){
	int i;
	i = 0;
	do{
		printf("i=%d\n",i);
		i++;
	} while(i<=10);
	do {
		printf("Entrer un nombre entier impair : ");
		scanf("%d",&i);
	}while((i%2)==0);
	return 0;

}

