#include <stdio.h>

#define N 15
//RF_1:El sistema debe almacenar números enteros del 1 al 15 en un arreglo (Vec).
//RF_2:El sistema debe calcular el factorial de cada número en Vec y almacenarlo en otro arreglo (Fact).
//RF_3:El sistema debe imprimir una tabla con dos columnas: Número y Factorial, formateada para alinear los valores.
//RF_4:El sistema debe usar el tipo unsigned long long para evitar desbordamiento en factoriales grandes.

//*Funciones
void llenar(int v[]);
void fact(int v[], unsigned long long f[]);
void ver(int v[], unsigned long long f[]);

int main() {
    int vec[N];
    unsigned long long factv[N];

    llenar(vec);
    fact(vec, factv);
    ver(vec, factv);

    return 0;
}

// *RF1
void llenar(int v[]) {
    for (int i = 0; i < N; i++) {
        v[i] = i + 1;
    }
}

// *RF2
void fact(int v[], unsigned long long f[]) {
    for (int i = 0; i < N; i++) {
        f[i] = 1;
        for (int j = 1; j <= v[i]; j++) {
            f[i] *= j;
        }
    }
}

// *RF3
void ver(int v[], unsigned long long f[]) {
    printf("Numero | Factorial\n");
    printf("---------------------------\n");
    for (int i = 0; i < N; i++) {
        printf("%6d | %20llu\n", v[i], f[i]);
    }
}
