/*
 * mp3.h
 *
 */
#ifndef MP3_H_
#define MP3_H_

#pragma pack(1) // Alignement mémoire sur 1 octet nécessaire pour la structure
#include <string>
#include "fichiers.h"

const std::string LISTE_GENRE_MUSICAL[] = {"Blues", "Classic Rock", "Country", "Dance", "Disco", "Funk", "Grunge", "Hip-Hop", "Jazz", "Metal", "New Age", "Oldies", "Other", "Pop", "Rhythm and Blues", "Rap", "Reggae", "Rock", "Techno", "Industrial", "Alternative", "Ska", "Death Metal", "Pranks", "Soundtrack", "Euro-Techno", "Ambient", "Trip-Hop", "Vocal", "Jazz & Funk", "Fusion", "Trance", "Classical", "Instrumental", "Acid", "House", "Game", "Sound clip", "Gospel", "Noise", "Alternative Rock", "Bass", "Soul", "Punk", "Space", "Meditative", "Instrumental Pop", "Instrumental Rock", "Ethnic", "Gothic", "Darkwave", "Techno-Industrial", "Electronic", "Pop-Folk", "Eurodance", "Dream", "Southern Rock", "Comedy", "Cult", "Gangsta", "Top 40", "Christian Rap", "Pop/Funk", "Jungle music", "Native US", "Cabaret", "New Wave", "Psychedelic", "Rave", "Showtunes", "Trailer", "Lo-Fi", "Tribal", "Acid Punk", "Acid Jazz", "Polka", "Retro", "Musical", "Rock ’n’ Roll", "Hard Rock"};

class MP3 : public Fichiers
{
    private:
        struct ID3v1_1 {
            char tag[3];          // "TAG"
            char title[30];       // Titre de la chanson
            char artist[30];      // Nom de l'interprète
            char album[30];       // Nom de l'album
            char year[4];         // Année de sortie
            char comment[28];     // Commentaire
            char zero_byte;       // Séparateur (0x00)
            char track;           // Numéro de la piste
            char genre;           // Genre musical
        } tagID3V;

    public:
        MP3(std::string filename, access_t mode) : Fichiers(filename, mode) {}
        virtual ~MP3() {}
        bool litMetadonnees();
        bool ecritMetadonnees();
        void afficherMetadonnees();
        void modifierMetadonnees();
};

#endif /* MP3_H_ */