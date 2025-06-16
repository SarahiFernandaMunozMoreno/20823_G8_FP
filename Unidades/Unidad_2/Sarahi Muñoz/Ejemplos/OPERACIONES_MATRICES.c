#include <stdio.h>

//REQUISITOS FUNCIONALES (RF):
 //RF1 - El programa debe permitir ingresar matrices cuadradas (n x n).
 //RF2 - Validar que las matrices sean cuadradas antes de operar.
 //RF3 - Implementar 4 operaciones básicas: suma, resta, multiplicación y mostrar matrices.
 //RF4 - Mostrar resultados claramente formateados.
 //RF5 - Menú interactivo con opciones numeradas.

// INGRESO
void ingresarMatriz(int n, int matriz[n][n]) {
    printf("\nIngrese los elementos de la matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

// MOSTRAR
void mostrarMatriz(int n, int matriz[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

// SUMAR
void sumarMatrices(int n, int A[n][n], int B[n][n], int resultado[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultado[i][j] = A[i][j] + B[i][j];
        }
    }
}

// RESTAR
void restarMatrices(int n, int A[n][n], int B[n][n], int resultado[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultado[i][j] = A[i][j] - B[i][j];
        }
    }
}

// MULTIPLICAR
void multiplicarMatrices(int n, int A[n][n], int B[n][n], int resultado[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < n; k++) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int n, opcion;

    printf("OPERACIONES CON MATRICES CUADRADAS (n x n)\n");
    printf("Ingrese el tamaño de las matrices (n): ");
    scanf("%d", &n);

    // RF2
    if (n <= 0) {
        printf("\nError: El tamaño debe ser un numero positivo.\n");
        return 1;
    }

    int matrizA[n][n], matrizB[n][n], resultado[n][n];

    do {
    // RF5
        printf("\n=== MENU DE OPERACIONES ===\n");
        printf("1. Ingresar matrices\n");
        printf("2. Sumar matrices\n");
        printf("3. Restar matrices\n");
        printf("4. Multiplicar matrices\n");
        printf("5. Mostrar matrices\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: // RF1 - Ingresar matrices
                printf("\nMatriz A:\n");
                ingresarMatriz(n, matrizA);
                printf("\nMatriz B:\n");
                ingresarMatriz(n, matrizB);
                break;

            case 2: // RF3 - Suma
                sumarMatrices(n, matrizA, matrizB, resultado);
                printf("\nResultado de la suma:\n");
                mostrarMatriz(n, resultado); // RF4
                break;

            case 3: // RF3 - Resta
                restarMatrices(n, matrizA, matrizB, resultado);
                printf("\nResultado de la resta:\n");
                mostrarMatriz(n, resultado); // RF4
                break;

            case 4: // RF3 - Multiplicación
                multiplicarMatrices(n, matrizA, matrizB, resultado);
                printf("\nResultado de la multiplicacion:\n");
                mostrarMatriz(n, resultado); // RF4
                break;

            case 5: // Mostrar matrices originales
                printf("\nMatriz A:\n");
                mostrarMatriz(n, matrizA);
                printf("\nMatriz B:\n");
                mostrarMatriz(n, matrizB);
                break;

            case 6:
                printf("\nSaliendo del programa...\n");
                break;

            default:
                printf("\nOpcion no valida. Intente nuevamente.\n");
        }
    } while (opcion != 6);

    return 0;
}
