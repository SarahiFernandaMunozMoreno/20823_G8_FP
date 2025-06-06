#include<stdio.h>
#define ARREGLO_MAX 100
//Requisitos funcionales del juego:
//Generar una matriz cuadrada de tamaño fijo 10x10.
//Llenar la matriz con valores ingresados por el usuario.
//Calcular la suma total de los elementos de la matriz.
//Pedir al jugador que adivine cuál es la suma total.
//Informar si el jugador acertó o no, mostrando la suma correcta si falla.
int main() {
	int c;
	int f;
	int i;
	int intento;
	int j;
	int mat[ARREGLO_MAX][ARREGLO_MAX];
	int max;
	int suma;
	suma = 0;
	max = 10;
	printf("Bienvenidos a este juego de adivinanza de un numero que se encuentra oculto en la matriz\n");
	printf("\n");
	printf("Ingrese el numero de filas\n");
	scanf("%i", &f);
	printf("Ingrese el numero de Columnas\n");
	scanf("%i", &c);
  if (f > max || c > max || f <= 0 || c <= 0) {
        printf("Dimensiones invalidas.\n");
    } else {
        printf("Ingrese los elementos de la matriz por filas:\n");
        for (i = 0; i < f; i++) {
            for (j = 0; j < c; j++) {
                printf("Elemento [%d][%d]: \n", i, j);
                scanf("%lf", &mat[i][j]);
                suma += mat[i][j];
            }
        }
        printf("Adivina que numero salio ^_^ \n");
        scanf("%lf", &intento);

        if (intento == suma) {
            printf("WOOOO Adivinaste :D\n");
        } else {
            printf("Lo siento no lo lograste T_T\n");
            printf("%.2f\n", suma);
        }
    }

    return 0;
}

