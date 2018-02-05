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

int LCM(int a, int b) {

  return (a*b)/GCD(a, b);

}
void main() {

  int a, b, lcm;
  
  printf("Enter the first number:");
  scanf("%d", &a);
  printf("Enter the second number:");
  scanf("%d", &b); 
  lcm = LCM(a,b);  
  printf("The least common multiple of %d and %d is %d \n", a, b, lcm);
}
