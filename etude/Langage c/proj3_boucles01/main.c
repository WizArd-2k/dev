/*
 * main.c
 *
 *  Created on: 17 sept. 2024
 *      Author: bdefossez
 */

#include <stdio.h>

int main(){
	int n;
	printf("Nombre de départ : ");
	scanf("%d",&n);
	int i ;
	int d ;
	d = n+10;
	for (i=n; i<=d; i++){
		printf("i=%d -> i²=%d\n", i, i*i);
	}
	return 0;
}
