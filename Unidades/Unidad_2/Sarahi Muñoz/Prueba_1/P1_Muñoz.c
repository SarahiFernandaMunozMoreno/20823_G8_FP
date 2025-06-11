#include <stdio.h>
#define max
//RF1:El programa debera pedir el ingreso de filas y columnas de tamaño de su matriz
//RF2:El programa pedira ingresar los datos de su matriz
//RF3:El programa debera pedir la fila de la cual decee analizar el maximo
//RF4:El programa debe mostrar el valor maximo de dicha fila
int main () {
int F, C;
int i, j;
int max;
int matriz[F][C];
}
// RF1
printf(" Ingrese el numero de filas : ") ;
scanf(" %d " , " F ");

printf(" Ingrese el numero de columnas : ") ;
scanf("%d","C");
int matriz[F][C];

// RF2
for(i = 0; i < F; i++) {
    for(j = 0; j < C; j++) {
        printf("Ingrese los datos de su matriz [%d][%d]: ", i, j);
         scanf("%d", matriz[i][j]);
        }
    }
// RF3
int max;
printf("Ingrese la fila que desea analizar (%d): ", F - 1);
scanf("%d", max);
