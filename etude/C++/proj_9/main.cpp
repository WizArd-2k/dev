#include <iostream>
#include <string>

using namespace std;

class Couverture {
    public:
        Couverture(string titre){
            Couverture::titre.reserve(256);
            Couverture::titre = titre;
            cout << "Classe Couverture construite" << endl;
        }
        ~Couverture(void){
            Couverture::titre.clear();
            cout << "Classe Couverture détruite" << endl;
        }
        protected:
            string titre;
};

class Page {
    public:
        Page(int lignes = 55) {
            cout << "Classe Page construite" << endl;
            Page::lignes = lignes;
        }
        ~Page(void){
            cout << "Classe Page détruite" << endl;
        }
    protected:
        int lignes;
};

class Livre: public Couverture, public Page {
    public:
        Livre(string auteur, string titre, float prix, string devise): Couverture(titre), Page(60){
            Livre::auteur.reserve(256);
            Livre::devise.reserve(4);
            Livre::auteur = auteur;
            Livre::titre = titre;
            Livre::prix = prix;
            Livre::devise = devise;
            cout << "Classe Livre construite" << endl;
        }
        ~Livre(void){
            Livre::auteur.clear();
            Livre::devise.clear();
            cout << "Classe Livre détruite" << endl;
        }

        void afficher_livre(void){
            cout << titre<< endl;
            cout << auteur << "\t\t" << prix << ' ' << devise << endl;
        };
        private:
            string auteur;
            float prix;
            string devise;
};

int main(void){
    Livre texte("Suzanne Collins", "Hunger Games (Les jeux de la faim)", 15.85, "EUR");
    texte.afficher_livre();
}