#include <string>
#include <iostream>

using namespace std;

int u = 5;
int n = 0;

int main(){
    while (u >= 1.01 ){
        cout << "u = " << u << endl;
        cout << "n = " << n << endl;
        n = n+1;
        u = 3 - 10.0 / (u + 4); 
    }
}