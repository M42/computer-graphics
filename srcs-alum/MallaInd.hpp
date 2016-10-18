#ifndef MALLAIND
#define MALLAIND

#include "Objeto3D.hpp"
#include <vector>

class MallaInd : public Objeto3D {
protected:
public:
  // Visualización de la malla
  virtual void visualizarGL(ContextoVis& cv);
};

#endif
