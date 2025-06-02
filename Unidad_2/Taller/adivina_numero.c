#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int main() {
	bool acierto;
	int intento;
	int n_s;
	int n_u;
	/* Generar un número secreto aleatorio entre 1 y 100 */
	n_s = (rand()%100)+1;
	acierto = false;
	/* Dar 5 intentos al usuario */
	for (intento=1; intento<=5; ++intento) {
		printf("Intento %i: Ingrese un numero entre 1 y 100\n", intento);
		scanf("%i", &n_u);
		/* Verificar si el número adivinado es correcto */
		if (n_u==n_s) {
			printf("¡Felicidades! Has adivinado el numero secreto\n");
			acierto = true;
			intento = 6;
			/* para salir del bucle */
		} else {
			/* Dar una pista al usuario */
			if (n_u<n_s) {
				printf("El numero secreto es mayor que %i\n", n_u);
			} else {
				printf("El numero secreto es menor que %i\n", n_u);
			}
		}
	}
	/* Si el usuario no adivinó el número secreto en 5 intentos */
	if (acierto==false) {
		printf("Lo siento, no has adivinado el numero secreto. El numero secreto era %i\n", n_s);
	}
	return 0;
}
