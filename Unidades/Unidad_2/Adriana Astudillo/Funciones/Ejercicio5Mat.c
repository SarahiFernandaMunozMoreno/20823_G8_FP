#include <stdio.h>
#define MAX 100

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

    printf("\nMatriz original:\n");
    ver(n, m);

    printf("\nMatriz en orden inverso:\n");
    verInv(n, m);

    return 0;
}

// *RF1:Llena la matriz con datos del usuario
void llenar(int n, int m[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Ingrese el elemento [%d, %d]: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
}

//*RF2: Muestra la matriz original
void ver(int n, int m[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

// *RF3:Muestra la matriz inversa
void verInv(int n, int m[MAX][MAX]) {
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

