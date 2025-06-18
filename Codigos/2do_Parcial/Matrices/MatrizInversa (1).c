#include<stdio.h>
#define ARREGLO_MAX 100
#define SIN_TIPO float
int main() {
int i;
int j;
SIN_TIPO mat[ARREGLO_MAX][ARREGLO_MAX];
int n;
printf("Ingrese el tamaño N de la matriz (N x N):\n");
scanf("%i", &n);

/* Llenado de la matriz */
for (i=1; i<=n-1; ++i) {
for (j=1; j<=n-1; ++j) {
printf("Ingrese el elemento [%i,%i]:\n", i, j);
scanf("%f", mat[i-1][j-1]);
}
}
/* Recorrido en orden inverso */
printf("Matriz en orden inverso:\n");
for (i=n-1; i>=1; --i) {
for (j=n-1; j>=1; --j) {
printf("%f\n", mat[i-1][j-1]);
}
//NRC: #20823_G8_FP
//Colaboradores
//Astudillo Adriana
//Muñoz Sarahi
//Nero Alan
}
return 0;
}
