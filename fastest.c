#include "project.h"

unsigned fastest_solution(adj_t matrix) {
  unsigned candidate = 0;
  unsigned challenger = 0;
  while (++challenger < NVERTEX) {
    bool candidate2challenger = get_edge(matrix, challenger, candidate);
    bool challenger2candidate = get_edge(matrix, candidate, challenger);
    if (candidate2challenger == challenger2candidate) {
      candidate = ++challenger;
      continue;
    }
    if (challenger2candidate)
      continue;
    candidate = challenger;
  }
  if (candidate >= NVERTEX || !vertex_accepts(matrix, candidate))
    return ~0;
  return candidate;
}
