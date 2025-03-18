#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    ofstream ofs;
    ifstream ifs;

    string lectFile;
    char caractere;

    ofs.open("text.txt", ios::out | ios::trunc);
    ofs << "Une premiere ligne dans le fichier,\n" << endl;
    ofs << "et une autre ligne, la seconde." << endl;
    ofs.close();

    ifs.open("text.txt", ios::in);
    ifs.get(caractere);
    getline(ifs, lectFile);
    cout << "1er caractere contenu dans le fichier : " << caractere << endl;
    cout << "Reste de la 1ere ligne du fichier : "<< lectFile << endl;
    ifs.close();

    return 0;
}