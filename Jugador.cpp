#include <iostream>
#include "colors.h"
#include "Jugador.h"
#include "Baraja.h"
#include "Carta.h"
#include <map>
#include <string>
using namespace std;


Jugador::Jugador(string nombre){
	this->nombre=nombre;
	numColores=0;
	for(int i=0; i<10; i++){
		mano[i]=0;
	}
}

void Jugador::recibirCarta(Carta carta, Baraja& baraja) {
    mano[carta.tipo_carta]++;
    
    if (carta.tipo_carta == 8) { // Camaleon dorado
        cout << "Has obtenido un camaleon dorado, tienes que tomar otra carta del mazo" << endl;
        Carta cartaAdicional = baraja.darCarta();
        mano[cartaAdicional.tipo_carta]++;
        cout << "Has sacado la carta adicional: " << cartaAdicional.imprimirTipoCarta() << endl;
    }
    int comodin;
    if(carta.tipo_carta == 9){
        cout << "Has tomado un comodin, a que color de carta se lo deseas poner: ";cin >> comodin;
        mano[comodin]++;
    }
}

void Jugador::mostrarMano(){
	cout << "Mano de " << nombre << ": ";
	for(int i=0; i<8; i++){
		Carta carta(i);
		cout << carta.imprimirTipoCarta() << " (" << mano[i] << ") ";
	}
	cout << endl;
}


int Jugador::tablaPuntos(int carta){

	map<int,int> tablaValores;
	
	tablaValores[1]=1;
	tablaValores[2]=3;
	tablaValores[3]=6;
	tablaValores[4]=10;
	tablaValores[5]=15;
	tablaValores[6]=21;
	tablaValores[9]=2;
	
	return tablaValores[carta];				
}	

int Jugador::puntaje(){
    
    puntos = 0;
    numColores = 0;
    
	for(int i=0; i<7; i++){
		if(mano[i]>0){
			numColores++;
			puntos+=tablaPuntos(mano[i]);
	}
	
	if(numColores>3){
		 cout << "Tines mas de tres colores. Cual color de carta desea restar? (0-6) " << endl;
		 cin >> posiRestar;
		 puntosRestar= tablaPuntos(mano[posiRestar]);
		 puntos-=puntosRestar;
		 
	}
}
    return puntos;
}
