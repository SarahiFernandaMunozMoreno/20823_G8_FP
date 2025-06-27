#include <stdio.h>
void fibonacci(int num) {
  int a=0, b=1, c, i;
  printf("Serie de Fibonacci:\n");
  for (i=0; i<num; i++) {
    if (i<=1) {
      c=i;
    } else {
      c=a+b;
      a=b;
      b=c;
    }
    printf("%d ",c);
  }
  printf("\n");
}
int main() {
  int num;
  printf("Ingrese el numero de terminos de la serie de Fibonacci: ");
  scanf("%d", &num);
  fibonacci(num);
  return 0;
}
