#include <math.h>
#include <stdio.h>
#include <stdlib.h>
 
void main() {

  int n;
  
  printf("Enter a number:");
  scanf("%d", &n);

  if (n == 2 || n == 3) {
    printf("%d is prime.\n", n);
  }
  else if (n == 1 || n % 2 == 0 || n % 3 == 0) {
    printf("%d is not prime.\n", n);
  }
  else { 
    printf("%d is prime.\n", n);
  }
}
