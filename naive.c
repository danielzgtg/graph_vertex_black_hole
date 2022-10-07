#include "project.h"

unsigned naive_solution(adj_t matrix) {
  for (unsigned i = NVERTEX; i--;) {
    if (vertex_accepts(matrix, i)) {
      return i;
    }
  }
  return ~0;
}
