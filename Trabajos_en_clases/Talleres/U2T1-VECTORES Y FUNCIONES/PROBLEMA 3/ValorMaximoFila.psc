Algoritmo ValorMaximoFila
	Definir c, f, i, j, max, fila_i Como Entero
	Dimensionar Mat[10,10]
	max <- 10
	Escribir "Bienvenidos al programa que te dirá el valor máximo de una fila"
	Escribir ""
	Escribir "Ingrese el número de filas"
	Leer f
	Escribir "Ingrese el número de Columnas"
	Leer c
	Si f > max O c > max O f <= 0 O c <= 0 Entonces
		Escribir "Dimensiones inválidas."
	Sino
		Escribir "Ingrese los elementos de la matriz por filas:"
		Para i <- 1 Hasta f-1 Hacer
			Para j <- 1 Hasta c-1 Hacer
				Escribir "Elemento [", i, "][", j, "]:"
				
				Leer Mat[i,j]
			FinPara
		FinPara
		Escribir "Matriz original:"
		Para i <- 1 Hasta f-1 Hacer
			Para j <- 1 Hasta c-1 Hacer
				Escribir Sin Saltar Mat[i,j], " "
			FinPara
			Escribir "" // Salto de línea
		FinPara
		Escribir "Ingrese la fila a consultar:"
		Leer fila_i
		Si fila_i >= 0 Y fila_i < f Entonces
			max <- Mat[fila_i,0]
			Para j <- 1 Hasta c-1 Hacer
				Si Mat[fila_i,j] > max Entonces
					max <- Mat[fila_i,j]
				FinSi
			FinPara
			Escribir "El valor máximo de la fila ", fila_i, " es: ", max
		Sino
			Escribir "Fila fuera de rango."
		FinSi
	FinSi
FinAlgoritmo