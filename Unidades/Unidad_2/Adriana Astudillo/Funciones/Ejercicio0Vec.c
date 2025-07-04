#include <stdio.h>

#define N 10
//RF_1:El sistema debe permitir al usuario ingresar 10 valores enteros y almacenarlos en un vector.
//RF_2:El sistema debe ordenar los números en orden descendente (de mayor a menor).
//RF_3:El sistema debe imprimir el vector ordenado en formato lista.
//RF_4:El algoritmo de ordenamiento debe ser eficiente para entradas pequeñas
// *Funciones
void leer(int v[]);
void ord(int v[]);
void ver(int v[]);

int main() {
    int vec[N];

    leer(vec);
    ord(vec);
    ver(vec);

    return 0;
}

// *RF1
void leer(int v[]) {
    for (int i = 0; i < N; i++) {
        printf("Ingrese el valor %d: ", i + 1);
        scanf("%d", &v[i]);
    }
}

// *RF2
void ord(int v[]) {
    for (int i = 0; i < N - 1; i++) {
        int max = i;
        for (int j = i + 1; j < N; j++) {
            if (v[j] > v[max]) {
                max = j;
            }
        }
        if (max != i) {
            int tmp = v[i];
            v[i] = v[max];
            v[max] = tmp;
        }
    }
}

// *RF3
void ver(int v[]) {
    printf("\nVector ordenado (descendente):\n");
    for (int i = 0; i < N; i++) {
        printf("%d\n", v[i]);
    }
}
