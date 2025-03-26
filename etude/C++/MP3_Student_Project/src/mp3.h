/*
 * mp3.h
 *
 */
#ifndef MP3_H_
#define MP3_H_

#pragma pack(1) // alignement mémoire sur 2 octets nécessaire pour la structure
#include <string>
#include "fichiers.h"

const string LISTE_GENRE_MUSICAL[]={"Blues","Classic Rock","Country","Dance","Disco","Funk","Grunge","Hip-Hop","Jazz","Metal","New Age","Oldies","Other","Pop","Rhythm and Blues","Rap","Reggae","Rock","Techno","Industrial","Alternative","Ska","Death Metal","Pranks","Soundtrack","Euro-Techno","Ambient","Trip-Hop","Vocal","Jazz & Funk","Fusion","Trance","Classical","Instrumental","Acid","House","Game","Sound clip","Gospel","Noise","Alternative Rock","Bass","Soul","Punk","Space","Meditative","Instrumental Pop","Instrumental Rock","Ethnic","Gothic","Darkwave","Techno-Industrial","Electronic","Pop-Folk","Eurodance","Dream","Southern Rock","Comedy","Cult","Gangsta","Top 40","Christian Rap","Pop/Funk","Jungle music","Native US","Cabaret","New Wave","Psychedelic","Rave","Showtunes","Trailer","Lo-Fi","Tribal","Acid Punk","Acid Jazz","Polka","Retro","Musical","Rock ’n’ Roll","Hard Rock"};

class MP3 : public Fichiers
{
    private:
		// A FAIRE : Structure des données de l'entête
		struct ID3v1_1 {
      char title[256];
		} tagID3V;

    public:
        MP3(string,access_t);
        virtual ~MP3();
        bool litMetadonnees();
        bool ecritMetadonnees();
};

#endif /* MP3_H_ */
