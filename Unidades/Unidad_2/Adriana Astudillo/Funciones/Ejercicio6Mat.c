#include <stdio.h>
#define MAX 10
//RF1: Generar una matriz mxn.
//RF2: Llenar la matriz con valores ingresados por el usuario.
//RF3: Solicita la fila a consultar.
//RF4: Imprime la matriz original y el valor maximo de la fila
//*Funciones
void gen(int m[][MAX], int f, int c);
void imp(int m[][MAX], int f, int c);
int maxFila(int m[][MAX], int fila, int c);

int main() {
    int f, c;
    int m[MAX][MAX];
    int fila, max;

    printf("Programa para mostrar el valor maximo de una fila\n\n");
//*RF1: el usuario escoge la dimención
    printf("Ingrese numero de filas: ");
    scanf("%d", &f);
    printf("Ingrese numero de columnas: ");
    scanf("%d", &c);
//validación de dimención
    if (f > MAX || c > MAX || f <= 0 || c <= 0) {
        printf("Dimensiones invalidas.\n");
        return 1;
    }

    gen(m, f, c);
    imp(m, f, c);
//*RF3
    printf("\nIngrese la fila a consultar (1 a %d): ", f);
    scanf("%d", &fila);

    if (fila >= 1 && fila <= f) {
        max = maxFila(m, fila - 1, c); // Convertir a índice 0
        printf("El valor maximo de la fila %d es: %d\n", fila, max);
    } else {
        printf("Fila fuera de rango.\n");
    }

    return 0;
}
//*RF2: pide los elementos
void gen(int m[][MAX], int f, int c) {
    int i, j;
    printf("Ingrese los elementos de la matriz por filas:\n");
    for (i = 0; i < f; i++) {
        for (j = 0; j < c; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}
//*RF4: imprime la matriz
void imp(int m[][MAX], int f, int c) {
    int i, j;
    printf("\nMatriz ingresada:\n");
    for (i = 0; i < f; i++) {
        for (j = 0; j < c; j++) {
            printf("%3d ", m[i][j]);
        }
        printf("\n");
    }
}

int maxFila(int m[][MAX], int fila, int c) {
    int j, max = m[fila][0];
    for (j = 1; j < c; j++) {
        if (m[fila][j] > max) {
            max = m[fila][j];
        }
    }
    return max;
}
