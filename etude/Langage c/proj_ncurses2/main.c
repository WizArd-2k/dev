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
#include <sys/random.h>
#include <time.h>
#include <math.h>
float x=0,y=0;
int angle;
void test(){//boucle qui déplace 0
	do{
		clear();
		move(x,y);
		printw("0");
		x= x+1;
		y= y+1;
		refresh();
		usleep(25000);
		srandom(time(NULL));
			angle = random()%360;
			angle = angle/45;
		if(y>=LINES-1){
			angle=(random()%3)*45+45;
		}
		if(y<=0){
			angle=((random()%3)*45+315)%360;
			}
		if(x>=COLS-1){
			angle=((random()%3)*45+90)%360;
		}
		if(x<=0){
			angle=((random()%3)*45+225)%360;
		}

	}while(1);

}

int main(){
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	test();
	return 0;
}
