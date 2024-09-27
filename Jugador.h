#ifndef Jugador_H
#define Jugador_H
#include "Baraja.h"
#include "Carta.h"
#include <string>

using namespace std;
class Jugador{
	
	public:
		string nombre;
		int mano[10];
		int numColores; 
		int puntos;
		int posiRestar;
		int puntosRestar;
		
		Jugador(string nombre);
		void recibirCarta(Carta carta, Baraja& baraja);
		void mostrarMano();
		int tablaPuntos(int carta);
		int puntaje();
		bool finalizarJuego();
};

#endif 