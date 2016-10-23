#include "MallaPLY.hpp"

MallaPLY::MallaPLY(const std::string& nombre_archivo) {
  // Extrae los puntos para generar los vértices y las caras
  // desde el archivo PLY pasado como argumento.
  std::vector<float> plyv;
  std::vector<int> plyc;
  ply::read(nombre_archivo.c_str(), plyv, plyc);

  // Genera la malla organizando los puntos leídos en tuplas
  // Organiza los vértices
  for (unsigned i=0; i<plyv.size()/3; i++) {
    Tupla3f vertice = Tupla3f(plyv[i*3],plyv[i*3+1],plyv[i*3+2]);
    vertices.push_back(vertice);
  }

  // Organiza las caras
  for (unsigned i=0; i<plyc.size()/3; i++) {
    Tupla3i cara = Tupla3i(plyc[i*3],plyc[i*3+1],plyc[i*3+2]);
    caras.push_back(cara);
  }
}
