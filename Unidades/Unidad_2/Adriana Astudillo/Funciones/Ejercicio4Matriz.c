#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

// *RF1:Declaración de funciones
void gen(int m[MAX][MAX], int n);
void ver(int m[MAX][MAX], int n);
void swap(int m[MAX][MAX], int n, int f1, int f2);
int valido(int n);
int pedirFila(const char* msg, int max);

int main() {
    srand(time(NULL));  // Inicializa números aleatorios

    int n;
    int m[MAX][MAX];

    printf("Tamano de la matriz (maximo %d): ", MAX);
    if (scanf("%d", &n) != 1 || !valido(n)) {
        printf("tamaño fuera de rango (1 a %d).\n", MAX);
        return 1;
    }

    gen(m, n);
    printf("\nMatriz generada:\n");
    ver(m, n);

    int f1 = pedirFila("Fila 1 (1 a %d): ", n);
    int f2 = pedirFila("Fila 2 (1 a %d): ", n);

    f1--; f2--;

    if (f1 == f2) {
        printf("No se puede intercambiar una fila consigo misma.\n");
        return 0;
    }

    swap(m, n, f1, f2);
    printf("\nMatriz con filas %d y %d intercambiadas:\n", f1 + 1, f2 + 1);
    ver(m, n);

    return 0;
}

// *RF2:Genera matriz aleatoria
void gen(int m[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            m[i][j] = rand() % 99 + 1;
}

// *RF3:Muestra matriz
void ver(int m[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        printf("    ");
        for (int j = 0; j < n; j++)
            printf("%3d ", m[i][j]);
        printf("\n");
    }
}

// Intercambia dos filas
void swap(int m[MAX][MAX], int n, int f1, int f2) {
    for (int j = 0; j < n; j++) {
        int tmp = m[f1][j];
        m[f1][j] = m[f2][j];
        m[f2][j] = tmp;
    }
}

// Verifica si el tamaño es válido
int valido(int n) {
    return n > 0 && n <= MAX;
}

// Pide número de fila al usuario
int pedirFila(const char* msg, int max) {
    int f;
    do {
        printf(msg, max);
        if (scanf("%d", &f) != 1) {
            printf("Entrada inválida.\n");
            exit(1);
        }
        if (f < 1 || f > max)
            printf("Fuera de rango. Intenta (1 a %d).\n", max);
    } while (f < 1 || f > max);

    return f;
}
