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
 
  if (gcd == 1) {    
    printf("%d and %d are coprime \n", a, b);
  }  
  else {
    printf("%d and %d are not coprime \n",a, b);
  }
}
