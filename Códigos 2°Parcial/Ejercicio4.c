#include <stdio.h>
int main() {
    int i;
    int j;
    int temp;
    int vector[10];

    /* Leer los valores del vector */
    for (i = 0; i < 10; i++) {
        printf("Ingrese el valor %d: \n", i + 1);
        scanf("%d", &vector[i]);
    }

    /* Ordenar el vector */
    for (i = 0; i < 9; i++) {
        for (j = i + 1; j < 10; j++) {
            if (vector[i] < vector[j]) {
                temp = vector[i];
                vector[i] = vector[j];
                vector[j] = temp;
            }
        }
    }
    /* Imprimir el vector ordenado */
    printf("Vector ordenado: \n");
    for (i = 0; i < 10; i++) {
        printf("%d\n", vector[i]);
    }
    return 0;
}
