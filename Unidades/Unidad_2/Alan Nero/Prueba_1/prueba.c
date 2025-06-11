#include <stdio.h>
#define ARREGLO_MAX 10
//Requisitos funcionales para el programa:
//Generar una matriz mxn.
//Llenar la matriz con valores ingresados por el usuario.
//Solicita la fila a consultar.
//Imprime la matriz original y el valor maximo de la fila
int main() {
	int c;
	int f;
	int i;
	int j;
	int mat[ARREGLO_MAX][ARREGLO_MAX];
	int max;
    int fila_i;
	max = 10;
    printf("Bienvenidos al programa que te dira el valor maximo de una fila \n\n");
    // GENERA LA MATRIZ MxN
    printf("Ingrese el numero de filas\n");
	scanf("%i", &f);
	printf("Ingrese el numero de Columnas\n");
	scanf("%i", &c);
  if (f > max || c > max || f <= 0 || c <= 0) {
        printf("Dimensiones invalidas.\n");
    } else {
    // DATOS POR TECLADO INGRESADOS POR EL USUARIO
        printf("Ingrese los elementos de la matriz por filas:\n");
        for (i = 0; i < f; i++) {
            for (j = 0; j < c; j++) {
                printf("Elemento [%d][%d]: \n", i, j);
                scanf("%d", &mat[i][j]);
            }
        }
    }
    //PRESENTA LA MATRIZ
    printf("Matriz original:\n");
    for (i = 0; i < f; i++) {
        for (j =0; j < c; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    //SOLICITA AL USUARIO LA FILA A CONSULTAR
    printf("Ingrese la fila a consultar: ");
    scanf("%d", &fila_i);
    if (fila_i >= 0 && fila_i < f) {
            max = mat[fila_i][0];
    for (j = 1; j < c; j++) {
        if (mat[fila_i][j] > max) {
                max = mat[fila_i][j];
        }
    }
    //PRESENTA EL VALOR MAXIMO DE LA FILA
    printf("El valor maximo de la fila %d es: %d\n", fila_i, max);
} else {
    printf("Fila fuera de rango.\n");
}
    return 0;
}


