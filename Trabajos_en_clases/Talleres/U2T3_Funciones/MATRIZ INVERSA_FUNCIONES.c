#include <stdio.h>

void llenarMatriz(int N, int Mat[N][N]);
void mostrarMatrizInversa(int N, int Mat[N][N]);

int main() {
    int N;

    printf("Ingrese el tamaño N de la matriz (N x N): ");
    scanf("%d", &N);

    int Mat[N][N];

    llenarMatriz(N, Mat);
    mostrarMatrizInversa(N, Mat);

    return 0;
}

void llenarMatriz(int N, int Mat[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("Ingrese el elemento [%d, %d]: ", i + 1, j + 1);
            scanf("%d", &Mat[i][j]);
        }
    }
}

void mostrarMatrizInversa(int N, int Mat[N][N]) {
    int i, j;
    printf("Matriz en orden inverso:\n");
    for (i = N - 1; i >= 0; i--) {
        for (j = N - 1; j >= 0; j--) {
            printf("%d ", Mat[i][j]);
        }
        printf("\n");
    }
}
//NRC: #20823_G8_FP
//Colaboradores
//Astudillo Adriana
//Muñoz Sarahi
//Nero Alan

