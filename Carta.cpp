#include <iostream>
#include "Carta.h"
#include "colors.h"
#include <string>
using namespace std;


Carta::Carta(){
    tipo_carta=0;
}

Carta::Carta(int tipo_carta){
    this->tipo_carta=tipo_carta;
}
        
string Carta::imprimirTipoCarta(){
            
    switch(tipo_carta){
                
        case 0:
            return ORANGE "Camaleon Naranja " RESET;
            break;
        case 1:
           return BLUE "Camaleon Azul " RESET;
            break;
        case 2:
            return GRAY "Camaleon Cafe " RESET;
            break;
        case 3:
            return YELLOW "Camaleon Amarillo " RESET;
            break;
        case 4:
            return MAGENTA "Camaleon Violeta " RESET;
            break;
        case 5:
            return GREEN "Camaleon Verde " RESET;
            break;
        case 6:
            return RED "Camaleon Rojo " RESET;
            break;
        case 7:
            return WHITE "+2 " RESET;
            break;
		case 8:
            return GOLD "Camaleon Dorado " RESET;
            break;
		case 9:
            return BOLD "Camaleon multicolor " RESET;
            break;
        default:
        	return "Carta desconocida ";
    }

}

  
