#include <iostream>


using namespace std;


class Chiffres {
   public:
       Chiffres(void);
       void Afficher_Chiffres(void);
   private:
       int a;
       int b;
       int c;
};


Chiffres::Chiffres(void) : a(1), b(2), c(3) {};


void Chiffres::Afficher_Chiffres(void) {
   cout << "a contient = " << a << endl;
   cout << "b contient = " << b << endl;
   cout << "c contient = " << c << endl;
}


int main() {
   Chiffres Valeur;
   Valeur.Afficher_Chiffres();
}

