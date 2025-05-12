Proceso Raiz_de_un_numero
	Definir N_1, r, i Como Real
	Escribir 'Ingresar un entero mayor a 0: '
	Leer N_1
	i <- Raiz(N_1)
	r1 <- (i>1) Y (i^2<N_1)
	Si (i>1) Entonces
		Escribir 'La Raiz es: ', i
	FinSi
FinProceso