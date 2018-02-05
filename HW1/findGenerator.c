#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main() {

  int p, g, r;
  printf("Enter a prime number:");
  scanf("%d", &p);
  
  if (p == 2 || p == 3) {
    for (int i = 1; i < p; i++) {
      while (r < p - 1) {
        if ((int)pow(i,r) % p == 1) {
          i = i+1;
          break;
        }
        else {
          r + 1; 
        } 
      }
      if (i == p) {
         g = i - 1;
         break;
      }
      else {
         g = i;
         break;
      }
    }
    printf("%d is a generator of Z_%d \n",g,p);
  }
  else if (p == 1 || p % 2 == 0 || p % 3 == 0) {
    printf("Error: %d is not a prime number \n", p);
  } 
  else {
    for (int i = 1; i < p; i++) {
      while (r < p - 1) {
        if ((int)pow(i,r) % p == 1) {
          i = i+1; 
          break;
        }
        else {
          r + 1; 
        } 
      }
      if (i == p) {
         g = i - 1;
         break;
      }
      else {
         g = i;
         break;
      }
    } 
    printf("%d is a generator of Z_%d \n",g,p);
  }
}
