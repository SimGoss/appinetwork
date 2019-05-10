#include "../sources/tfit.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv)
{
  // Adjacency matrix of graph.gr
  int sA[18][18] = {
    { 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0 },
    { 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
    { 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0 },
    { 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0 },
    { 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0 },
    { 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  };
  int N = 18;

  // graph6.gr (very simple graph)
//  int sA[6][6] = {
//    { 0, 1, 1, 1, 0, 0 },
//    { 1, 0, 1, 1, 0, 0 },
//    { 1, 1, 0, 1, 0, 0 },
//    { 1, 1, 1, 0, 0, 0 },
//    { 0, 0, 0, 0, 0, 1 },
//    { 0, 0, 0, 0, 1, 0 }
//  };
//  int N = 6;

  int* P = malloc(N*sizeof(int));
  // https://stackoverflow.com/questions/3911400/how-to-pass-2d-array-matrix-in-a-function-in-c
  int** A = malloc(N*sizeof(int*));
  for (int i=0; i<N; i++)
  {
    A[i] = malloc(N*sizeof(int));
    for (int j=0; j<N; j++)
      A[i][j] = sA[i][j];
  }
  tfit_core(A, N, P);
  for (int i=0; i<N; i++)
    printf("%i ", P[i]);
  printf("\n");
  free(P);
  for (int i=0; i<N; i++)
    free(A[i]);
  free(A);
  return 0;
}
