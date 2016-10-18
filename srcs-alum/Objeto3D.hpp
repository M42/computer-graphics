#include<string>
#include "practicas.hpp"

class Objeto3D {
protected:
  std::string nombre_objeto;
public:
  std::string nombre();
  virtual void visualizarGL(ContextoVis& cv) = 0;
};
