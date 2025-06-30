#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_INTENTOS 10
//RF01 � Configuraci�n del rango: El sistema debe permitir que el usuario defina el rango m�nimo y m�ximo del n�mero secreto.
//RF02 � Configuraci�n del n�mero de intentos: El sistema debe permitir que el usuario seleccione el n�mero de intentos (m�ximo 10).
//RF03 � Validaci�n de rango: El sistema debe validar que cada intento ingresado est�dentro del rango especificado.
//RF04 � Registro de intentos: El sistema debe almacenar cada intento del usuario en un vector.
//RF05 � Visualizaci�n de resultados: Al finalizar el juego, el sistema debe mostrar un resumen de los intentos y el n�mero secreto.
int main() {
   int min_r, max_r;
   int max_intentos;
   int i, intentos_realizados= 0;
   int N_secreto, intento;
   int lista_intentos[MAX_INTENTOS];

//RF01 � Configuraci�n del rango
printf("=== BIENVENIDO AL JUEGO ADIVINA EL NUMERO ===\n");
printf("==DEFINAMOS TU RANGO PARA EL NUMERO SECRETO==\n");
printf("INGRESA EL NUMERO MINIMO: ");
scanf("%d",&min_r);
printf("INGRESA EL NUMERO MAXIMO: ");
scanf("%d",&max_r);

if(min_r>=max_r){
    printf("ERROR: EL NUMERO MINIMO DEBE SER MENOR QUE EL MAXIMO\n");
    return 1;
}
//RF02 � Configuraci�n del n�mero de intentos
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

for(i=0;i<max_intentos;i++){
    printf("\n intento %d: INGRESA UN NUMERO ENTRE %d y %d: ", i+1, min_r, max_r);
    scanf("%d", &intento);
// RF03 - Validaci�n de rango
    if(intento< min_r|| intento>max_r){
        printf("NUMERO FUERA DEL RANGO,\n");
        printf("INTENTALO DE NUEVO\n");i--;
        continue;
}
// RF04 - Registro de intentos
lista_intentos[intentos_realizados++]= intento;
if(intento==N_secreto){
    printf("\n FELICIDADES!! ADIVINASTE EL NUMERO SECRETO.\n");
    break;
}else if (intento<N_secreto){
  printf("DEMASIADO BAJO.\n");
}else{
    printf("DEMASIADO ALTO.\n");
}
}
// RF05 - Visualizaci�n de resultados
printf("\n=== Detalles del juego ===\n");
printf("NUMERO SECRETO:%d\n", N_secreto);
for(i=0;i<intentos_realizados;i++){
    printf("%d", lista_intentos[i]);
if(i<intentos_realizados- 1){
    printf(",");
}
}
printf("\n");
return 0;
}
/*CREDITOS:SARAHI MU�OZ*/
