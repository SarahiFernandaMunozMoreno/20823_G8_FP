Algoritmo JuegoAdivinanza
//Requisitos funcionales del juego:
//Generar una matriz cuadrada de tama o fijo 10x10.
//Llenar la matriz con valores ingresados por el usuario.
//Calcular la suma total de los elementos de la matriz.
//Pedir al jugador que adivine cu l es la suma total.
//Informar si el jugador acert  o no, mostrando la suma correcta si falla.
    Definir ARREGLO_MAX Como Entero
    ARREGLO_MAX <- 100
    Definir c,f,i,j,max,suma,mat, intento Como Entero
    Dimension mat[ARREGLO_MAX, ARREGLO_MAX]
    Definir intentos Como Cadena
    intentos <- ""
    suma <- 0
    max <- 10
	
    Escribir "Bienvenidos a este juego de adivinanza de un numero que se encuentra oculto en la matriz"
    Escribir ""
    Escribir "Ingrese el numero de filas"
    Leer f
    Escribir "Ingrese el numero de Columnas"
    Leer c
	
    Si f > max O c > max O f <= 0 O c <= 0 Entonces
        Escribir "Dimensiones invalidas."
    Sino
        Escribir "Ingrese los elementos de la matriz por filas:"
        Para i <- 1 Hasta f Hacer
            Para j <- 1 Hasta c Hacer
                Escribir "Elemento [", i-1, "][", j-1, "]: "
                Leer mat[i, j]
                suma <- suma + mat[i, j]
            FinPara
        FinPara
		
        Repetir
            Escribir "Adivina que numero salio ^_^ "
            Leer intento
            intentos <- intentos + ConvertirATexto(intento) + ", "
            Si intento = suma Entonces
                Escribir "WOOOO Adivinaste :D"
            Sino
                Escribir "Lo siento no lo lograste T_T"
            FinSi
        Hasta Que intento = suma
		
        Escribir "La suma es: ", suma
        Escribir "Intentos: ", intentos
        Escribir "Total de intentos: ", Longitud(intentos) / 2
    FinSi
FinAlgoritmo
