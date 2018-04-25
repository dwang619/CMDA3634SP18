#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "cuda.h"
#include "functions.c"

__global__ void kernelDecrypt(unsigned n, unsigned int p, unsigned int g,
			      unsigned int h, unsigned int x) {

  int threadid = threadIdx.x;
  int blockid = blockIdx.x;
  int Nblock = blockDim.x;
  
  int id = threadid + blockid*Nblock;

  // find the secret key
  if (x==0 || modExp(g,x,p)!=h) {
    printf("Finding the secret key...\n");
    double startTime = clock();
    for (unsigned int i=0;i<p-1;i++) {
      if (modExp(g,i+1,p)==h) {
        printf("Secret key found! x = %u \n", i+1);
        x=i+1;
      } 
    }
  }
}

int main (int argc, char **argv) {

  /* Part 2. Start this program by first copying the contents of the main function from 
     your completed decrypt.c main function. */ 
   
  /* Q4 Make the search for the secret key parallel on the GPU using CUDA. */
  
  //declare storage for an ElGamal cryptosytem
  unsigned int *h_x, *d_x;
  unsigned int n, p, g, h;
  unsigned int Nints;
  unsigned int N = atoi(argv[1]);

  h_x = (unsigned int *) malloc(N*sizeof(unsigned int));

  cudaMalloc(&x, N*sizeof(unsigned int));
  
  //get the secret key from the user
  printf("Enter the secret key (0 if unknown): "); fflush(stdout);
  char stat = scanf("%u",&x);

  printf("Reading file.\n");
  
  
  cudaMemory(d_x,h_x,N*sizeof(unsigned int), cudaMemcpyHostToDevice);
  
  // Read in the public key data from public_key.txt and the cyphertexts from messages.txt.
  FILE* publicKey = fopen("public_key.txt","r");
  fscanf(publicKey, "%u \n%u \n%u \n%u \n", &n, &p, &g, &h);
  fclose(publicKey);
  
  
  int Nthreads = atoi(argv[2]);
  int Nblocks= (N+Nthread-1)/Nthreads;
  
  double startTime = clock();
  
 
  kernelDecrypt <<<Nblocks , Nthreads>>>(n, p, g, h, x); 
  
  double endTime = clock();

  double totalTime = (endTime-startTime)/CLOCKS_PER_SEC;
  double work = (double) p;
  double throughput = work/totalTime;

  printf("Searching all keys took %g seconds, throughput was %g values tested per second.\n", totalTime, throughput);
 

  // After finding the secret key, decrypt the message
  FILE* msg = fopen("message.txt", "r");
  fscanf(msg, "%u\n", &Nints);
  unsigned int *m = (unsigned int *) malloc(Nints*sizeof(unsigned int));
  unsigned int *a = (unsigned int *) malloc(Nints*sizeof(unsigned int));
  for (int i = 0; i < Nints; i++) {
    fscanf(msg, "%u %u\n", &m[i], &a[i]);
  } 
  ElGamalDecrypt(m, a, Nints, p, x);

  unsigned char *message = (unsigned char *) malloc(1024*sizeof(unsigned char));
  unsigned int charsPerInt = sizeof(p) / sizeof(n);
  unsigned int Nchars = Nints * charsPerInt;
  convertZToString(m, Nints, message, Nchars);
  printf("The decrypted message is: %s\n", message);

  cudaFree(d_x);
  free(h_x); 
  return 0;
}
