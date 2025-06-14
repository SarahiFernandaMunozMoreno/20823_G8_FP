Algoritmo MatrizInversa
		Definir N, i, j como Entero
		Escribir "Ingrese el tamaño N de la matriz (N x N):"
		Leer N
		
		Dimensionar Mat[N, N] 
		
		// Llenado de la matriz
		Para i <- 1 Hasta N - 1 Hacer
			Para j <- 1 Hasta N - 1 Hacer
				Escribir "Ingrese el elemento [", i, ",", j, "]:"
				Leer Mat[i, j]
			Fin Para
		Fin Para
		
		// Recorrido en orden inverso
		Escribir "Matriz en orden inverso:"
		Para i <- N - 1 Hasta 1 Con Paso -1 Hacer
			Para j <- N - 1 Hasta 1 Con Paso -1 Hacer
				Escribir Mat[i, j]
			Fin Para
		Fin Para
FinAlgoritmo
