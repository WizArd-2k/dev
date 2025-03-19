#include <iostream>

using namespace std;

class NombresMagiques {
    public:
        NombresMagiques(int a = 1, int b = 2, int c = 3){
            NombresMagiques::a = a;
            NombresMagiques::b = b;
            NombresMagiques::c = c;
        }
    void afficher_nombres(void){
        cout << a << ' ' << b << ' ' << c << endl;
    }
    private:
        int a, b, c;
};

int main(void){
    NombresMagiques un(1, 1, 1);
    NombresMagiques defauts;
    NombresMagiques autres(303, 202, 101);

    un.afficher_nombres();
    defauts.afficher_nombres();
    autres.afficher_nombres();
    
}