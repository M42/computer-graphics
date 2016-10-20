// *********************************************************************
// **
// ** Informática Gráfica, curso 2016-17
// ** Práctica 1  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practicas.hpp"
#include "practica1.hpp"

unsigned objeto_activo = 0 ; // objeto activo: cubo (0), tetraedro (1), otros....

// ---------------------------------------------------------------------
// declaraciones de estructuras de datos....

// ---------------------------------------------------------------------
// declaraciones del cubo y el tetraedro
Cubo::Cubo() {
  // Nombra el objeto
  nombre_objeto = "Cubo creado";

  // Añade los vértices al cubo
  // TODO: Reescribir en binario
  vertices.push_back(Tupla3i(0,0,0));
  vertices.push_back(Tupla3i(0,0,1));
  vertices.push_back(Tupla3i(0,1,0));
  vertices.push_back(Tupla3i(0,1,1));
  vertices.push_back(Tupla3i(1,0,0));
  vertices.push_back(Tupla3i(1,0,1));
  vertices.push_back(Tupla3i(1,1,0));
  vertices.push_back(Tupla3i(1,1,1));

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

void P1_Inicializar( int argc, char *argv[] )
{


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

bool P1_FGE_PulsarTeclaNormal( unsigned char tecla )
{
   // ........
   return false ;
}


// ---------------------------------------------------------------------
// Función a implementar en la práctica 1  para dibujar los objetos
// se debe de usar el modo de dibujo que hay en el parámetro 'cv'
// (se accede con 'cv.modoVisu')

void P1_DibujarObjetos( ContextoVis & cv )
{


}
