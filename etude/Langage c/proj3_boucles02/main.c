 /*
 * main.c
 *
 *  Created on: 17 sept. 2024
 *      Author: bdefossez
 */

#include <stdio.h>

int main(){
	int i, sum;
	sum=0;
	printf("nombre de départ :");
	scanf("%d",&i);
	while(i>0) {
		printf("i=%d\n",i);
		sum=sum+i;
		i--;
	}
	printf("la somme des entiers est :%d",sum);
	return 0;
}
