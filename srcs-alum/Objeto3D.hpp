#ifndef OBJETO3D
#define OBJETO3D

#include <string>
#include "practicas.hpp"

class Objeto3D {
protected:
  // Nombre interno del objeto. Puede usarse para depurar.
  std::string nombre_objeto;
public:
  // Devuelve el nombre interno del objeto.
  std::string nombre();

  // Visualiza un objeto con el modo de visualización dado.
  virtual void visualizarGL(ContextoVis& cv) = 0;
};

#endif
