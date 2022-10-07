#include "project.h"
#include <stdio.h>

static void print_board(adj_t matrix) {
  char board[(NVERTEX + 1) * NVERTEX + 1];
  board[(NVERTEX + 1) * NVERTEX] = '\0';
  for (unsigned y = NVERTEX; y--;) {
    board[y * (NVERTEX + 1) + NVERTEX] = '\n';
    for (unsigned x = NVERTEX; x--;) {
      board[y * (NVERTEX + 1) + x] = get_edge(matrix, x, y) ? '1' : '0';
    }
  }
  puts(board);
}

static bool validate(void) {
  adj_t matrix = (1L << (NVERTEX * NVERTEX)) - 1;
  do {
    unsigned naive = naive_solution(matrix);
    unsigned fastest = fastest_solution(matrix);
    if (naive != fastest) {
      print_board(matrix);
      printf("%lu %d %d\n", matrix, naive, fastest);
      return false;
    }
  } while (matrix--);
  return true;
}

int main(void) {
  if (validate()) {
    puts("Success");
    return 0;
  }
  puts("Failure");
  return 1;
}
