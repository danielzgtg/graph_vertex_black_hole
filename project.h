#pragma once

#include <stdbool.h>
#include <stdint.h>

/// Number of vertices
#define NVERTEX 5
// Setting this to 6 takes more than 10 minutes

/**
 * Adjacency matrix type. The diagonal is undefined.
 * Must have NVERTEX**2 bits. x is in; y is out.
 */
#define adj_t uint64_t

/// Returns whether the specified edge is present
static inline bool get_edge(adj_t matrix, unsigned x, unsigned y) {
  return matrix & 1 << (y * NVERTEX + x);
}

/// Checks whether the specified vertex is a black hole in the graph
static inline bool vertex_accepts(adj_t matrix, unsigned i) {
  for (unsigned x = NVERTEX; x--;) {
    if (x != i && get_edge(matrix, x, i))
      return false;
  }
  for (unsigned y = NVERTEX; y--;) {
    if (y != i && !get_edge(matrix, i, y))
      return false;
  }
  return true;
}

/// Check if the graph has a black hole using the naive strategy
unsigned naive_solution(adj_t);

/// Check if the graph has a black hole using the fastest strategy
unsigned fastest_solution(adj_t);
