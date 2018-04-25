#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "functions.h"

int main (int argc, char **argv) {

	//seed value for the randomizer 
  double seed = clock(); //this will make your program run differently everytime
  //double seed = 0; //uncomment this and your program will behave the same everytime it's run

  srand(seed);

  int bufferSize = 1024;
  unsigned char *message = (unsigned char *) malloc(bufferSize*sizeof(unsigned char));

  printf("Enter a message to encrypt: ");
  int stat = scanf (" %[^\n]%*c", message); //reads in a full line from terminal, including spaces

  //declare storage for an ElGamal cryptosytem
  unsigned int n, p, g, h;

  printf("Reading file.\n");

  /* Q2 Complete this function. Read in the public key data from public_key.txt,
    convert the string to elements of Z_p, encrypt them, and write the cyphertexts to 
    message.txt */
  FILE* publicKey = fopen("public_key.txt","r");
  fscanf(publicKey, "%u \n%u \n%u \n%u \n",&n, &p, &g, &h);
  fclose(publicKey);
 
  unsigned int charsPerInt = sizeof(p) / sizeof(n);
  unsigned int Nchars = strlen(message);
  unsigned int Nints = strlen(message) / charsPerInt;
  unsigned int *Z = (unsigned int *) malloc(Nints*sizeof(unsigned int));
  unsigned int *a = (unsigned int *) malloc(Nints*sizeof(unsigned int));
  convertStringToZ(message, Nchars, Z, Nints);
  ElGamalEncrypt(Z, a, Nints, p, g, h);
  
  FILE* m = fopen("message.txt", "w");
  for (int i = 0; i < Nints; i++) {
    if (i == 0) {
      fprintf(m, "%d \n", Nints);
    }
      fprintf(m, "%d %d\n", Z[i], a[i]);
  } 
  fclose(m);

  return 0;
}
