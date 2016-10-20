#ifndef MALLAIND
#define MALLAIND

#include "Objeto3D.hpp"
#include "tuplasg.hpp"
#include <vector>

// Mallas indexadas
class MallaInd : public Objeto3D {
protected:
  std::vector<Tupla3d> vertices;
public:
  // Visualización de la malla
  virtual void visualizarGL(ContextoVis& cv);
};

#endif
