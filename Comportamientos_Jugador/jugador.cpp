#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;

//Función que pinta el precipio que hay en el borde, independientemente del mapa que sea
void pintaPrecipio(vector<vector<unsigned char>> &matriz){
    for(int i=0;i<matriz.size();i++){
        for(int j=0;j<matriz[0].size();j++){
            matriz[0][j] = 'P'; //Pintar fila 0
            matriz[1][j] = 'P'; //Pintar fila 1
            matriz[2][j] = 'P'; //Pintar fila 2
            matriz[matriz.size()-3][j] = 'P'; //Pintar antepenúltima fila
            matriz[matriz.size()-2][j] = 'P'; //Pintar penúltima fila
            matriz[matriz.size()-1][j] = 'P'; //Pintar última fila
            matriz[i][0] = 'P'; //Pintar columna 0
            matriz[i][1] = 'P'; //Pintar columna 1
            matriz[i][2] = 'P'; //Pintar columna 2
            matriz[i][matriz[0].size()-3] = 'P'; //Pintar antepenúltima columna
            matriz[i][matriz[0].size()-2] = 'P'; //Pintar penúltima columna
            matriz[i][matriz[0].size()-1] = 'P'; //Pintar última columna
        }
    }
    
}

//Función que muestra el valor de los sensores
void muestraSensores(Sensores sensores){
    cout << "Posicion: fila " << sensores.posF << " columna " << sensores.posC;

	switch (sensores.sentido)
	{
		case norte:	  cout << " Norte\n";	break;
		case noreste: cout << " Noreste\n";	break;
		case este:    cout << " Este\n";	break;
		case sureste: cout << " Sureste\n";	break;
		case sur:     cout << " Sur\n";	break;
		case suroeste:cout << " Suroeste\n";	break;
		case oeste:   cout << " Oeste\n";	break;
		case noroeste:cout << " Noroeste\n";	break;
	}
	cout << "Terreno: ";
	for (int i=0; i<sensores.terreno.size(); i++)
		cout << sensores.terreno[i];

	cout << "  Agentes: ";
	for (int i=0; i<sensores.agentes.size(); i++)
		cout << sensores.agentes[i];

	cout << "\nColision: " << sensores.colision;
	cout << "  Reset: " << sensores.reset;
	cout << "  Vida: " << sensores.vida << endl<< endl;

}

//Función que pinta la parte de mapa ya descubierta
void PonerTerrenoEnMatriz(const vector<unsigned char> & terreno, const state &st, vector<vector<unsigned char>> &matriz){

      matriz[st.fil][st.col] = terreno[0];
      switch (st.brujula){
        case norte:
        cout << "Estoy mirando al norte" << endl;
        matriz[st.fil - 1][st.col - 1] = terreno[1];
        matriz[st.fil - 1][st.col]     = terreno[2];
        matriz[st.fil - 1][st.col + 1] = terreno[3];
        matriz[st.fil - 2][st.col - 2] = terreno[4];
        matriz[st.fil - 2][st.col - 1] = terreno[5];
        matriz[st.fil - 2][st.col]     = terreno[6];
        matriz[st.fil - 2][st.col + 1] = terreno[7];
        matriz[st.fil - 2][st.col + 2] = terreno[8];
        matriz[st.fil - 3][st.col - 3] = terreno[9];
        matriz[st.fil - 3][st.col - 2] = terreno[10];
        matriz[st.fil - 3][st.col - 1] = terreno[11];
        matriz[st.fil - 3][st.col]     = terreno[12];
        matriz[st.fil - 3][st.col + 1] = terreno[13];
        matriz[st.fil - 3][st.col + 2] = terreno[14];
        matriz[st.fil - 3][st.col + 3] = terreno[15];
        break;
        case sur:
        cout << "Estoy mirando al sur" << endl;
        matriz[st.fil + 1][st.col + 1] = terreno[1];
        matriz[st.fil + 1][st.col]     = terreno[2];
        matriz[st.fil + 1][st.col - 1] = terreno[3];
        matriz[st.fil + 2][st.col + 2] = terreno[4];
        matriz[st.fil + 2][st.col + 1] = terreno[5];
        matriz[st.fil + 2][st.col]     = terreno[6];
        matriz[st.fil + 2][st.col - 1] = terreno[7];
        matriz[st.fil + 2][st.col - 2] = terreno[8];
        matriz[st.fil + 3][st.col + 3] = terreno[9];
        matriz[st.fil + 3][st.col + 2] = terreno[10];
        matriz[st.fil + 3][st.col + 1] = terreno[11];
        matriz[st.fil + 3][st.col]     = terreno[12];
        matriz[st.fil + 3][st.col - 1] = terreno[13];
        matriz[st.fil + 3][st.col - 2] = terreno[14];
        matriz[st.fil + 3][st.col - 3] = terreno[15];
        break;
        case este:
        cout << "Estoy mirando al este" << endl;
        matriz[st.fil - 1][st.col + 1] = terreno[1];
        matriz[st.fil ][st.col +1]     = terreno[2];
        matriz[st.fil + 1][st.col + 1] = terreno[3];
        matriz[st.fil - 2][st.col + 2] = terreno[4];
        matriz[st.fil - 1][st.col + 2] = terreno[5];
        matriz[st.fil][st.col + 2]     = terreno[6];
        matriz[st.fil + 1][st.col + 2] = terreno[7];
        matriz[st.fil + 2][st.col + 2] = terreno[8];
        matriz[st.fil - 3][st.col + 3] = terreno[9];
        matriz[st.fil - 2][st.col + 3] = terreno[10];
        matriz[st.fil - 1][st.col + 3] = terreno[11];
        matriz[st.fil ][st.col + 3]    = terreno[12];
        matriz[st.fil + 1][st.col + 3] = terreno[13];
        matriz[st.fil + 2][st.col + 3] = terreno[14];
        matriz[st.fil + 3][st.col + 3] = terreno[15];
        break;
        case oeste:
        cout << "Estoy mirando al oeste" << endl;
        matriz[st.fil + 1][st.col - 1] = terreno[1];
        matriz[st.fil][st.col - 1]     = terreno[2];
        matriz[st.fil - 1][st.col - 1] = terreno[3];
        matriz[st.fil + 2][st.col - 2] = terreno[4];
        matriz[st.fil + 1][st.col - 2] = terreno[5];
        matriz[st.fil][st.col - 2]     = terreno[6];
        matriz[st.fil - 1][st.col - 2] = terreno[7];
        matriz[st.fil - 2][st.col - 2] = terreno[8];
        matriz[st.fil + 3][st.col - 3] = terreno[9];
        matriz[st.fil + 2][st.col - 3] = terreno[10];
        matriz[st.fil + 1][st.col - 3] = terreno[11];
        matriz[st.fil][st.col - 3]     = terreno[12];
        matriz[st.fil - 1][st.col - 3] = terreno[13];
        matriz[st.fil - 2][st.col - 3] = terreno[14];
        matriz[st.fil - 3][st.col - 3] = terreno[15];
        break;
        case noreste:
        matriz[st.fil - 1][st.col]     = terreno[1];
        matriz[st.fil - 1][st.col + 1] = terreno[2];
        matriz[st.fil][st.col + 1]     = terreno[3];
        matriz[st.fil - 2][st.col]     = terreno[4];
        matriz[st.fil - 2][st.col + 1] = terreno[5];
        matriz[st.fil - 2][st.col + 2] = terreno[6];
        matriz[st.fil - 1][st.col + 2] = terreno[7];
        matriz[st.fil][st.col + 2]     = terreno[8];
        matriz[st.fil - 3][st.col]     = terreno[9];
        matriz[st.fil - 3][st.col + 1] = terreno[10];
        matriz[st.fil - 3][st.col + 2] = terreno[11];
        matriz[st.fil - 3][st.col + 3] = terreno[12];
        matriz[st.fil - 2][st.col + 3] = terreno[13];
        matriz[st.fil - 1][st.col + 3] = terreno[14];
        matriz[st.fil][st.col + 3]     = terreno[15];
        break; 
        case noroeste:
        matriz[st.fil][st.col - 1]     = terreno[1];
        matriz[st.fil - 1][st.col - 1] = terreno[2];
        matriz[st.fil - 1][st.col]     = terreno[3];
        matriz[st.fil][st.col - 2]     = terreno[4];
        matriz[st.fil - 1][st.col - 2] = terreno[5];
        matriz[st.fil - 2][st.col - 2] = terreno[6];
        matriz[st.fil - 2][st.col - 1] = terreno[7];
        matriz[st.fil - 2][st.col]     = terreno[8];
        matriz[st.fil][st.col - 3]     = terreno[9];
        matriz[st.fil - 1][st.col - 3] = terreno[10];
        matriz[st.fil - 2][st.col - 3] = terreno[11];
        matriz[st.fil - 3][st.col - 3] = terreno[12];
        matriz[st.fil - 3][st.col - 2] = terreno[13];
        matriz[st.fil - 3][st.col - 1] = terreno[14];
        matriz[st.fil - 3][st.col]     = terreno[15];
        break; 
        case sureste:
        matriz[st.fil][st.col + 1]     = terreno[1];
        matriz[st.fil + 1][st.col + 1] = terreno[2];
        matriz[st.fil + 1][st.col]     = terreno[3];
        matriz[st.fil][st.col + 2]     = terreno[4];
        matriz[st.fil + 1][st.col + 2] = terreno[5];
        matriz[st.fil + 2][st.col + 2] = terreno[6];
        matriz[st.fil + 2][st.col + 1] = terreno[7];
        matriz[st.fil + 2][st.col]     = terreno[8];
        matriz[st.fil][st.col + 3]     = terreno[9];
        matriz[st.fil + 1][st.col + 3] = terreno[10];
        matriz[st.fil + 2][st.col + 3] = terreno[11];
        matriz[st.fil + 3][st.col + 3] = terreno[12];
        matriz[st.fil + 3][st.col + 2] = terreno[13];
        matriz[st.fil + 3][st.col + 1] = terreno[14];
        matriz[st.fil + 3][st.col]     = terreno[15];
        break; 
        case suroeste:
        matriz[st.fil + 1][st.col]     = terreno[1];
        matriz[st.fil + 1][st.col - 1] = terreno[2];
        matriz[st.fil][st.col - 1]     = terreno[3];
        matriz[st.fil + 2][st.col]     = terreno[4];
        matriz[st.fil + 2][st.col - 1] = terreno[5];
        matriz[st.fil + 2][st.col - 2] = terreno[6];
        matriz[st.fil + 1][st.col - 2] = terreno[7];
        matriz[st.fil][st.col - 2]     = terreno[8];
        matriz[st.fil + 3][st.col]     = terreno[9];
        matriz[st.fil + 3][st.col - 1] = terreno[10];
        matriz[st.fil + 3][st.col - 2] = terreno[11];
        matriz[st.fil + 3][st.col - 3] = terreno[12];
        matriz[st.fil + 2][st.col - 3] = terreno[13];
        matriz[st.fil + 1][st.col - 3] = terreno[14];
        matriz[st.fil][st.col - 3]     = terreno[15];
        break; 
     }
}

//Función que indica si dentro de la visión del robot hay zapatillas
bool hayZapatillas(const vector<unsigned char> & terreno){
    bool hay_objeto = false;
    for(int i=0;i<terreno.size();i++){
        if (terreno [i] == 'K') hay_objeto = true;
        if (terreno [i] == 'D') hay_objeto = true;
    }
    return hay_objeto;
}

//Función que indica si dentro de la visión del robot hay bikini
bool hayBikini(const vector<unsigned char> & terreno){
    bool hay_objeto = false;
    for(int i=0;i<terreno.size();i++){
        if (terreno [i] == 'K') hay_objeto = true;
        if (terreno [i] == 'D') hay_objeto = true;
    }
    return hay_objeto;
}

//Función que devuelve la posición de un objeto (Zapatillas ó Bikini) que hay dentro del alcance del robot en un momento dado
int posObjeto(const vector<unsigned char> & terreno){
    int pos_objeto = -1;
    for(int i=0;i<terreno.size();i++){
        if (terreno [i] == 'K') pos_objeto=i;
        if (terreno[i] == 'D') pos_objeto=i;
    }
    return pos_objeto;
}

//Función que indica si dentro de la visión del robot hay alguna casilla de recarga
bool hayRecarga(const vector<unsigned char> & terreno){
    bool hay_recarga = false;
    for(int i=0;i<terreno.size();i++){
        if (terreno [i] == 'X') hay_recarga = true;
    }
    return hay_recarga;
}

//Función que devuelve la posición de la casilla de recarga que hay dentro del alcance del robot en un momento dado
int posRecarga(const vector<unsigned char> & terreno){
    int pos_recarga = -1;
    for(int i=0;i<terreno.size();i++){
        if (terreno [i] == 'X') pos_recarga=i;
    }
    return pos_recarga;
}

//Función que indica si dentro de la visión del robot hay alguna casilla de recarg
bool hayPosicionamiento(const vector<unsigned char> & terreno){
    bool hay_posicionamiento = false;
    for(int i=0;i<terreno.size();i++){
        if (terreno [i] == 'G') hay_posicionamiento = true;
    }
    return hay_posicionamiento;
}

//Función que devuelve la posición de la casilla de posicionamiento que hay dentro del alcance del robot en un momento dado
int posPosicionamiento(const vector<unsigned char> & terreno){
    int pos_poscionamiento = -1;
    for(int i=0;i<terreno.size();i++){
        if (terreno [i] == 'G') pos_poscionamiento=i;
    }
    return pos_poscionamiento;
}

//Función que indica si hay un lobo dentro de la visión del robot
bool hayLoboCerca(const vector<unsigned char> & agentes){
    bool hay_lobo = false;
    for(int i=0;i<agentes.size();i++){
        if (agentes [i] == 'l') hay_lobo = true;
    }
    return hay_lobo;
}

//Función que indica si hay un aldeano dentro de la visión del robot
bool hayAldeanoCerca(const vector<unsigned char> & agentes){
    bool hay_aldeano = false;
    for(int i=0;i<agentes.size();i++){
        if (agentes [i] == 'a') hay_aldeano = true;
    }
    return hay_aldeano;
}

//Función que indica si ha encontrado hueco entre 2 muros a la izquierda
bool hayHuecoDcha(const vector<unsigned char> & terreno){
        return (terreno[3] != ('l' || 'P' || 'M') && terreno[7] == ('M'));
}

//Función que indica si estoy rodeado de agua y no tengo bikini
void ComportamientoJugador::rodeadoA(const vector<unsigned char> & terreno){
    if((terreno[1] == 'A' && terreno[2] == 'A' && terreno[3] == 'A') && !bikini && num_turns > 4)rodeadoAgua = true;
}

//Función que indica si estoy rodeado de bosque y no tengo zapatillas
void ComportamientoJugador::rodeadoB(const vector<unsigned char> & terreno){
    if((terreno[1] == 'B' && terreno[2] == 'B' && terreno[3] == 'B') && !zapatillas && num_turns > 4)rodeadoBosque = true;
}

//Función que indica al robot como moverse de forma básica
Action ComportamientoJugador::funcionamientoBasico(Sensores sensores){
    Action accion;
    if((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='B' or sensores.terreno[2]=='A' or sensores.terreno[2]=='D' or 
        sensores.terreno[2]=='K') and sensores.agentes[2]=='_' and sensores.terreno[2] != 'P' and sensores.terreno[2] != 'M' and num_walks<=10){
            accion = actWALK;
        
	}else if(!girar_derecha){
		    accion = actTURN_L;
		    girar_derecha = (rand()%2==0);

	}else{
		    accion = actTURN_SR;
		    girar_derecha = (rand()%2==0);
	}

    return accion;
}

//Función que indica al robot como moverse en caso de tener un aldeano
Action ComportamientoJugador::funcionamientoConAldeano(Sensores sensores){
    
    Action accion; 

    switch (sensores.sentido){
        case norte: 
        case sur: 
        case este: 
        case oeste: 
            if(sensores.agentes[4] == 'a'|| sensores.agentes[9] == 'a' || sensores.agentes[10] == 'a'){
                accion = actTURN_SR;    
            }else if(sensores.agentes[8] == 'a' || sensores.agentes[14] == 'a' || sensores.agentes[15] == 'a'){
                accion = actTURN_L;
            }else if(sensores.agentes[11] == 'a' || sensores.agentes[12] == 'a' || sensores.agentes[13] == 'a'){
                if(!girar_derecha){
		            accion = actTURN_L;
		            girar_derecha = (rand()%2==0);
	            }else{
		            accion = actTURN_SR;
		            girar_derecha = (rand()%2==0);
	            }
            }else{
                if(sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.agentes[2] != 'a'){
                    accion = actWALK;
            }else{
                accion = actIDLE; 
                }
            }
        break;

        case noreste: 
        case noroeste: 
        case sureste: 
        case suroeste: 
            if(sensores.agentes[1] == 'a' || sensores.agentes[2] == 'a' || sensores.agentes[4] == 'a' || sensores.agentes[5] == 'a'
             || sensores.agentes[6] == 'a' || sensores.agentes[9] == 'a' || sensores.agentes[10] == 'a' || sensores.agentes[11] == 'a' || sensores.agentes[12] == 'a'){
                accion = actTURN_SR;    
            }else if(sensores.agentes[3] == 'a' || sensores.agentes[7] == 'a' || sensores.agentes[8] == 'a' || sensores.agentes[13] == 'a' 
             || sensores.agentes[14] == 'a' || sensores.agentes[15] == 'a'){
                accion = actTURN_L;
            }else{
                if(sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.agentes[2] != 'l'){
                    accion = actWALK;
                }else{
                accion = actIDLE; 
                }
            }
        break;
    }
    return accion;
}

//Función que indica al robot como moverse en caso de tener un lobo dentro de la visión de sus sensores
Action ComportamientoJugador::funcionamientoConLobo(Sensores sensores){
    
    Action accion; 

    switch (sensores.sentido){
        case norte: 
        case sur: 
        case este: 
        case oeste: 
            if(sensores.agentes[4] == 'l'|| sensores.agentes[9] == 'l' || sensores.agentes[10] == 'l'){
                accion = actTURN_SR;    
            }else if(sensores.agentes[8] == 'l' || sensores.agentes[14] == 'l' || sensores.agentes[15] == 'l'){
                accion = actTURN_L;

            }else if(sensores.agentes[11] == 'l' || sensores.agentes[12] == 'l' || sensores.agentes[13] == 'l'){
                if(!girar_derecha){
		            accion = actTURN_L;
		            girar_derecha = (rand()%2==0);
	            }else{
		            accion = actTURN_SR;
		            girar_derecha = (rand()%2==0);
	            }
            }else{
                if(sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.agentes[2] != 'l'){
                    accion = actWALK;
            }else{
                accion = actIDLE; 
                }
            }
        break;

        case noreste: 
        case noroeste: 
        case sureste: 
        case suroeste: 
            if(sensores.agentes[1] == 'l' || sensores.agentes[2] == 'l' || sensores.agentes[4] == 'l' || sensores.agentes[5] == 'l'
             || sensores.agentes[6] == 'l' || sensores.agentes[9] == 'l' || sensores.agentes[10] == 'l' || sensores.agentes[11] == 'l' || sensores.agentes[12] == 'l'){
                accion = actTURN_SR;    
            }else if(sensores.agentes[3] == 'l' || sensores.agentes[7] == 'l' || sensores.agentes[8] == 'l' || sensores.agentes[13] == 'l' 
             || sensores.agentes[14] == 'l' || sensores.agentes[15] == 'l'){
                accion = actTURN_L;
            }else{
                if(sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.agentes[2] != 'l'){
                    accion = actWALK;
                }else{
                accion = actIDLE; 
                }
            }
        break;
    }
    return accion;
}

//Función que acerca al robot cada vez más a su objeto. En caso de encontrarlo, lo marca como obtenido
Action ComportamientoJugador::acercarACasilla(const vector<unsigned char> & terreno, const state &st, int posFinal){ 
    
    Action accion;
    switch (st.brujula){
        case norte:
        case sur:
        case este:
        case oeste:
            switch(posFinal){
                case 0:  
                         if(terreno[0] == 'K'){
                            bikini = true;
                         }else if(terreno[0] == 'D'){
                            zapatillas = true;
                         }
                         accion = actWALK;     break;
                case 1:  accion = actTURN_L;   break;
                case 2:  accion = actWALK;     break;
                case 3:  accion = actTURN_SR;  break;
                case 4:  accion = actTURN_L;   break;
                case 5:  accion = actWALK;     break;
                case 6:  accion = actWALK;     break;
                case 7:  accion = actWALK;     break;
                case 8:  accion = actTURN_SR;  break;
                case 9:  accion = actTURN_L;   break;
                case 10: accion = actTURN_L;   break;
                case 11: accion = actWALK;     break;
                case 12: accion = actWALK;     break;
                case 13: accion = actWALK;     break;
                case 14: accion = actTURN_SR;  break; 
                case 15: accion = actTURN_SR;  break;
                default:break;
            }
        break;

        case noreste:
        case noroeste: 
        case sureste:
        case suroeste:
            switch(posFinal){
                case 0:  
                         if(terreno[0] == 'K'){
                            bikini = true;
                         }else if(terreno[0] == 'D'){
                            zapatillas = true;
                         }
                         accion = actWALK;     break;
                case 1:  accion = actTURN_L;   break;
                case 2:  accion = actWALK;     break;
                case 3:  accion = actTURN_SR;  break;
                case 4:  accion = actTURN_L;   break;
                case 5:  accion = actWALK;     break;
                case 6:  accion = actWALK;     break;
                case 7:  accion = actWALK;     break;
                case 8:  accion = actTURN_SR;  break;
                case 9:  accion = actTURN_L;   break;
                case 10: accion = actTURN_L;   break;
                case 11: accion = actWALK;     break;
                case 12: accion = actWALK;     break;
                case 13: accion = actWALK;     break;
                case 14: accion = actWALK;     break; 
                case 15: accion = actTURN_SR;  break;
                default:break;
            }
        break;   
    }
    return accion;
}

//Función que reinicia el valor de todas las variables de estado del robot en caso de que haya "muerto"
void ComportamientoJugador::reiniciar(){
    current_state.fil = 99;
      current_state.col = 99;
      current_state.brujula=norte;
      last_action = actIDLE;
      girar_derecha = false;
      bien_situado = false; 
      bikini = false;
      zapatillas = false; 
      precipicios = false;
      num_walks = 0;
      saliendo_cuadrado = false;
      pasos_salida = 0;
      movimientos_guardados.clear();
}

//Función que ya venía
int ComportamientoJugador::interact(Action accion, int valor){return false;}

//Función que define el comportamiento del robot
Action ComportamientoJugador::think(Sensores sensores){

	Action accion = actIDLE;
	int a; 

    if(!precipicios){pintaPrecipio(mapaResultado);precipicios = true;}
    if(sensores.reset) reiniciar();

	switch (last_action){
		case actWALK:
        num_walks++;
        num_turns = 0;
		switch (current_state.brujula){
            case norte: current_state.fil--; break;
            case noreste: current_state.fil--; current_state.col++; break;
            case este: current_state.col++; break;
            case sureste: current_state.fil++; current_state.col++; break;
            case sur: current_state.fil++; break;
            case suroeste:current_state.fil++; current_state.col--; break;
            case oeste: current_state.col--; break;
            case noroeste:current_state.fil--; current_state.col--; break;

        } 
		break;
		case actRUN:
		break;
		case actTURN_SR:
        num_walks=0;
        num_turns++;
		a = current_state.brujula;
		a = (a+1)%8;
		current_state.brujula = static_cast<Orientacion>(a);
		break;
		case actTURN_L:
        num_walks=0;
        num_turns++;
		a = current_state.brujula;
		a = (a+6)%8;
		current_state.brujula = static_cast<Orientacion>(a);
		break;
		case actIDLE:
		break;
		}

    if(sensores.nivel==0 or (sensores.terreno[0]=='G' and !bien_situado)){
		current_state.fil = sensores.posF;
		current_state.col= sensores.posC;
		current_state.brujula = sensores.sentido;			
		bien_situado = true;
	}

    rodeadoA(sensores.terreno);
    rodeadoB(sensores.terreno);

    if(bien_situado){PonerTerrenoEnMatriz(sensores.terreno, current_state, mapaResultado);}

	//DECISIÓN DE LA NUEVA ACCIÓN -------------------------------------------------------------------------------------------------------------------------------------------
    
    if(hayRecarga(sensores.terreno) && sensores.bateria < 1000 && sensores.terreno[2]!='M' && sensores.terreno[2]!='P'){
        int casilla_dest = posRecarga(sensores.terreno);
        if(sensores.terreno[0] == 'X'){accion = actTURN_SR;}else{accion = acercarACasilla(sensores.terreno,current_state,casilla_dest);}

    }else if(hayZapatillas(sensores.terreno) && !zapatillas && sensores.terreno[2]!='M' && sensores.terreno[2]!='P'){
            int casilla_dest = posObjeto(sensores.terreno);
            accion = acercarACasilla(sensores.terreno,current_state,casilla_dest); 
            if(zapatillas)rodeadoBosque = false; //De esta forma permito que siga entrando el if(rodeadoAgua/rodeadoBosque) por si da la casulidad de que el objeto solo esta entre bosque/agua

    }else if(hayBikini(sensores.terreno) && !bikini && sensores.terreno[2]!='M' && sensores.terreno[2]!='P'){
            int casilla_dest = posObjeto(sensores.terreno);
            accion = acercarACasilla(sensores.terreno,current_state,casilla_dest); 
            if(bikini)rodeadoAgua = false;

    }else if(hayPosicionamiento(sensores.terreno) && !bien_situado && sensores.terreno[2]!='M' && sensores.terreno[2]!='P'){
            int casilla_dest = posPosicionamiento(sensores.terreno);
            accion = acercarACasilla(sensores.terreno,current_state,casilla_dest); 

    }else if(hayHuecoDcha(sensores.terreno) && current_state.brujula == norte){
            accion = actTURN_SR;
    }else if(hayHuecoDcha(sensores.terreno) && current_state.brujula == sur){
            accion = actTURN_SR;
    }else if(hayHuecoDcha(sensores.terreno) && current_state.brujula == este){
            accion = actTURN_SR;
    }else if(hayHuecoDcha(sensores.terreno) && current_state.brujula == oeste){
            accion = actTURN_SR;

    }else if(rodeadoAgua){
            accion = funcionamientoBasico(sensores);
            if(bikini)rodeadoAgua = false;

    }else if(rodeadoBosque){
            accion = funcionamientoBasico(sensores);
            if(zapatillas)rodeadoBosque = false;

    }else if(hayLoboCerca(sensores.agentes) && !zapatillas){
            accion = funcionamientoConLobo(sensores);
    }else if(hayLoboCerca(sensores.agentes) && !bikini){
            accion = funcionamientoConLobo(sensores);

    }else if(hayAldeanoCerca(sensores.agentes) && !zapatillas){
            accion = funcionamientoConAldeano(sensores);
    }else if(hayAldeanoCerca(sensores.agentes) && !bikini){
            accion = funcionamientoConAldeano(sensores);

	}else if((sensores.terreno[2]=='T' or sensores.terreno[2]=='S' or sensores.terreno[2]=='G' or sensores.terreno[2]=='D' or sensores.terreno[2]=='K' or 
            (sensores.terreno[2]=='B' and zapatillas) or (sensores.terreno[2]=='A' and bikini)) and sensores.agentes[2]=='_' and sensores.terreno[2] != 'P' 
            and sensores.terreno[2] != 'M' and num_walks<=10){
            accion = actWALK;
        
	}else if(!girar_derecha){
		    accion = actTURN_L;
		    girar_derecha = (rand()%2==0);
	}else{
		    accion = actTURN_SR;
		    girar_derecha = (rand()%2==0);
	}
	muestraSensores(sensores);
	last_action=accion;
	return accion;
}