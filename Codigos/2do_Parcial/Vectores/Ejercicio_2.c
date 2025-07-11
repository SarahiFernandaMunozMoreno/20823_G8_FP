#include <stdio.h>
#include <stdbool.h>  
//R_1:El sistema debe inicializar un vector de tamaño 15 con valores del 1 al 14.
//R_2:El sistema debe solicitar al usuario dos números enteros (n_1 y n_2).
//R_3:El sistema debe buscar ambos números en el vector y actualizar las banderas correspondientes si los encuentra.
//R_4:El sistema debe mostrar un mensaje indicando si: Ambos números están en el vector, Ninguno de los números está en el vector.
//R_5:El sistema debe mostrar un mensaje indicando si:Solo el primer número está en el vector, Solo el segundo número está en el vector.
    
#define SIZE 15  

int main() {
    int vec[SIZE];    
    int n_1, n_2;    
    bool bandera_n_1 = false;  
    bool bandera_n_2 = false;  

    for (int i = 1; i <= 14; i++) {
        vec[i] = i;
    }
    printf("Ingrese el primer numero a buscar: ");
    scanf("%d", &n_1);
    printf("Ingrese el segundo numero a buscar: ");
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
        printf("Ambos numeros están en el vector\n");
    } else if (bandera_n_1) {
        printf("Solo el primer numero esta en el vector\n");
    } else if (bandera_n_2) {
        printf("Solo el segundo numero esta en el vector\n");
    } else {
        printf("Ninguno de los numeros esta en el vector\n");
    }

    return 0;
}
//NRC: #20823_G8_FP
//Colaboradores
//Astudillo Adriana
//Muñoz Sarahi
//Nero Alan
