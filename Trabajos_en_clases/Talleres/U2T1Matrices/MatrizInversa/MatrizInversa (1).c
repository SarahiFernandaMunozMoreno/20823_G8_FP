#include <stdio.h>

int main() {
    int N, i, j;

    // Solicitar tamaño de la matriz
    printf("Ingrese el tamano N de la matriz (N x N): ");
    scanf("%d", &N);

    // Declarar la matriz
    int Mat[N][N];

    // Llenado de la matriz
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("Ingrese el elemento [%d, %d]: ", i + 1, j + 1);
            scanf("%d", &Mat[i][j]);
        }
    }

    // Mostrar la matriz en orden inverso
    printf("Matriz en orden inverso:\n");
    for (i = N - 1; i >= 0; i--) {
        for (j = N - 1; j >= 0; j--) {
            printf("%d ", Mat[i][j]);
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

