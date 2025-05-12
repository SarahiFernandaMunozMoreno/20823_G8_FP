Proceso MaximoMinimoMediaAlturas
	// Declaración de variables
	Definir N_1, Sum, Med, Max, Min Como Real;
	Definir contador Como Entero;
	Definir N_0 Como Logico;
	// Inicialización
	Sum <- 0;
	contador <- 0;
	N_0 <- Verdadero;
	// Bucle para leer alturas
	Repetir
		Escribir 'Ingrese una altura: '; //Ingresa un numero negativo para terminar
		Leer N_1;
		Si N_1>=0 Entonces
			// Inicializar maximo y minimo con la primera altura válida
			Si N_0 Entonces
				Max <- N_1;
				Min <- N_1;
				N_0 <- Falso;
			SiNo
				// Actualizar máximo y mínimo
				Si N_1>Max Entonces
					Max <- N_1;
				FinSi
				Si N_1<Min Entonces
					Min <- N_1;
				FinSi
			FinSi
			// Acumular para la media
			Sum <- Sum+N_1;
			contador <- contador+1;
		FinSi
	Hasta Que N_1<0
	// Mostrar resultados
	Si contador>0 Entonces
		Med <- Sum/contador;
		Escribir 'Media de alturas: ', Med;
		Escribir 'Altura máxima: ', Max;
		Escribir 'Altura mínima: ', Min;
	SiNo
		Escribir 'No se ingresaron alturas válidas.';
	FinSi
FinProceso
