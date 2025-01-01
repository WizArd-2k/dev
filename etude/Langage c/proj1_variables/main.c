/*
 * main.c
 *
 *  Created on: 10 sept. 2024
 *      Author: bdefossez
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	int var1;
	char var2;
	float var3;
	double var4;
	var1 = 15984;
	var2 = 'B';
	var3 = 8942.356887;
	var4 = 13465793413414.4165478769;

	printf( "sizeof(int) == %d bytes\n", sizeof( int ) );
	printf( "sizeof(char) == %d bytes\n", sizeof( char ) );
	printf( "sizeof(float) == %d bytes\n", sizeof( float ) );
	printf( "sizeof(double) == %d bytes\n", sizeof( double ) );

	return 0;
}
