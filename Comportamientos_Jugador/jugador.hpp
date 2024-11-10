#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"
using namespace std;

struct state{
int fil;
int col;
Orientacion brujula;
};

class ComportamientoJugador : public Comportamiento{

  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size){
     
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
      num_turns = 0;
      saliendo_cuadrado = false;
      pasos_salida = 0;
      rodeadoAgua = false;
      rodeadoBosque = false;
      
    }
      

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);
    Action acercarACasilla(const vector<unsigned char> & terreno, const state &st, int posFinal);
    void dentroCuadrado(const vector<unsigned char> & terreno, const state &st);
    void reiniciar();
    bool pasoEntreMuros(const vector<unsigned char> & terreno);
    void rodeadoA(const vector<unsigned char> & terreno);
    void rodeadoB(const vector<unsigned char> & terreno);
    Action funcionamientoBasico(Sensores sensores);
    Action funcionamientoConLobo(Sensores sensores);
    Action funcionamientoConAldeano(Sensores sensores);
    
    
    

  private:
  // Declarar aquí las variables de estado
  state current_state;
  Action last_action; 
  bool girar_derecha;
  bool bien_situado;
  bool bikini;
  bool zapatillas;
  bool precipicios;
  int num_walks;
  int num_turns;
  bool saliendo_cuadrado;
  int pasos_salida;
  bool rodeadoAgua; //A true si al aparecer esta rodeado de agua. Se pone a false cuando ya haya encontrado el bikini
  bool rodeadoBosque; //A true si al aparecer esta rodeado de bosque. Se pone a false cuando ya haya las zapatillas
  
  std::vector<Action> movimientos_guardados;
  
};
#endif
