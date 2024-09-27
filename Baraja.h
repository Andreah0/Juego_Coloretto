#ifndef Mazo_H
#define Mazo_H
#include "Carta.h"
#include <vector>
using namespace std;
class Baraja{
	
	public:
		vector<Carta> mazo;
		Baraja();
		void mezclar();
		Carta darCarta();	
};

#endif 