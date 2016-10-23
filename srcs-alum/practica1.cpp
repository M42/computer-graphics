// *********************************************************************
// **
// ** Informática Gráfica, curso 2016-17
// ** Práctica 1  (implementación)
// **
// *********************************************************************

#include "practicas.hpp"
#include "practica1.hpp"
#include <vector>

// ---------------------------------------------------------------------
// declaraciones de estructuras de datos....
unsigned objeto_activo1 = 0; // objeto activo: cubo (0), tetraedro (1), otros....
std::vector<MallaInd> objetos1;

// ---------------------------------------------------------------------
// declaraciones del cubo y el tetraedro
Cubo::Cubo() {
  // Nombra el objeto
  nombre_objeto = "Cubo creado";

  // Añade los vértices al cubo
  for (int i=0; i<8; i++)
    vertices.push_back(Tupla3i(i/4,(i/2)%2,i%2));

  // Añade las caras del cubo
  // x = 0
  caras.push_back(Tupla3i(0,1,3));
  caras.push_back(Tupla3i(0,2,3));
  // x = 1
  caras.push_back(Tupla3i(4,5,7));
  caras.push_back(Tupla3i(4,6,7));
  // y = 0
  caras.push_back(Tupla3i(0,1,5));
  caras.push_back(Tupla3i(0,4,5));
  // y = 1
  caras.push_back(Tupla3i(2,3,7));
  caras.push_back(Tupla3i(2,6,7));
  // z = 0
  caras.push_back(Tupla3i(0,2,6));
  caras.push_back(Tupla3i(0,4,6));
  // z = 1
  caras.push_back(Tupla3i(1,3,7));
  caras.push_back(Tupla3i(1,5,7));
};

Tetraedro::Tetraedro() {
  // Nombra el objeto
  nombre_objeto = "Tetraedro creado";

  // Añade los vértices del tetraedro
  // Es un tetraedro inscrito en un cubo con lado 2*sqrt(2)
  vertices.push_back(Tupla3i(+1,+1,+1));
  vertices.push_back(Tupla3i(-1,-1,+1));
  vertices.push_back(Tupla3i(-1,+1,-1));
  vertices.push_back(Tupla3i(+1,-1,-1));

  // Caras del tetraedro
  caras.push_back(Tupla3i(0,1,2));
  caras.push_back(Tupla3i(0,1,3));
  caras.push_back(Tupla3i(0,2,3));
  caras.push_back(Tupla3i(1,2,3));
};

// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e
// incializado OpenGL.
void P1_Inicializar(int argc, char *argv[]) {
  // Crea los objetos
  objetos1.push_back(Cubo());
  objetos1.push_back(Tetraedro());
}

// ---------------------------------------------------------------------
// Función invocada al pulsar una tecla con la práctica 1 activa:
// (si la tecla no se procesa en el 'main').
//
//  - devuelve 'true' si la tecla se usa en esta práctica para cambiar
//    entre el cubo, el tetraedro u otros objetos (cambia el valor de
//    'objeto_activo').
//  - devuelve 'false' si la tecla no se usa en esta práctica (no ha
//    cambiado nada)
bool P1_FGE_PulsarTeclaNormal(unsigned char tecla) {
  // Teclas o/O para cambiar objeto.
  if (tecla == 'o' or tecla == 'O') {
    objeto_activo1++;
    objeto_activo1 %= objetos1.size();
    return true;
  }

  // Devuelve false si la tecla no se usa.
  return false;
}


// ---------------------------------------------------------------------
// Función a implementar en la práctica 1  para dibujar los objetos
// se debe de usar el modo de dibujo que hay en el parámetro 'cv'
// (se accede con 'cv.modoVisu')
void P1_DibujarObjetos(ContextoVis& cv) {
  objetos1[objeto_activo1].visualizar(cv);
}
