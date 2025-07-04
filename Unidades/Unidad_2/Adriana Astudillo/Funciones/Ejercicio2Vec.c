#include <stdio.h>
#include <stdbool.h>

#define SIZE 15
//R_1:El sistema debe inicializar un vector de tamaño 15 con valores del 1 al 14.
//R_2:El sistema debe solicitar al usuario dos números enteros (n_1 y n_2).
//R_3:El sistema debe buscar ambos números en el vector y actualizar las banderas correspondientes si los encuentra.
//R_4:El sistema debe mostrar un mensaje indicando si: Ambos números están en el vector, Ninguno de los números está en el vector.
//R_5:El sistema debe mostrar un mensaje indicando si:Solo el primer número está en el vector, Solo el segundo número está en el vector.
//*Funciones
void inicia(int v[]);
void ing(int *a, int *b);
bool busca(int v[], int n);
void encontrar(bool f1, bool f2);

int main() {
    int vec[SIZE];
    int n1, n2;
    bool b1, b2;

    inicia(vec);
    ing(&n1, &n2);

    b1 = busca(vec, n1);
    b2 = busca(vec, n2);

encontrar(b1, b2);

    return 0;
}

// *RF1
void inicia(int v[]) {
    for (int i = 0; i < SIZE - 1; i++) {
        v[i] = i + 1;
    }
    v[SIZE - 1] = 0;
}

// *RF2
void ing(int *a, int *b) {
    printf("Ingrese el primer numero a buscar: ");
    scanf("%d", a);
    printf("Ingrese el segundo numero a buscar: ");
    scanf("%d", b);
}

// *RF3
bool busca(int v[], int n) {
    for (int i = 0; i < SIZE -1; i++) {
        if (v[i] == n) return true;
    }
    return false;
}
//*RF4
void encontrar(bool f1, bool f2) {
    if (f1 && f2) {
        printf("Ambos numeros estan en el vector\n");
    } else if (f1) {
        printf("Solo el primer numero esta en el vector\n");
    } else if (f2) {
        printf("Solo el segundo numero esta en el vector\n");
    } else {
        printf("Ninguno de los numeros esta en el vector\n");
    }
}
