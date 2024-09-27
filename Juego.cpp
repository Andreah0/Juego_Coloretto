#include <iostream>
#include <vector>
#include "Carta.h"
#include "Juego.h"
#include "Baraja.h"
#include "Jugador.h"
#include "colors.h"
using namespace std;


Juego::Juego(){
	
	cout << "Ingrese el numero de jugadores (3-5): " << endl; cin >> numJugadores;
	
	
	if(numJugadores >=3 && numJugadores<=5){
		for(int i=0; i<numJugadores; i++){
			cout << "ingrese el nombre del jugador " << i << " "; cin >> nombre;
			jugadores.push_back(Jugador(nombre));
		}
		}else{
		
			cout << "Cantidad de jugadores incorrecta" << endl;
		}
	
	rondaFinal=false;
	columnas.resize(numJugadores);
	baraja.mezclar();
}

void Juego::iniciarJuego() {
    while (!finalizarJuego()) {
        
        nuevaRonda();
        cout << "Ronda numero " << numRonda << endl;
        
        while (!rondaTerminada()) {
            if (!jugadorActivo[turno]) {
                turno = (turno + 1) % jugadores.size();
                continue;
            }
        
            
            bool turnoFinalizado=false;
            
            while(!turnoFinalizado){
                
                cout << "Turno de " << jugadores[turno].nombre << endl;
                int rta;
                cout << "1. Tomar una carta de la baraja\n2. Tomar una columna\n3. Mostrar mano de los Jugadores" << endl;
                cin >> rta;
            
                switch(rta) {
                    case 1:
                        tomarCartaBaraja(turno);
                        turnoFinalizado=true;
                        break;
                    case 2:
                        tomarColumna(turno);
                        turnoFinalizado=true;
                        break;
                    case 3:
                        for(int i=0; i<jugadores.size(); i++){
                            jugadores[i].mostrarMano();
                        }
                        break;
                    default:
                        cout << "Opción inválida" << endl;
                        break;
                }
            }
        
            turno = (turno + 1) % jugadores.size();
        }
        
    }
    puntajesFinales();
}

void Juego::tomarCartaBaraja(int turno) {
    Carta c = baraja.darCarta();
    cout << "Has sacado la carta: " << c.imprimirTipoCarta() << endl;
    
    int columna;
    do {
        cout << "¿En qué columna desea poner la carta? ";
        for (int i = 0; i < numJugadores; i++) {
            if (!columnaTomada[i]) { // Mostrar solo las columnas que no han sido tomadas
                cout << i << " ";
            }
        }
        cout << endl;
        cin >> columna;

        if (columna < 0 || columna >= numJugadores) {
            cout << "Columna inválida. Por favor, elija una columna válida." << endl;
        } else if (columnaTomada[columna]) {
            cout << "Esta columna ya ha sido tomada. Elija otra." << endl;
        } else if (columnas[columna].size() >= 3) {
            cout << "Esta columna está llena. Por favor, elija otra." << endl;
        }
    } while (columna < 0 || columna >= numJugadores || columnaTomada[columna] || columnas[columna].size() >= 3);

    columnas[columna].push_back(c);
    mostrarColumnas();
}

void Juego::tomarColumna(int turno) {
    
    if (!jugadorActivo[turno]) {
        cout << "Este jugador ya ha tomado una columna en esta ronda" << endl;
        return;
    }

    int columna;
    do {
        cout << "¿Qué columna desea tomar?: ";
        for (int i = 0; i < numJugadores; i++) {
            if (!columnaTomada[i]) {
                cout << i << " ";
            }
        }
        cout << endl;
        cin >> columna;
        
        if (columna < 0 || columna >= numJugadores || columnaTomada[columna]) {
            cout << "Columna inválida o ya tomada, por favor elija otra columna." << endl;
        }
    } while (columna < 0 || columna >= numJugadores || columnaTomada[columna]);
    
    for (Carta& carta : columnas[columna]) {
        jugadores[turno].recibirCarta(carta,baraja);
    }
    
    columnas[columna].clear();
    columnaTomada[columna] = true;
    jugadorActivo[turno] = false;
    mostrarColumnas();
}


void Juego::mostrarColumnas(){
	for(int i=0; i<columnas.size(); i++){
		cout << "( " << i << " )" << endl;
		if(columnas[i].empty()){
			cout << "Columna vacia" << endl;
		}else{	
			for(auto carta: columnas[i]){
				cout << carta.imprimirTipoCarta();
			}
		}
		cout << endl;
	}
}

bool Juego::rondaTerminada() {
    for (bool activo : jugadorActivo) {
        if (activo) return false;
    }
    return true;
}

void Juego::nuevaRonda() {
    numRonda++;
    columnaTomada.assign(numJugadores, false);
    jugadorActivo.assign(numJugadores, true);

    for (auto& col : columnas) {
        col.clear();
    }
}


void Juego::puntajesFinales(){
	
	cout << "El juego ha terminado\nLos resultados son: " << endl;
	for(int i=0; i<jugadores.size(); i++){
		jugadores[i].mostrarMano();
		cout << jugadores[i].puntaje() << endl;
		cout << "-------------------------------------------------" << endl;
	}
	
}


bool Juego::finalizarJuego() {
    if (baraja.mazo.size() <= 16 && !rondaFinal) {
        cout << "Esta Es La Ultima Ronada" << endl;
        rondaFinal = true;
    }
    return rondaFinal && rondaTerminada();
}


