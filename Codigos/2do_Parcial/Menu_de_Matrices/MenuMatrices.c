#include <stdio.h>
#define MAX 10
	/* Requisitos funcionales del programa: */
	/* Generar una matriz MxN. */
	/* Llenar la matriz con valores ingresados por el usuario. */
	/* Calcular la suma, resta, multiplicación y potenciación de las matrices. */
	/* Presentar los resultados de las operaciones. */

void imprimirMatriz(float matriz[MAX][MAX], 
int filas, int columnas){
    int i, j;
    for (i = 0; i < filas; ++i) {
        for (j = 0; j < columnas; ++j) {
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int filas, columnas, i, j, k, m, opcion, potencia;
    float matriz1[MAX][MAX], matriz2[MAX][MAX];
    float resultado[MAX][MAX], temp[MAX][MAX];

    printf("Ingrese el numero de filas (maximo %d): ", MAX);
    scanf("%d", &filas);
    printf("Ingrese el numero de columnas (maximo %d): ", MAX);
    scanf("%d", &columnas);

    if (filas < 1 || filas > MAX || columnas < 1 || columnas > MAX) {
        printf("Error: las dimensiones deben estar entre 1 y %d.\n", MAX);
        return 1;
    }

    printf("Ingrese los elementos de la matriz 1:\n");
    for (i = 0; i < filas; ++i) {
        for (j = 0; j < columnas; ++j) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matriz1[i][j]);
        }
    }

    printf("Ingrese los elementos de la matriz 2:\n");
    for (i = 0; i < filas; ++i) {
        for (j = 0; j < columnas; ++j) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matriz2[i][j]);
        }
    }

    do {
        printf("\nBienvenidos este progrma realiza operaciones de matriz\n");
        printf("===== MENU =====\n");
        printf("1. Suma de matrices\n");
        printf("2. Resta de matrices\n");
        printf("3. Multiplicacion de matrices\n");
        printf("4. Potencia de la primera matriz\n");
        printf("5. Potencia de la segunda matriz\n");
        printf("6. Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                for (i = 0; i < filas; ++i)
                    for (j = 0; j < columnas; ++j)
                        resultado[i][j] = matriz1[i][j] + matriz2[i][j];

                printf("\nResultado de la suma:\n");
                imprimirMatriz(resultado, filas, columnas);
                break;

            case 2:
                for (i = 0; i < filas; ++i)
                    for (j = 0; j < columnas; ++j)
                        resultado[i][j] = matriz1[i][j] - matriz2[i][j];

                printf("\nResultado de la resta:\n");
                imprimirMatriz(resultado, filas, columnas);
                break;

            case 3:
                if (columnas != filas) {
                    printf("Error: para multiplicar, columnas de la primera deben igualar filas de la segunda.\n");
                } else {
                    for (i = 0; i < filas; ++i)
                        for (j = 0; j < columnas; ++j) {
                            resultado[i][j] = 0;
                            for (k = 0; k < columnas; ++k)
                                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
                        }

                    printf("\nResultado de la multiplicacion:\n");
                    imprimirMatriz(resultado, filas, columnas);
                }
                break;

            case 4:
            case 5: {
                float (*base)[MAX] = (opcion == 4) ? matriz1 : matriz2;
                if (filas != columnas) {
                    printf("Solo las matrices cuadradas pueden elevarse a una potencia.\n");
                } else {
                    printf("Ingrese la potencia (entero >= 1): ");
                    scanf("%d", &potencia);

                    if (potencia < 1) {
                        printf("Potencia no válida.\n");
                        break;
                    }

                    // Copiar matriz base a resultado
                    for (i = 0; i < filas; ++i)
                        for (j = 0; j < columnas; ++j)
                            resultado[i][j] = base[i][j];

                    for (k = 2; k <= potencia; ++k) {
                        // Multiplicar resultado por base y guardar en temp
                        for (i = 0; i < filas; ++i)
                            for (j = 0; j < columnas; ++j) {
                                temp[i][j] = 0;
                                for (m = 0; m < columnas; ++m)
                                    temp[i][j] += resultado[i][m] * base[m][j];
                            }

                        // Copiar temp a resultado
                        for (i = 0; i < filas; ++i)
                            for (j = 0; j < columnas; ++j)
                                resultado[i][j] = temp[i][j];
                    }

                    printf("\nResultado de la potencia:\n");
                    imprimirMatriz(resultado, filas, columnas);
                }
                break;
            }

            case 6:
                printf("\nSaliendo del programa... ¡Hasta pronto!\n");
                printf("\nElaborado por el grupo 8: Adriana Astudillo, Sara Munoz, Alan Nero, \n");
                break;

            default:
                printf("Opción inválida. Intente de nuevo.\n");
        }

    } while (opcion != 6);

    return 0;
}


