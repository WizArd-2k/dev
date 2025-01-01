/*
 * main.c
 *
 *  Created on: 18 sept. 2024
 *      Author: bdefossez
 */
#include <stdio.h>
int main(){
	char chaine[]="Bonjour tout le monde !";
	int i=0;
	for(i;i<21;i++){
		printf("chaine[%d]=%c\n", i, chaine[i]);

		if(chaine[i]== 'm'){
			int position = i;
			printf("La position des m est :%d\n", position);
		}
	}
	return 0;
}

