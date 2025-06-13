#include <stdio.h>
#include <stdlib.h>
#define FILAS 6
#define COLUMNAS 7
#define JUGADOR1 '*'
#define JUGADOR2 '#'
// Función para imprimir el tablero
printf("Bienvenidos a este juego \n");
void imprimirTablero(char tablero[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf(" %c ", tablero[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < COLUMNAS; i++) {
        printf(" %d ", i + 1);
    }
    printf("\n");
}
// Función para comprobar si hay un ganador
int comprobarGanador(char tablero[FILAS][COLUMNAS], char jugador) {
    // Comprobar horizontal
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS - 3; j++) {
            if (tablero[i][j] == jugador && tablero[i][j + 1] == jugador && tablero[i][j + 2] == jugador && tablero[i][j + 3] == jugador) {
                return 1;
            }
        }
    }
    // Comprobar vertical
    for (int i = 0; i < FILAS - 3; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (tablero[i][j] == jugador && tablero[i + 1][j] == jugador && tablero[i + 2][j] == jugador && tablero[i + 3][j] == jugador) {
                return 1;
            }
        }
    }
    // Comprobar diagonal (arriba-izquierda a abajo-derecha)
    for (int i = 0; i < FILAS - 3; i++) {
        for (int j = 0; j < COLUMNAS - 3; j++) {
            if (tablero[i][j] == jugador && tablero[i + 1][j + 1] == jugador && tablero[i + 2][j + 2] == jugador && tablero[i + 3][j + 3] == jugador) {
                return 1;
            }
        }
    }
    // Comprobar diagonal (abajo-izquierda a arriba-derecha)
    for (int i = 3; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS - 3; j++) {
            if (tablero[i][j] == jugador && tablero[i - 1][j + 1] == jugador && tablero[i - 2][j + 2] == jugador && tablero[i - 3][j + 3] == jugador) {
                return 1;
            }
        }
    }

    return 0;
}
int main() {
    char tablero[FILAS][COLUMNAS];
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            tablero[i][j] = '.';
        }
    }

    char jugadorActual = JUGADOR1;
    int columna;
    while (1) {
        imprimirTablero(tablero);
        printf("Turno de jugador %c. Ingrese la columna: ", jugadorActual);
        scanf("%d", &columna);
        columna--;
        // Comprobar si la columna está llena
        if (tablero[0][columna] != '.') {
            printf("La columna está llena. Intente de nuevo.\n");
            continue;
        }
        // Colocar la ficha en la columna
        for (int i = FILAS - 1; i >= 0; i--) {
            if (tablero[i][columna] == '.') {
                tablero[i][columna] = jugadorActual;
                break;
            }
        }
        // Comprobar si hay un ganador
        if (comprobarGanador(tablero, jugadorActual)) {
            imprimirTablero(tablero);
            printf("Jugador %c gana!\n", jugadorActual);
            break;
        }
        // Cambiar de jugador
        if (jugadorActual == JUGADOR1) {
            jugadorActual = JUGADOR2;
        } else {
            jugadorActual = JUGADOR1;
        }
    }

    return 0;
}
