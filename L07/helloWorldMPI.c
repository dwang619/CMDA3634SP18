#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "mpi.h"

int main(int argc, char** argv) {

  //every MPI program must start with an initialize
  //always do this first
  MPI_Init(&argc, &argv);

  printf("Hello World!\n");

  // all MPI programs must end with a finalize 
  MPI_Finalize();
  return 0; 
}
