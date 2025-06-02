#include <stdio.h>
#include <stdbool.h>  

#define SIZE 15  

int main() {
    int vec[SIZE];    
    int n_1, n_2;    
    bool bandera_n_1 = false;  
    bool bandera_n_2 = false;  

    for (int i = 1; i <= 14; i++) {
        vec[i] = i;
    }
    printf("Ingrese el primer número a buscar: ");
    scanf("%d", &n_1);
    printf("Ingrese el segundo número a buscar: ");
    scanf("%d", &n_2);
    for (int i = 1; i <= 14; i++) {
        if (vec[i] == n_1) {
            bandera_n_1 = true;
        }
        if (vec[i] == n_2) {
            bandera_n_2 = true;
        }
    }
    if (bandera_n_1 && bandera_n_2) {
        printf("Ambos números están en el vector\n");
    } else if (bandera_n_1) {
        printf("Solo el primer número está en el vector\n");
    } else if (bandera_n_2) {
        printf("Solo el segundo número está en el vector\n");
    } else {
        printf("Ninguno de los números está en el vector\n");
    }

    return 0;
}
