#include <stdio.h>
#define MAX 100
//El sistema debe solicitar al usuario el número de términos (n) a generar, con un máximo de MAX = 100.
//El sistema debe validar que n esté en el rango permitido (1 a 100). Si no, mostrará un mensaje de error y terminará.
//El sistema debe calcular cada término de la sucesión usando la fórmula y almacenarlo en un vector.
//El sistema debe imprimir los términos generados en formato lista.
int main() {
    int n;
    int vec[MAX];
    int k, VK;
    printf("¿Cuántos términos de la sucesión deseas generar? (1-%d): ", MAX);
    scanf("%d", &n);
    if (n > MAX || n <= 0) {
        printf("Error: Debes ingresar un número entre 1 y %d\n", MAX);
        return 1;
    }
    for (int posicion = 0; posicion < n; posicion++) {
        k = posicion + 1;
        VK = k * k + 3;
        vec[posicion] = VK;
    }
    printf("\nLos primeros %d términos de la sucesión son:\n", n);
    for (int posicion = 0; posicion < n; posicion++) {
        printf("Término %d: %d\n", posicion + 1, vec[posicion]);
    }

    return 0;
}
