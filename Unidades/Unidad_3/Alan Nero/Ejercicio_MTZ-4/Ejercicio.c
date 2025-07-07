#include <stdio.h>
#define MAX 3 // Definimos el tamaño de la matriz 3x3
// Funciones usadas
void llenarMatriz(int matriz[MAX][MAX]);
void calcularSumas(int matriz[MAX][MAX]);
void imprimirMatriz(int matriz[MAX][MAX]);
int existeEnMatriz(int matriz[MAX][MAX], int F, int C, int numero);
int main() {
    int matriz[MAX][MAX];
    printf("Bienvenido al juego del cuadrado magico\n");
    printf("Te deseo mucha suerte...\n");
    printf("Ingrese los numeros para la matriz 3x3:\n");
    //Solicita al usuario llenar la matriz validando rango y repetidos
    llenarMatriz(matriz);
    //Muestra la matriz ingresada por el usuario
    printf("\nMatriz ingresada:\n");
    imprimirMatriz(matriz);
    //Calcula y muestra sumas de filas, columnas y diagonales
    calcularSumas(matriz);
    return 0;
}
//Verifica si un número ya existe en posiciones anteriores de la matriz
int existeEnMatriz(int matriz[MAX][MAX], int F, int C, int numero) {
    for (int i = 0; i <= F; i++) {
        for (int j = 0; j < MAX; j++) {
            if (i == F && j >= C) break; // No revisa posiciones futuras
            if (matriz[i][j] == numero) return 1; // Encontró repetido
        }
    }
    return 0; // No existe repetido
}
//Genera la matriz pidiendo al usuario valores entre 1 y 9 y sin repetidos
void llenarMatriz(int matriz[MAX][MAX]) {
    int numero;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            do {
                printf("Elemento [%d][%d]: ", i + 1, j + 1);
                scanf("%d", &numero);
                if (numero < 1 || numero > 9) {
                    printf("Error: El numero debe estar entre 1 y 9.\n");
                } else if (existeEnMatriz(matriz, i, j, numero)) {
                    printf("Error: El numero ya se ha ingresado.\n");
                    numero = 0; // Fuerza repetir
                }
            } while (numero < 1 || numero > 9);
            matriz[i][j] = numero; // Guarda el número en la matriz
        }
    }
}
//Calcula sumas por filas, columnas y diagonales y verifica cuadrado mágico
void calcularSumas(int matriz[MAX][MAX]) {
    int S_f[MAX] = {0};
    int S_c[MAX] = {0};
    int S_DP = 0;
    int S_DS = 0;
    //Calcular sumas de filas, columnas y diagonales
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            S_f[i] += matriz[i][j];
            S_c[j] += matriz[i][j];
        }
        S_DP += matriz[i][i];
        S_DS += matriz[i][MAX - i - 1];
    }

    int R = S_f[0];
    int esMagico = 1;
    //Verificar que todas las filas y columnas tengan la misma suma
    for (int i = 0; i < MAX; i++) {
        if (S_f[i] != R || S_c[i] != R) {
            esMagico = 0;
            break;
        }
    }
    //Verificar diagonales
    if (S_DP != R || S_DS != R) {
        esMagico = 0;
    }
    //Mostrar sumas de filas por separado
    printf("\n---Resultados de sumas por FILAS---\n");
    for (int i = 0; i < MAX; i++) {
        printf("Fila %d: %d\n", i + 1, S_f[i]);
    }
    //Mostrar sumas de columnas por separado
    printf("\n---Resultados de sumas por COLUMNAS---\n");
    for (int i = 0; i < MAX; i++) {
        printf("Columna %d: %d\n", i + 1, S_c[i]);
    }
    //Mostrar sumas de diagonales
    printf("\n---Resultados de sumas de DIAGONALES---\n");
    printf("Diagonal Principal: %d\n", S_DP);
    printf("Diagonal Secundaria: %d\n", S_DS);
    //Imprime mensaje si es o no magico
    if (esMagico) {
        printf("\nLa matriz si es un cuadrado magico con suma %d.\n", R);
    } else {
        printf("\nLa matriz no es es un cuadrado magico.\n");
    }
}
// Imprime la matriz ingresada
void imprimirMatriz(int matriz[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
