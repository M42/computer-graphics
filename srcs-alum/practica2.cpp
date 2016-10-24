// *********************************************************************
// **
// ** Informática Gráfica, curso 2016-17
// ** Práctica 2  (implementación)
// **
// *********************************************************************

#include "practica2.hpp"
#include "MallaPLY.hpp"
#include "MallaRevol.hpp"
#include <string>

unsigned objeto_activo2 = 0;
const unsigned num_objetos = 3;
static MallaPLY* oply = NULL;
static MallaRevol* revol = NULL;
static MallaPLY* beethoven = NULL;

void P2_Inicializar(int argc, char* argv[]) {
  // Lee los nombres de los archivos desde el comando de terminal
  // con la sintaxis siguiente:
  //  <archivo PLY> <archivo PLY revolución> <número de perfiles>
  // En caso de error toma parámetros por defecto
  std::string archivo_ply;
  std::string archivo_revol;
  std::string archivo_beethoven;
  unsigned nperfiles;
  
  // Lectura de parámetros
  if (argc == 6) {
    archivo_ply = argv[2];
    archivo_revol = argv[3];
    nperfiles = atoi(argv[4]);
    archivo_beethoven = argv[5];
  }

  // Parámetros por defecto
  else {
    archivo_ply = "../plys/ant.ply";
    archivo_revol = "../plys/peon.ply";
    archivo_beethoven = "../plys/beethoven.ply";
    nperfiles = 20;
  }

  // Genera los objetos como mallas leyendo del archivo
  // PLY que se ha obtenido anteriormente
  oply = new MallaPLY(archivo_ply);
  revol = new MallaRevol(archivo_revol, nperfiles, true, true);
  beethoven = new MallaPLY(archivo_beethoven);
}

// Redibuja los objetos de la práctica 2.
// Esta función es llamada desde main.cpp cada vez
// que se necesita redibujar un objeto.
void P2_DibujarObjetos(ContextoVis& cv) {
  if (objeto_activo2 == 0)
    oply->visualizar(cv);
  else if (objeto_activo2 == 1)
    revol->visualizar(cv);
  else
    beethoven->visualizar(cv);
}

// Calcula una acción cada vez que se pulsa una
// tecla en la práctica 2. Esta función es llamada desde
// main.cpp.
bool P2_FGE_PulsarTeclaNormal(unsigned char tecla) {
  if (tecla == 'o' or tecla == 'O') {
    objeto_activo2++;
    objeto_activo2%=num_objetos;
    return true;
  }

  return false;
}
