#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//RF2.1 – debe generar un número aleatorio entre 1 y 100.
//RF2.2 – debe permitir hasta 5 intentos mediante un ciclo 'for'.
//RF2.3 – debe indicar si el intento es correcto, bajo o alto.
//RF2.4 – Al final del juego, debe mostrar todos los intentos realizados.
//RF2.5 – Mostrar un mensaje secreto si el jugador adivina el número correctamente

int main() {
    int numeroSecreto, intento;
    int acierto = 0;


    int intento1 = 0, intento2 = 0, intento3 = 0, intento4 = 0, intento5 = 0;

// RF2.1
    srand(time(NULL));
    numeroSecreto = rand() % 100 + 1;

    printf(" Bienvenido al juego Adivina el Numero (1 a 100)\n");
    printf(" Tienes 5 intentos para adivinarlo\n");

// RF2.2
    for (int i = 1; i <= 5; i++) {
        printf("\n Intento %d: ", i);
        scanf("%d", &intento);



// RF2.3
        if (intento == numeroSecreto) {
            printf(" ¡Correcto! Adivinaste el número.\n");
            printf(" Mensaje secreto: ¡Felicidades, eres un adivinador experto!\n");
// RF2.5
            acierto = 1;
            break;
        } else if (intento < numeroSecreto) {
            printf("Muy bajo.");
        } else {
            printf("Muy alto.");
        }
    }

// RF2.4
    printf("\n\n Lista de intentos realizados:\n Intento %d: i");


    if (!acierto) {
        printf("\n No lograste adivinar el numero. El numero correcto era: %d\n", numeroSecreto);
    }

    return 0;
}
