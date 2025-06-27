#include <stdio.h>

float division(float a, float b) {

    return a / b;
}

int main() {
    float numerador, denominador, cociente;

    printf("Ingrese el numerador: ");
    scanf("%f", &numerador);
    printf("Ingrese el denominador: ");
    scanf("%f", &denominador);

    cociente = division(numerador, denominador);
    printf("Cociente: %.2f\n", cociente);

    return 0;
}
