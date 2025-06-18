#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARREGLO_MAX 10
int main() {
    int n;
    int i, j;
    int fila_i, fila_j;
    int temp;
    int mat[ARREGLO_MAX][ARREGLO_MAX];
    srand(time(NULL)); // Inicializa la semilla de números aleatorios
    printf("Bienvenidos al programa que intercambia filas de la matriz\n\n");
    printf("Ingrese el tamano de la matriz cuadrada (maximo %d): ", ARREGLO_MAX);
    scanf("%d", &n);

    if (n <= 0 || n > ARREGLO_MAX) {
        printf("Tamano no valido. Debe ser entre 1 y %d.\n", ARREGLO_MAX);
        return 1;
    }
    // Llenar la matriz con valores aleatorios entre 1 y 99
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            mat[i][j] = rand() % 99 + 1;
        }
    }
    // Mostrar matriz original
    printf("\nMatriz original generada aleatoriamente:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
    // Pedir filas a intercambiar (desde 1 para el usuario)
    printf("\nIngrese el numero de la fila i a intercambiar (1 a %d): ", n);
    scanf("%d", &fila_i);
    printf("Ingrese el numero de la fila j a intercambiar (1 a %d): ", n);
    scanf("%d", &fila_j);
    // Ajustar a base 0
    fila_i--;
    fila_j--;
    if (fila_i < 0 || fila_i >= n || fila_j < 0 || fila_j >= n) {
        printf("Indices de fila no validos.\n");
        return 1;
    }
    if (fila_i == fila_j) {
        printf("Las filas son iguales. No se realizo ningun intercambio.\n");
        return 0;
    }
    // Intercambiar las filas
    for (j = 0; j < n; j++) {
        temp = mat[fila_i][j];
        mat[fila_i][j] = mat[fila_j][j];
        mat[fila_j][j] = temp;
    }
    // Mostrar matriz modificada
    printf("\nMatriz modificada tras intercambiar filas %d y %d:\n", fila_i + 1, fila_j + 1);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
//NRC: #20823_G8_FP
//Colaboradores
//Astudillo Adriana
//Muñoz Sarahi
//Nero Alan
