#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define INTENTO_MAX 10
#define COLUMNAS 3

int main() {
    int intentos;
    int i, intento_realizados = 0;
    int N_secreto;
    int r_max, r_min;
    int max_intentos;
    int matriz_intentos[INTENTO_MAX][COLUMNAS];
    bool adivinado = false;

    srand(time(NULL));

    printf("=== BIENVENIDO AL JUEGO ===\n");
    printf("A CONTINUACION DEFINIRAS TU RANGO\n");

// RF01:Configuración de rango
    do {
        printf("TU RANGO MINIMO ES: \n");
        scanf("%d", &r_min);
        printf("TU RANGO MAXIMO ES: \n");
        scanf("%d", &r_max);

        if (r_min >= r_max) {
            printf("ERROR: EL RANGO MINIMO DEBE SER MENOR QUE EL RANGO MAXIMO\n");
        }
    } while (r_min >= r_max);

// RF02 - Configuración de intentos
    do {
        printf("\nINGRESE EL NUMERO DE INTENTOS QUE DESEE (MAXIMO %d): ", INTENTO_MAX);
        scanf("%d", &max_intentos);

        if (max_intentos <= 0 || max_intentos > INTENTO_MAX) {
            printf("\nCOMETISTE UN ERROR!! LOS INTENTOS DEBEN ESTAR ENTRE 1 Y %d.\n", INTENTO_MAX);
        }
    } while (max_intentos <= 0 || max_intentos > INTENTO_MAX);

    N_secreto = rand() % (r_max - r_min + 1) + r_min;

    for (i = 0; i < max_intentos; i++) {
        bool valido = false;

// RF03:validacion de rango y duplicados
        do {
            printf("\nIntento %d: INGRESA UN NUMERO ENTRE %d y %d: ", i + 1, r_min, r_max);
            scanf("%d", &intentos);

            if (intentos < r_min || intentos > r_max) {
                printf("NUMERO FUERA DEL RANGO, INTENTALO DE NUEVO\n");
                continue;
            }

            bool duplicado = false;
            for (int j = 0; j < intento_realizados; j++) {
                if (matriz_intentos[j][1] == intentos) {
                    printf("YA INGRESASTE ESTE NUMERO. PRUEBA CON OTRO.\n");
                    duplicado = true;
                    break;
                }
            }

            if (!duplicado) {
                valido = true;
            }

        } while (!valido);

// RF04 - Registro en matriz
        matriz_intentos[intento_realizados][0] = i + 1;
        matriz_intentos[intento_realizados][1] = intentos;

        if (intentos == N_secreto) {
            printf("\nFELICIDADES!! ADIVINASTE EL NUMERO SECRETO.\n");
            matriz_intentos[intento_realizados][2] = 2;
            adivinado = true;
            intento_realizados++;
            break;
        } else if (intentos < N_secreto) {
            printf("DEMASIADO BAJO.\n");
            matriz_intentos[intento_realizados][2] = 0;
        } else {
            printf("DEMASIADO ALTO.\n");
            matriz_intentos[intento_realizados][2] = 1;
        }

        intento_realizados++;
    }
// RF05 - Visualización de resumen detallado
    printf("\n=== DETALLES DEL JUEGO ===\n");
    printf("NUMERO SECRETO: %d\n", N_secreto);

    if (intento_realizados > 0) {
        printf("\n=== HISTORIAL DE INTENTOS ===\n");
        printf("| Intento #  | Valor |   Resultado    |\n");
        for (i = 0; i < intento_realizados; i++) {
            printf("|    %2d     |  %3d  | ", matriz_intentos[i][0], matriz_intentos[i][1]);

            switch (matriz_intentos[i][2]) {
                case 0: printf("Demasiado bajo |\n"); break;
                case 1: printf("Demasiado alto |\n"); break;
                case 2: printf("CORRECTO!     |\n"); break;
            }
        }
    }

    if (!adivinado) {
        printf("\nNo lograste adivinar el número. ¡Mejor suerte la próxima vez!\n");
    }

    return 0;
}

/*CREDITOS:SARAHI MUÑOZ/
