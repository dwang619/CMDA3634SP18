#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main() {
  
  //arhc holds the number of arguments sent to the command line when the prigram was run
  //argv is an array of strings which are the arguments themselves 

  //to see this let's print everything out
  for (int n = 0; n < argc; n++) {
    printf("The %d-th argument was %s\n". n, argv[n]);
  }  

  return 0;
}
