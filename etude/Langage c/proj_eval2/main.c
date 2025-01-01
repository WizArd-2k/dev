#include <stdio.h>
int donnees[]={5, 26, -9, 1, 83, 45698, 349, -73, -537, 169, -47, 18, 36, -97, -75, -43, 580, -52, 655, -59, -30, 76, 1236, -8, 23};
int main(){
    int x;
    x = 0;

    //while ( x <25){
    //   donnees[x];
    //   //printf("%d\n", donnees[x]);
    //   if (donnees[x] < 0){
    //    printf("%d\n", donnees[x]);
    //   }
    //   x ++;
    //}


    for (x = 0 ; x<25 ; x++ )
        {
            if  (donnees[x] < 0){
                if (donnees[x] < x -1 ){
                printf("%d\n",donnees[x]);
              }
            }
            
        }
}