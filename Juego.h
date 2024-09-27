#include <iostream>
#include <vector>
#include <string>
#include "Carta.h"
#include "Baraja.h"
#include "Jugador.h"
#include "colors.h"
using namespace std;


class Juego{
	
	public:
		
		string nombre;
		int turno;
		int numRonda=0;
		bool rondaFinal;
		int numJugadores;
		vector<Jugador> jugadores;
		vector<vector<Carta>> columnas;
		vector<bool> columnaTomada;
 	    vector<bool> jugadorActivo;

		Baraja baraja;
			
		Juego();
		void iniciarJuego();
		void tomarCartaBaraja(int turno);
		void tomarColumna(int turno);
		void mostrarColumnas();
		bool rondaTerminada();
		void puntajesFinales();
		bool finalizarJuego();
		void nuevaRonda();
		
};