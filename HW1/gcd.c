#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int GCD(int a, int b) {

  if (b == 0) {
    return a;
  } 
  else {
    return GCD(b, a % b);
  }
}

void main() {

  int a, b, gcd;
  
  printf("Enter the first number:");
  scanf("%d", &a);
  printf("Enter the second number:");
  scanf("%d", &b); 
  gcd = GCD(a,b);  
  printf("The greatest common divisor of %d and %d is %d \n", a, b, gcd);
}
