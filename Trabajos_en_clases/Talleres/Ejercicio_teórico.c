/***Guarde 10 números reales en un vector***/
#include <stdio.h>
#define MAX 10
int main() {
    float X[MAX];
    for (int x = 0; x < MAX; x++) {
        printf("Ingresar un datos (%d): ", x + 1, MAX);
        scanf("%f", &X[x]);
    }
    for (int x = 0; x < MAX; x++) {
        printf("Numero %d: %.2f\n", x + 1, X[x]);
    }
    printf("Elaborado por el grupo 8: Sara Munoz, Alan Nero, Adriana Astudillo");
    return 0;
}
