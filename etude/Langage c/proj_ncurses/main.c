/*
 * main.c
 *
 *  Created on: 18 sept. 2024
 *      Author: bdefossez
 */

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
float x=0,y=0;
void test(){
	do{
		clear();
		move(x,y);
		printw("0");
		x= x+1;
		refresh();
		usleep(200000);
	}while(x<LINES && y<COLS);
	do{
		clear();
		move(x,y);
		printw("0");
		x = x-1;
		refresh();
		usleep(200000);
	}while(x<=0 && y<COLS);
}

int main(){
	initscr();
	cbreak();
	noecho();
	curs_set(0); // 0 curseur invisible | 1 visible | 2 très visible
	//printw("%d",LINES);
	//printw(" %d",COLS);
	int compteur = 0;
	do{
		test();
		compteur = compteur+1;
	}while (compteur == 10);


	return 0;
}
