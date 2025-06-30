#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_INTENTOS 10
#define COLUMNAS 3
//RF01 – Configuración dinámica del rango: El sistema debe permitir que el usuario defina elrango mínimo y máximo del número secreto.
//RF02 – Configuración dinámica de intentos: El sistema debe permitir que el usuario seleccione el número máximo de intentos (hasta 10).
//RF03 – Validación de rango y duplicados: El sistema debe validar que cada intento esté dentro del rango y no se repita.
//RF04 – Registro de intentos en matriz: El sistema debe almacenar en una matriz el número de intento, el valor ingresado y el resultado (0 bajo, 1 alto, 2 correcto).
//RF05 – Visualización de resumen detallado: Al terminar, el sistema debe mostrar una tabla con cada intento y el resultado textual, y revelar el número secreto si no se adivinó.
int main() {
   int min_r, max_r;
   int max_intentos;
   int i, intentos_realizados= 0;
   int N_secreto, intento;
   int matriz_intentos[MAX_INTENTOS][COLUMNAS];
   bool adivinado= false;
//RF01 – Configuración del rango
printf("=== BIENVENIDO AL JUEGO ADIVINA EL NUMERO ===\n");
printf("==DEFINAMOS TU RANGO PARA EL NUMERO SECRETO==\n");
do{
printf("INGRESA EL NUMERO MINIMO: ");
scanf("%d",&min_r);
printf("INGRESA EL NUMERO MAXIMO: ");
scanf("%d",&max_r);

if(min_r>=max_r){
    printf("ERROR: EL NUMERO MINIMO DEBE SER MENOR QUE EL MAXIMO\n");
}
    } while(min_r >= max_r);
// RF02 - Configuración de intentos
do{
printf("\n INGRESE EL NUMERO DE INTENTOS QUE DESEE (MAXIMO 10): ",MAX_INTENTOS);
scanf("%d",&max_intentos);

if( max_intentos<=0 || max_intentos>MAX_INTENTOS){
    printf("\n");
    printf("COMETISTE UN ERROR!! LOS INTENTOS DEBEN ESTAR ENTRE 1 Y %d.\n", MAX_INTENTOS);

}
}while(max_intentos<=0||max_intentos>MAX_INTENTOS);
srand(time(NULL));
N_secreto=rand()%(max_r- min_r+1)+ min_r;
for(i = 0; i < max_intentos; i++) {
        bool valido = false;

// RF03 - Validación de rango y duplicados
do {
    printf("\nIntento %d: INGRESA UN NUMERO ENTRE %d y %d: ", i+1, min_r, max_r);
            scanf("%d", &intento);
    if(intento < min_r || intento > max_r) {
            printf("NUMERO FUERA DEL RANGO,\nINTENTALO DE NUEVO\n");
                continue;
            }
    bool duplicado = false;
            for(int j = 0; j < intentos_realizados; j++) {
                if(matriz_intentos[j][1] == intento) {
                    printf("YA INGRESASTE ESTE NUMERO. PRUEBA CON OTRO.\n");
                    duplicado = true;
                    break;
                }

            }
if(!duplicado) {
                valido = true;
            }
        } while(!valido);
// RF04 - Registro en matriz
        matriz_intentos[intentos_realizados][0] = i+1;
        matriz_intentos[intentos_realizados][1] = intento;
        if(intento == N_secreto) {
printf("\nFELICIDADES!! ADIVINASTE EL NUMERO SECRETO.\n");
            matriz_intentos[intentos_realizados][2] = 2;
        adivinado = true;
            intentos_realizados++;
            break;
        } else if(intento < N_secreto) {
            printf("DEMASIADO BAJO.\n");
            matriz_intentos[intentos_realizados][2] = 0;
        } else {
            printf("DEMASIADO ALTO.\n");
            matriz_intentos[intentos_realizados][2] = 1;
 }

        intentos_realizados++;
    }
// RF05 - Visualización de resumen detallado
    printf("\n=== DETALLES DEL JUEGO ===\n");
    printf("NUMERO SECRETO: %d\n", N_secreto);

    if(intentos_realizados > 0) {
        printf("\n=== HISTORIAL DE INTENTOS ===\n");
        printf("| Intento #  | Valor |   Resultado    |\n");
    for(i = 0; i < intentos_realizados; i++) {
            printf("|    %2d     |  %3d  | ", matriz_intentos[i][0], matriz_intentos[i][1]);

            switch(matriz_intentos[i][2]) {
                case 0: printf("Demasiado bajo |\n"); break;
                case 1: printf("Demasiado alto |\n"); break;
                case 2: printf("CORRECTO!     |\n"); break;
            }
        }
}

    if(!adivinado) {
        printf("\nNo lograste adivinar el número. ¡Mejor suerte la próxima vez!\n");
    }

    return 0;
}
/*CREDITOS:SARAHI MUÑOZ*/
