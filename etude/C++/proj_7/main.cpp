#include <iostream>

using namespace std;

class UnArgument {
    public:
        UnArgument(int j){ a = j;}
        int donne_a(void){ return a;}
        
    private:
        int a;
};

int main(void){
    UnArgument objet = 95;
    cout << objet.donne_a();
}