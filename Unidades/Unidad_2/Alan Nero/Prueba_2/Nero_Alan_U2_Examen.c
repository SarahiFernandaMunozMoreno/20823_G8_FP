#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Requisitos funcionales
// 1. Permitir al usuario que defina el rango en el que estará el número secreto
// 2. Permitir al usuario que seleccione el número máximo de intentos (hasta 10)
// 3. Validar que cada intento esté dentro del rango y no se repita
// 4. Almacenar en una matriz el número de intentos, el valor ingresado y el resultado (0 bajo, 1 alto, 2 correcto)
// 5. Presentar una tabla con cada intento y el resultado textual y revelar el número secreto si no se adivinó

int main() {
    int min, max, num_sec;
    int numIntentos, intento, resultado;
    int matriz[10][3]; // [intento, valor ingresado, resultado]
    bool existe;
    int i, j;
    srand(time(NULL));
    // 1. Permitir al usuario que defina el rango en el que estará el número secreto
    printf("Bienvenido al juego de la adivinanza del número\n");
    printf("Te deseo mucha suerte...\n");
    printf("Define el rango para el número secreto:\n");

    do {
        printf("Ingrese el número mínimo: ");
        scanf("%d", &min);
        printf("Ingrese el número máximo: ");
        scanf("%d", &max);
        if (min >= max) {
            printf("Error: El mínimo debe ser menor que el máximo.\n");
        }
    } while (min >= max);

    // 2. Definir el número máximo de intentos
    do {
        printf("Ingrese el número máximo de intentos (hasta 10): ");
        scanf("%d", &numIntentos);
        if (numIntentos < 1 || numIntentos > 10) {
            printf("Error: Los intentos deben ser entre 1 y 10.\n");
        }
    } while (numIntentos < 1 || numIntentos > 10);
    num_sec = (rand() % (max - min + 1)) + min;
    i = 0;
    while (i < numIntentos) {
        // 3. Validar que cada intento esté dentro del rango y no se repita
        do {
            existe = false;
            printf("\nIntento %d: Ingresa un número entre %d y %d: ", i + 1, min, max);
            scanf("%d", &intento);
            if (intento < min || intento > max) {
                printf("Error: El número está fuera del rango.\n");
                existe = true;
                continue;
            }
            for (j = 0; j < i; j++) {
                if (matriz[j][1] == intento) {
                    printf("Error: Ya intentaste con este número.\n");
                    existe = true;
                    break;
                }
            }
        } while (existe);
        // 4. Almacenar en una matriz el número de intentos, el valor ingresado y el resultado
        if (intento == num_sec) {
            resultado = 2; // Correcto
        } else if (intento < num_sec) {
            resultado = 0; // Bajo
        } else {
            resultado = 1; // Alto
        }
        matriz[i][0] = i + 1;
        matriz[i][1] = intento;
        matriz[i][2] = resultado;

        if (resultado == 2) {
            printf("¡Correcto! Adivinaste el número secreto.\n");
            break;
        } else if (resultado == 0) {
            printf("Muy bajo, intenta un número más alto.\n");
        } else {
            printf("Muy alto, intenta un número más bajo.\n");
        }

        i++;
    }

// 5. Presentar una tabla con cada intento y el resultado textual y revelar el número secreto si no se adivinó
    printf("\n================ TABLA DE INTENTOS ================\n");
    printf("Intento  | Número Ingresado  |  Resultado\n");
    printf("-----------------------------------------------\n");

    for (j = 0; j < i; j++) {
        printf("   %2d    |       %3d         |   ", matriz[j][0], matriz[j][1]);
        switch (matriz[j][2]) {
            case 0: printf("Bajo\n"); break;
            case 1: printf("Alto\n"); break;
            case 2: printf("Correcto\n"); break;
        }
    }

    if (matriz[i-1][2] != 2) {
        printf("======================================================\n");
        printf("Lo siento, no adivinaste el número. El número secreto era: %d\n", num_sec);
    }

    return 0;
}
