#include <stdio.h>
void fibonacci(int n) {
    if (n <= 0) {
        printf("Ingrese un numero mayor que 0.\n");
        return;
    }
    int a = 0, b = 1;
    printf("Sucesion de Fibonacci (%d terminos): ", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", a);
        int c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}
int main() {
    printf("Ingrese el numero de terminos: ");
    int terminos;
    scanf("%d", &terminos);
    fibonacci(terminos);
    return 0;
}
