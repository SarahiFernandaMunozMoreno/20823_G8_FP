#include <stdio.h>
#include <stdbool.h>
#define SUMA_MAG 15

int main() {
    int matriz[3][3];
    int s_fila, s_colm, s_diag1, s_diag2;
    int i,j;
    bool es_mag=true;

/* RF_1: Ingreso y validación de datos */
    printf("INGRESA LOS 9 ELEMENTOS PARA LA MATRIZ 3x3:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            do {
                printf("TU VALOR PARA LA POSICION [%d][%d]: ", i, j);
                scanf("%d", &matriz[i][j]);
                if(matriz[i][j] < 1 || matriz[i][j] > 9) {
                    printf("Valor fuera de rango. Ingrese nuevamente .\n");
                }
            } while(matriz[i][j] < 1 || matriz[i][j] > 9);
        }
    }

    /* RF_2: Suma de filas */
    printf("\nSuma de filas:\n");
    for(i = 0; i < 3; i++) {
        s_fila = 0;
        for(j = 0; j < 3; j++) {
            s_fila += matriz[i][j];
        }
        printf("Fila %d: %d\n", i+1, s_fila);
        if(s_fila != SUMA_MAG) es_mag = false;
    }

    /* RF_3: Suma de columnas */
    printf("\nSuma de columnas:\n");
    for(j = 0; j < 3; j++) {
        s_colm = 0;
        for(i = 0; i < 3; i++) {
            s_colm += matriz[i][j];
        }
        printf("Columna %d: %d\n", j+1, s_colm);
        if(s_colm != SUMA_MAG) es_mag = false;
    }

     /* RF_4: Suma de diagonales */
    s_diag1 = matriz[0][0] + matriz[1][1] + matriz[2][2];
    s_diag2 = matriz[0][2] + matriz[1][1] + matriz[2][0];
    printf("\nSuma diagonal 1: %d\n", s_diag1);
    printf("Suma diagonal 2: %d\n", s_diag2);
    if(s_diag1 != SUMA_MAG || s_diag2 != SUMA_MAG) es_mag = false;


    /* RF_5: Resultado final */
    printf("\n");
    if(es_mag) {
        printf("FELICIDADES! ES UN CUADRADO MAGICO.\n");
    } else {
        printf("LO SIENTO, NO ES UN CUADRADO MAGICO.\n");
    }

    return 0;
}
