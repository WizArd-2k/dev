#include <iostream>
using namespace std;
int main()
{
    int age = 0;
    char nom[30], prenom[30];
    float valeurFlottante;
    unsigned int valeur, un = 1;
    string message = "Hello";
    message += " World!";
    valeur = un << 1;

    cout << "Bonjour à tous !" << endl;
    cout << "Bienvenue en langage C++!" << endl;
    
    cout << message << endl;
    
    cout << "Quel age avez-vous et comment vous appelez-vous ?" << endl;
    cin >> age >> nom >> prenom;
    cout << "Ah ! vous etes : " << prenom << ' ' << nom << " et vous avez " << age << " ans." << endl;
    cout << "Votre age en hexadecimal : " << hex << age << endl;
    cout << "Votre age en octale : " << oct << age << endl;
    cout << "Entrer un nombre à virgule : ";
    cin >> valeurFlottante;
    cout << "Vous avez ecrit : " << valeurFlottante << endl;

    cout << "Valeur vaut : " << valeur << endl;
    cout << "Resultat du décalage à gauche de un : " << (un << 1) << endl;
    cout << "Resultat sans décalage à gauche de un : " << un << 1 << endl;
    return 0;
}
