/*
 * main.c
 *
 *  Created on: 17 sept. 2024
 *      Author: bdefossez
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	int note;
	char mention[8];
	printf("Saisir une note : ");
	scanf("%d",&note);
//	switch (note / 2) {
//		case 10 :
//		case 9 :
//		case 8 :
//			mention = "TB";
//			break;
//		case 7 :
//			mention = "B";
//			break;
//		case 6:
//			mention = "AB";
//			break;
//		case 5:
//			mention = "P";
//			break;
//		default :
//			mention = "AJOURNE";
//	}
	if (note >=0){
		if (note >=9){

		}
		else if (note == 8){
			printf("mention = TB");
		}
		else if (note == 7){
			printf("mention = B");
		}
		else if (note == 6){
			printf("mention = AB");
		}
		else if (note == 5){
			printf("mention = P");
		}
	}
	return 0;
}
