#include <stdio.h>
#define ARREGLO_MAX 10
//Requisitos funcionales para el programa:
//Generar una matriz cuadrada de n<=10.
//Llenar la matriz con valores ingresados por el usuario.
//Solicita las filas a intercambiar.
//Imprime la matriz original y la matriz intercambiada
int main() {
    int n;
    int i, j;
    int fila_i, fila_j;
    int temp;
    int mat[ARREGLO_MAX][ARREGLO_MAX];
    printf("Bienvenidos al programa que intercambia filas de la matriz\n\n");
    printf("Ingrese el tamano de la matriz cuadrada (max 10): ", ARREGLO_MAX);
    scanf("%d", &n);

    if (n <= 0 || n > ARREGLO_MAX) {
        printf("Tamaño de matriz no válido.\n");
        return 1;
    }

    printf("Ingrese los elementos de la matriz:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("Matriz original:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    printf("Ingrese el indice de la fila i: ");
    scanf("%d", &fila_i);
    printf("Ingrese el indice de la fila j: ");
    scanf("%d", &fila_j);

    if (fila_i < 0 || fila_i >= n || fila_j < 0 || fila_j >= n) {
        printf("Indices de fila no validos.\n");
        return 1;
    }

    for (j = 0; j < n; j++) {
        temp = mat[fila_i][j];
        mat[fila_i][j] = mat[fila_j][j];
        mat[fila_j][j] = temp;
    }

    printf("Matriz modificada:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
