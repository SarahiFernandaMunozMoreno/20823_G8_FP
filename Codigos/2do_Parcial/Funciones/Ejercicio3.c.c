#include <stdio.h>
#define ARREGLO_MAX 10
//Requisitos funcionales para el programa:
//Generar una matriz mxn.
//Llenar la matriz con valores ingresados por el usuario.
//Solicita la fila a consultar.
//Imprime la matriz original y el valor maximo de la fila

// Declaraciones de funciones
void generarMatriz(int mat[][ARREGLO_MAX], int f, int c);
void imprimirMatriz(int mat[][ARREGLO_MAX], int f, int c);
int obtenerMaximoDeFila(int mat[][ARREGLO_MAX], int fila, int c);

int main() {
    int c, f;
    int mat[ARREGLO_MAX][ARREGLO_MAX];
    int fila_i, max;

    printf("Bienvenidos al programa que te dira el valor maximo de una fila \n\n");

    // GENERA LA MATRIZ MxN
    printf("Ingrese el numero de filas\n");
    scanf("%d", &f);
    printf("Ingrese el numero de columnas\n");
    scanf("%d", &c);

    if (f > ARREGLO_MAX || c > ARREGLO_MAX || f <= 0 || c <= 0) {
        printf("Dimensiones invalidas.\n");
        return 1;
    }

    generarMatriz(mat, f, c);
    imprimirMatriz(mat, f, c);

    // SOLICITA AL USUARIO LA FILA A CONSULTAR
    printf("\nIngrese el numero de la fila a consultar (0 a %d): ", f - 1);
    scanf("%d", &fila_i);

    if (fila_i >= 0 && fila_i < f) {
        max = obtenerMaximoDeFila(mat, fila_i, c);
        printf("El valor maximo de la fila %d es: %d\n", fila_i, max);
    } else {
        printf("Fila fuera de rango.\n");
    }

    return 0;
}

// Función para llenar la matriz con datos del usuario
void generarMatriz(int mat[][ARREGLO_MAX], int f, int c) {
    int i, j;
    printf("Ingrese los elementos de la matriz por filas:\n");
    for (i = 0; i < f; i++) {
        for (j = 0; j < c; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

// Función para imprimir la matriz
void imprimirMatriz(int mat[][ARREGLO_MAX], int f, int c) {
    int i, j;
    printf("\nMatriz original ingresada:\n");
    for (i = 0; i < f; i++) {
        for (j = 0; j < c; j++) {
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Función para obtener el valor máximo de una fila específica
int obtenerMaximoDeFila(int mat[][ARREGLO_MAX], int fila, int c) {
    int j, max = mat[fila][0];
    for (j = 1; j < c; j++) {
        if (mat[fila][j] > max) {
            max = mat[fila][j];
        }
    }
    return max;
}
//NRC: #20823_G8_FP
//Colaboradores
//Astudillo Adriana
//Muñoz Sarahi
//Nero Alan
