#include <stdio.h>
#define N 3
//*RF1: Ingreso de matriz y comprobar que los números entan entre 1 y 9, si nop cumple se vuelve a pedir.
//*RF2: Se calcula la suma por filas.
//*RF3: Si la suma por filas coincide se calcula la suma de columna.
//*RF4: Si la suma por columnas coincide, se hace la suma de diagonales.
//* RF5:
int main() {
    int matriz[N][N];
    int fila, columna;
    int diag_1 = 0, diag_2 = 0;
    int sumf[N] = {0}, sumc[N] = {0};

    int val = 1, n;

    printf("Ingrese los valores de la matriz 3x3 (entre 1 y 9):\n");
    for (fila = 0; fila < N; fila++) {
        for (columna = 0; columna < N; columna++) {
            do {
                printf("Elemento [%d][%d]: ", fila + 1, columna + 1);
                scanf("%d", &n);
                if (n < 1 || n > 9) {
                    printf("Valor invalido. Debe ser entre 1 y 9.\n");
                }
            } while (n < 1 || n > 9);
            matriz[fila][columna] = n;
        }
    }

    // sumas
    for (fila = 0; fila < N; fila++) {
        for (columna = 0; columna < N; columna++) {
            sumf[fila] += matriz[fila][columna];
            sumc[columna] += matriz[fila][columna];
            if (fila == columna) diag_1 += matriz[fila][columna];
            if (fila + columna == N - 1) diag_2 += matriz[fila][columna];
        }
    }

    //sumas de filas y columnas
    printf("\nSuma de filas:\n");
    for (fila = 0; fila < N; fila++) {
        printf("Fila %d: %d\n", fila + 1, sumf[fila]);
    }

    printf("\nSuma de columnas:\n");
    for (columna = 0; columna < N; columna++) {
        printf("Columna %d: %d\n", columna + 1, sumc[columna]);
    }

    printf("\nSuma de diagonal principal: %d\n", diag_1);
    printf("Suma de diagonal secundaria: %d\n", diag_2);

    int sumatotal = sumf[0];

    for (fila = 1; fila < N; fila++) {
        if (sumf[fila] != sumatotal) {
            val = 0;
            break;
        }
    }

    for (columna = 0; columna < N && val; columna++) {
        if (sumc[columna] != sumatotal) {
            val = 0;
            break;
        }
    }

    if (diag_1 != sumatotal || diag_2 != sumatotal) {
        val = 0;
    }

    if (val) {
        printf("\nLa matriz ingresada es un cuadrado magico.\n");
    } else {
        printf("\nLa matriz no es un cuadrado magico.\n");
    }

    return 0;
}

