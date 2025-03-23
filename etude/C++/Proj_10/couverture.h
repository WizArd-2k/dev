#ifndef COUVERTURE_H_
#define COUVERTURE_H_

#include <string>
using namespace std;

class Couverture{
    public:
        Couverture(string titre);
        ~Couverture(void);
    
    protected:
        string titre;
};

#endif // COUVERTURE_H_