#include <stdio.h>
#define MAX 100
//R_1:El sistema debe solicitar al usuario el número de términos (n) a generar, con un máximo de MAX = 100.
//R_2:El sistema debe validar que n esté en el rango permitido (1 a 100). Si no, mostrará un mensaje de error y terminará.
//R_3:El sistema debe calcular cada término de la sucesión usando la fórmula y almacenarlo en un vector.
//R_4:El sistema debe imprimir los términos generados en formato lista.
//*Funciones
int pedir(int);
void calc(int, int[]);
void imp(int, int[]);

int main() {
    int n;
    int vec[MAX];
//*RF1
    n = pedir(MAX);
    if (n == -1) return 1;

    calc(n, vec);
    imp(n, vec);

    return 0;
}
//*RF2
int pedir(int max) {
    int n;
    printf("Ingrese los terminos de la sucesion que desea generar (1-%d): ", max);
    if (scanf("%d", &n) != 1 || n <= 0 || n > max) {
        printf("Error: Debes ingresar un numero entre 1 y %d\n", max);
        return -1;
    }
    return n;
}
//*RF3
void calc(int n, int v[]) {
    for (int i = 0; i < n; i++) {
        int k = i + 1;
        v[i] = k * k + 3;
    }
}
//*RF4
void imp(int n, int v[]) {
    printf("\nLos primeros %d terminos de la sucesion son:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Termino %d: %d\n", i + 1, v[i]);
    }
}
