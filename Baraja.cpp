#include <random>
#include <algorithm>
#include <vector>
#include "Baraja.h"
#include "colors.h"
using namespace std;

Baraja::Baraja(){
	for(int c=0; c<7; c++ ){
		for(int i=0; i<9; i++){
			mazo.push_back(Carta(c));
		}
	}
	for(int i=0; i<10; i++){
		mazo.push_back(Carta(7));
	}
	for(int i=0; i<2; i++){
		mazo.push_back(Carta(9));
	}
	mazo.push_back(Carta(8));
}

void Baraja::mezclar(){
	random_device rd;
    default_random_engine rng(rd());  //asegura que cada vez que se barajan los elementos, el orden resultante sea diferente y aleatorio.

    shuffle(mazo.begin(), mazo.end(), rng);
}

Carta Baraja::darCarta() {
    if (!mazo.empty()) {
        Carta c = mazo.back();  
        mazo.pop_back();        
        return c;               
    }
    return Carta(-1);  // Devuelve una carta "vacía" o inválida
}

