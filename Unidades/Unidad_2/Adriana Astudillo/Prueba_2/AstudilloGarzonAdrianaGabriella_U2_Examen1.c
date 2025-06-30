#include <stdio.h>
#define MAX 100
int main () {
    int num;
    int valor;
    char mat[10];
 int Intento;
//*     RF1: Rango de intentos


int n (Intento I[], int n, int valor) {
    for (int i = 0; i < n; i++)
        if (intento[i].valor == valor) return 1;
    return 0;
}
int main() {
    int min, max, secreto, intMax, val, n = 0;
    Intento intentos[MAX];
    srand(time(NULL));
    printf("Minimo: ");
    scanf("%d", &min);
    printf("Maximo: ");
    scanf("%d", &max);
    if (min >= max) return printf("Rango no valido.\n"), 1;
    secreto = min + rand() % (max - min + 1);
//* RF2: Definir el numero de intentos
    printf("Numero de intentos: ");
    scanf("%d", &intMax);
    if (intMax <= 0 || intMax > MAX) return printf("Numero de intentos invalido.\n"), 1;
//* RF3: Validar el valor ingresado
    while (n < intMax) {
        printf("\nIntento %d - Ingrese un numero (%d-%d): ", n + 1, min, max);
        scanf("%d", &val);

        if (val < min || val > max) {
            printf("Fuera de rango.\n"); continue;
        }
        if (n(intentos, n, val)) {
            printf("Numero repetido.\n"); continue;
        }
//* RF4: Guardar en matriz
        intentos[n].num = n + 1;
        intentos[n].valor = val;

        if (val == secreto) {
            strcpy(intentos[n].res, "Correcto");
            printf("Correcto\n"); n++; break;
        } else {
            strcpy(intentos[n].res, val > secreto ? "alto" : "bajo");
            printf("%s\n", intentos[n].res);
        }
        n++;
    }
// * inprimir resultados
    printf("\nNumero secreto: %d\n", secreto);
    printf("Intento\tValor\tResultado\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%s\n", intentos[i].num, intentos[i].valor, intentos[i].res);

    if (n == intentosMax && strcmp(intentos[n - 1].res, "Correcto") != 0)
        printf("Ya no tienes mas los intentos.\n");

    return 0;
}
 }
