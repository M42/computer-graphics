#include "MallaRevol.hpp"
#include <cmath>

MallaRevol::MallaRevol(const std::string& nombre_archivo,
		       const unsigned nperfiles,
		       const bool crear_tapas,
		       const bool cerrar_malla) {
  // Extrae los puntos para generar los vértices.
  std::vector<float> plyv;
  ply::read_vertices(nombre_archivo.c_str(), plyv);
  int vnum = plyv.size()/3;

  // La figura de revolución se extrae generando un número determinado
  // de perfiles, cada uno de ellos a distinto ángulo. Estos perfiles
  // serán unidos por caras que se añadirán uniendo cada perfil con el
  // siguiente
  for (unsigned j=0; j<=nperfiles; ++j) {
    // Genera el ángulo al que va a colocar el perfil
    double angulo = j*2*M_PI/nperfiles;
    double cosp = cos(angulo);
    double senp = sin(angulo);

    // Añade cada vértice del perfil
    for (int i=0; i<vnum; i++) {
      // Calcula el vértice aplicando una rotacíón
      float nx = cosp*plyv[i*3]-senp*plyv[i*3+2];
      float ny = plyv[i*3+1];
      float nz = cosp*plyv[i*3]+senp*plyv[i*3+2];
      vertices.push_back(Tupla3f(nx,ny,nz));

      // Une el perfil con el siguiente mediante dos triángulos
      // que se unen formando una cara con el siguiente vértice.
      // Esta operación no es necesaria para el primer vértice ni
      // para la última cara.
      if (i!=0 and j!=nperfiles) {
	// Primer triángulo
	int ua = j*vnum + i;
	int ub = ua+vnum;
	int uc = ua-1;
	caras.push_back(Tupla3i(ua,ub,uc));
	
	// Segundo triángulo
	int va = uc;
	int vb = ub;
	int vc = uc-1;
	caras.push_back(Tupla3i(va,vb,vc));
      }
    }
  }
}
