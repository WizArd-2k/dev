#include <iostream>

using namespace std;

class Mere {
    int m_i;
    public:
        Mere(int);
        ~Mere(void);
    };

Mere::Mere(int i){
    m_i = i;
    cout << "Exécution du constructeur de la classe mère. m_i = " << m_i << endl;
    return;
}

Mere::~Mere(void){
    cout << "Exécution du destructeur de la classe mère.\n";
    return;
}

class Fille : public Mere {
    public:
        Fille(void);
        ~Fille(void);
    };

Fille::Fille(void) : Mere(2){
    cout << "Exécution du constructeur de la classe fille.\n";
    return;
}

Fille::~Fille(void){
    cout << "Exécution du destructeur de la classe fille.\n";
    return;
}

int main(void){
    Fille objFille1;
}