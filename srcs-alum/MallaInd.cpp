#include "MallaInd.hpp"

void MallaInd::visualizar(ContextoVis& cv) {
  // Prepara el array de vértices e indica sobre él la
  // posición inicial y el sentido que llevará.
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_INT, 0, vertices[0]);

  // Dibuja el array de vértices indicando los índices de los
  // triángulos que se dibujarán. Esto es más eficiente que repetir
  // varias veces un mismo punto (glDrawArrays) y que realizar una
  // llamada por vértice (glVertex).
  glDrawElements(GL_TRIANGLES, caras.size()*3, GL_UNSIGNED_INT, caras[0]);

  // Deja de usar el array de vértices.
  glDisableClientState(GL_VERTEX_ARRAY);
}
