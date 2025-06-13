Algoritmo IntercambiarFilas
    Definir ARREGLO_MAX Como Entero
    ARREGLO_MAX <- 10
    Definir n Como Entero
    Definir i, j Como Entero
    Definir fila_i, fila_j Como Entero
    Definir temp Como Entero
    Dimension mat[ARREGLO_MAX, ARREGLO_MAX]
	
    Escribir "Bienvenidos al programa que intercambia filas de la matriz"
    Escribir ""
    Escribir "Ingrese el tamaño de la matriz cuadrada (max 10): "
    Leer n
	
    Si n <= 0 O n > ARREGLO_MAX Entonces
        Escribir "Tamaño de matriz no válido."
    Sino
        Escribir "Ingrese los elementos de la matriz:"
        Para i <- 1 Hasta n Hacer
            Para j <- 1 Hasta n Hacer
                Escribir "Elemento [", i, "][", j, "]: "
                Leer mat[i, j]
            FinPara
        FinPara
		
        Escribir "Matriz original:"
        Para i <- 1 Hasta n Hacer
            Para j <- 1 Hasta n Hacer
                Escribir Sin Saltar mat[i, j], " "
            Fin Para
            Escribir ""
        FinPara
		
        Escribir "Ingrese el índice de la fila i: "
        Leer fila_i
        Escribir "Ingrese el índice de la fila j: "
        Leer fila_j
		
        Si fila_i < 1 O fila_i > n O fila_j < 1 O fila_j > n Entonces
            Escribir "Índices de fila no válidos."
        Sino
            Para j <- 1 Hasta n Hacer
                temp <- mat[fila_i, j]
                mat[fila_i, j] <- mat[fila_j, j]
                mat[fila_j, j] <- temp
            FinPara
			
            Escribir "Matriz modificada:"
            Para i <- 1 Hasta n Hacer
                Para j <- 1 Hasta n Hacer
                    Escribir Sin Saltar mat[i, j], " "
                Fin Para
                Escribir ""
            FinPara
        FinSi
    FinSi
FinAlgoritmo
