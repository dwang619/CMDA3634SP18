#iclude <stdio.h>
#include <stdlib.h>
#include<math.h>

#include "mympi.h"

int main (int argc, char **argv) {

  MPI_Init(&argc, &argv);
   
  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  int N;
  
  if (rank == 0) N = 199; //only rank 0 fills a value

  // myMPI_Bcast(&N, 0);
  treeMPI_Bcast(&N);
  printf("Rank %d received the value N = %d\n", rank, N);
  
  if (rank == size - 1) N = 10;
  
  myMPI_Bcast(&N, 0) ;
  printf("Rank %d received the value N = %d\n", rank, N);

  MPI_Barrier();
  MPI_Finalize();
  return 0;
}
