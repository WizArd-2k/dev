#include <iostream>

using namespace std;

class Simple {
    public:
        Simple(int);
    private:
        int qui_est_ce;
    } objt1_global(1), objt2_global(2);

    Simple::Simple(int num){
        cout << "Initialisation " << num << endl;
        qui_est_ce = num;

  };

int main(void){
    Simple objt3_local(3);
    cout << "Ceci n'est pas la première ligne affichée" << endl;
    Simple objt4_local(4);
}