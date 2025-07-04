#include <stdio.h>
#define MAX 100
//RF1: El sistema debe permitir ingresar una matriz cuadrada de tamaño.
//RF2: El sistema debe recorrer la matriz desde la última fila a la primera.
//RF3: Dentro de cada fila, debe recorrer los elementos desde la última columna a la primera
//RF4: El sistema debe mostrar cada elemento de la matriz en ese orden inverso.
// *Funciones
void llenar(int n, int m[MAX][MAX]);
void ver(int n, int m[MAX][MAX]);
void verInv(int n, int m[MAX][MAX]);

int main() {
    int n;
    int m[MAX][MAX];
    printf("Ingrese el tamano N de la matriz (N x N): ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
        printf("Tamano invalido. Debe estar entre 1 y %d.\n", MAX);
        return 1;
    }

    llenar(n, m);
//*RF4
    printf("\nMatriz original:\n");
    ver(n, m);

    printf("\nMatriz en orden inverso:\n");
    verInv(n, m);

    return 0;
}

// *RF1
void llenar(int n, int m[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Ingrese el elemento [%d, %d]: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
}

void ver(int n, int m[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

// *RF2
void verInv(int n, int m[MAX][MAX]) {
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

