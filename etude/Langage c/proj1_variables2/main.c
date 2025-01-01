/*
 * main.c
 *
 *  Created on: 10 sept. 2024
 *      Author: bdefossez
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int i, j, k, l, m;
	float a, b, c;
	double p, q, r;

	printf("Partie 1\n");
	i = 5;
	j = 22;
	//k = i+j;
	j = i;
	printf("i=%d ; j=%d ; k=%d\n", i, j, k);

	printf("\n\nPartie 2\n");
	j = k/i;
	l = k%i;
	m = 3/2;
	printf("j vaut %d ; l égale %d; m à pour valeur %d\n", j, l, m);

	printf("\n\nPartie 3\n");
	p = M_PI;
	i = 10;
	j = i/3*3;
	k = i*3/3;
	printf("p=%f ; i=%d ; j=%d ; k=%d\n", p, i, j, k);

	printf("\n\nPartie 4\n");
	p = 3/2;
	q = 3/2.;
	r = 3./2;
	printf("p=%f ; q=%f ; r=%f\n", p, q, r);

	printf("\n\nPartie 5\n");
	p = M_PI;
	i = p/2;
	r = p/2;
	printf("p=%f ; i=%d ; r=%f\n" , p, i, r);

	printf("\n\nPartie 6\n");
	p = 3;
	q = sqrt(p);
	r = pow(3, 4);
	printf("p=%f ; q=%f ; r=%f\n", p, q, r);

	printf("\n\nPartie 7\n");
	p = 1.5234e+3;
	printf("p=%f ; p=%e ; p=%8.3f ; p=%08.2f\n", p, p, p, p);
	i = 34;
	printf("i=%d ; i=%x , i=%5d ; i=%08d\n", i, i, i, i);

	printf("\n\nPartie 8\n");
	i = 3;
	j = i | 0xff;
	k = j & 0x0f;
	printf("i=%d ; j=%d ; k=%d\n", i, j, k);

	printf("\n\nPartie 9\n");
	printf("x=%d ; y=%d ; %s%d ; %s%X\n",12,10,"x*y=",120,"12=",12);

	printf("\n\nPartie 10\n");
	printf("Bonjour\n");
	printf("%c correspond au caractère ASCII %d\n", 'B', 'B');
	printf("%c correspond au caractère ASCII %d\n", 'o', 'o');
	printf("%c correspond au caractère ASCII %d\n", 'n', 'n');
	printf("%c correspond au caractère ASCII %d\n", 'j', 'j');
	printf("%c correspond au caractère ASCII %d\n", 'o', 'o');
	printf("%c correspond au caractère ASCII %d\n", 'u', 'u');
	printf("%c correspond au caractère ASCII %d\n", 'r', 'r');

	printf("\n\nTranstypage\n");
	int varI = 513; //variable entière sur 32 bits signé
	char varC; //variable entière sur 8 bits signé
	float varF = 2.5; //variable utilisant la norme flottant IEEE 32 bits
	varC = varI; // conversion dégradante
	varI = varF; //ici, un warning signale <<possible loss of data>>
	printf("%d %d\n",varC,varI);//affiche 1 (513mod256) et 2(partie entière de 2.5)

	varI = 513;
	int varD = (char)varI; //conversion int-> char forcée
	printf("%d",varD); //affiche les deux octets de poids faible de varI

}
