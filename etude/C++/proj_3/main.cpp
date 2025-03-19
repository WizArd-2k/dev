#include <iostream>
#include <string>

using namespace std;

enum enumGenre { SCIENCE_FICTION, FANTASY, MYSTERY, NON_FICTION };
const char* listeGenre[] = { "Science Fiction", "Fantasy", "Mystery", "Non Fiction" };

class Ouvrages {
protected:
    string auteur;
    string titre;
    double prix;

public:
    void setAuteur(const string& auteur) { this->auteur = auteur; }
    string getAuteur() const { return auteur; }

    void setTitre(const string& titre) { this->titre = titre; }
    string getTitre() const { return titre; }

    void setPrix(double prix) { this->prix = prix; }
    double getPrix() const { return prix; }
};

class Livres : public Ouvrages {
private:
    int nombrePages;
    enumGenre genre;

public:
    int getNombrePages() const { return nombrePages; }
    void setNombrePages(int nombrePages) { this->nombrePages = nombrePages; }

    enumGenre getGenre() const { return genre; }
    void setGenre(enumGenre genre) { this->genre = genre; }

    void setTitre(const string& titre) { this->titre = titre; } // Ajout de la méthode setTitre
};

int main() {
    Ouvrages revue;
    Livres livre;

    livre.setAuteur("Arthur C. Clarke");
    livre.setTitre("2001 l'odysse de l'espace");
    livre.setPrix(49.95);
    livre.setGenre(SCIENCE_FICTION);
    livre.setNombrePages(346);

    revue.setAuteur("ABEILLE DE FRANCE");
    revue.setTitre("L’abeille de France");
    revue.setPrix(3.00);

    cout << "Le prix du livre est de " << livre.getPrix() << " €\n";
    cout << "Son titre est : " << livre.getTitre() << "\n";
    cout << "Son auteur s’appelle : " << livre.getAuteur() << "\n";
    cout << "Il est classé dans la catégorie " << listeGenre[livre.getGenre()] << " et contient : " << livre.getNombrePages() << " pages\n";
    cout << "Le prix de la revue est de " << revue.getPrix() << " €\n";
    cout << "Son titre est : " << revue.getTitre() << "\n";
    cout << "L’association est : " << revue.getAuteur() << "\n";

    return 0;
}