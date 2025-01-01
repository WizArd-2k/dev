/*
 * main.c
 *
 *  Created on: 18 sept. 2024
 *      Author: bdefossez
 */

int main(){
	float tab[10]={20.9,21.3,21.2,22.1,22.4,21.6,23.7,23.3,23.0,22.8};

	for(int i = 0;i<10;i++){
		printf("tab[%d]=%f\n", i, tab[i]);
		if(tab[0]< tab[i])
			tab[0] = tab [i];
	}
	printf("le nombre le plus grand parmi ceux inscrit dans le tableau est : %.1f", tab[0] );
	return 0;
}
