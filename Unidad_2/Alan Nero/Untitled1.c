#include <stdio.h>
int main() {
    int vector[10];
    int i;
    int suma = 0;
    for (i = 0; i < 10; i++) {
        printf("Ingresa los numeros que quieres los cuadrados %d: ", i + 1);
        scanf("%d", &vector[i]);
    }
    for (i = 0; i < 10; i++) {
        vector[i] = vector[i] * vector[i];
        suma += vector[i];
    }
    printf("Los cuadrados son:\n");
    for (i = 0; i < 10; i++) {
        printf("%d\n", vector[i]);
    }
    printf("La suma de los cuadrados es: %d\n", suma);
    return 0;
}
