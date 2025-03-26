#ifndef MP3_H_
#define MP3_H_

#pragma pack(1)
#include <string>
#include "fichiers.h"

const std::string LISTE_GENRE_MUSICAL[] = {
    "Blues", "Classic Rock", "Country", "Dance", "Disco", "Funk", "Grunge",
    "Hip-Hop", "Jazz", "Metal", "New Age", "Oldies", "Other", "Pop", 
    "R&B", "Rap", "Reggae", "Rock", "Techno", "Industrial", "Alternative",
    "Ska", "Death Metal", "Pranks", "Soundtrack", "Euro-Techno", "Ambient",
    "Trip-Hop", "Vocal", "Jazz+Funk", "Fusion", "Trance", "Classical",
    "Instrumental", "Acid", "House", "Game", "Sound Clip", "Gospel", "Noise",
    "Alternative Rock", "Bass", "Soul", "Punk", "Space", "Meditative",
    "Instrumental Pop", "Instrumental Rock", "Ethnic", "Gothic", "Darkwave",
    "Techno-Industrial", "Electronic", "Pop-Folk", "Eurodance", "Dream",
    "Southern Rock", "Comedy", "Cult", "Gangsta", "Top 40", "Christian Rap",
    "Pop/Funk", "Jungle", "Native American", "Cabaret", "New Wave",
    "Psychadelic", "Rave", "Showtunes", "Trailer", "Lo-Fi", "Tribal",
    "Acid Punk", "Acid Jazz", "Polka", "Retro", "Musical", "Rock & Roll",
    "Hard Rock"
};

class MP3 : public Fichiers {
private:
    struct ID3v1_1 {
        char tag[3];
        char title[30];
        char artist[30];
        char album[30];
        char year[4];
        char comment[28];
        char zero_byte;
        char track;
        char genre;
    } tagID3V;

public:
    MP3(std::string filename, access_t mode);
    virtual ~MP3();
    bool litMetadonnees();
    bool ecritMetadonnees();
    void afficherMetadonnees();
    void modifierMetadonnees();
};

#endif /* MP3_H_ */