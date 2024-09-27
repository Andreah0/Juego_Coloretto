#ifndef Carta_H
#define Carta_H
#include <string>
using namespace std;

class Carta{
  
    public: 
        
        int tipo_carta;
        Carta();
        Carta(int tipo_carta);
        string imprimirTipoCarta();
        
};
#endif  