#include <stdio.h> // Libreria para entrada y salida de datos
#include <stdlib.h> // Libreria proporciona memoria dinámica
#include <time.h> //Libreria de Gestion de tiempos

#define MAX_INTENTOS 5

int main() {
    int num[MAX_INTENTOS];
    int num_sec, intento;
    int i;

    // Número aleatorio entre 1 y 100
    srand(time(NULL));
    num_sec = rand() % 100 + 1;

    printf("=== Bienvenido al juego Adivina el Numero ===\n");
    printf("El numero está entre 1 y 100\n");
    printf("Tienes 5 intentos para adivinarlo... ¡Buena Suerte!\n");

    // Solicitar intentos del ciclo for
    for (i = 0; i < MAX_INTENTOS; i++) {
        printf("\nIntento %d: \nIngresa un numero: ", i + 1);
        scanf("%d", &intento);
        num[i] = intento;

    // Mensaje secreto al adivinar
        if (intento == num_sec) {
            printf("Felicidades Adivinaste el numero secreto.\n");
            printf("Eres un gran jugador.\n");
            break;
    // Validacion de Intentos
        } else if (intento < num_sec) {
            printf("Demasiado bajo.\n");
        } else {
            printf("Demasiado alto.\n");
        }
    }
    // Mostrar los intentos realizados
    printf("\nTus intentos fueron: ");
    for (int j = 0; j <= i; j++) {
        printf("%d ", num[j]);
    }

    // Mostrar el número secreto al final del juego
    printf("\nEl numero secreto era: %d\n", num_sec);

    return 0;

}
