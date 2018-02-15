#include "mympi.h"

float main () { 
  
  float sum = val;
  
  float recvBuffer; //space for incoming values

  //start with all ranks active
  int Narice = size;

  while (Nactive > 1) {

    if (rank >= Nactive / 2)  {
      //MPI_send to rank - Nactive / 2
      int destRank = rank - Nactive / 2;
      int tag = Nactive; 

      MPI_Send(&val,
                1,
		MPI_FLOAT,
		destRank,
		tag,
		MPI_COMM_WORLD);	
}
