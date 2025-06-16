Algoritmo MenuMatrices
	//Requisitos funcionales del programa:
	//Generar una matriz MxN.
	//Llenar la matriz con valores ingresados por el usuario.
	//Calcular la suma, resta, multiplicacion y potenciacion de las matrices.
	//Presentar los resultados de las operaciones.
    Definir filas, columnas, opcion, i, j, k, m, potencia Como Entero
    Dimension matriz1[10,10], matriz2[10,10], resultado[10,10], temp[10,10]
    Escribir "Ingrese el número de filas (máximo 10): "
    Leer filas
    Escribir "Ingrese el número de columnas (máximo 10): "
    Leer columnas
    Escribir "Ingrese los elementos de la matriz 1:"
    Para i <- 1 Hasta filas Hacer
        Para j <- 1 Hasta columnas Hacer
            Escribir "Elemento [",i,"][",j,"]: "
            Leer matriz1[i,j]
        Fin Para
    Fin Para
    Escribir "Ingrese los elementos de la matriz 2:"
    Para i <- 1 Hasta filas Hacer
        Para j <- 1 Hasta columnas Hacer
            Escribir "Elemento [",i,"][",j,"]: "
            Leer matriz2[i,j]
        Fin Para
    Fin Para
    Repetir
		Escribir "Bienvenidos este progrma realiza operaciones de matriz"
        Escribir "===== MENU ====="
        Escribir "1. Suma de matrices"
        Escribir "2. Resta de matrices"
        Escribir "3. Multiplicación de matrices"
        Escribir "4. Potencia de la primera matriz"
		Escribir "5. Potencia de la segunda matriz"
        Escribir "6. Salir"
        Escribir "Ingrese su opción: "
        Leer opcion
        Segun opcion Hacer
            Caso 1:
                Para i <- 1 Hasta filas Hacer
                    Para j <- 1 Hasta columnas Hacer
                        resultado[i,j] <- matriz1[i,j] + matriz2[i,j]
                    Fin Para
                Fin Para
                Escribir "Resultado de la suma:"
                Para i <- 1 Hasta filas Hacer
                    Para j <- 1 Hasta columnas Hacer
                        Escribir resultado[i,j], " "
                    Fin Para
                    Escribir ""
                Fin Para
            Caso 2:
                Para i <- 1 Hasta filas Hacer
                    Para j <- 1 Hasta columnas Hacer
                        resultado[i,j] <- matriz1[i,j] - matriz2[i,j]
                    Fin Para
                Fin Para
                Escribir "Resultado de la resta:"
                Para i <- 1 Hasta filas Hacer
                    Para j <- 1 Hasta columnas Hacer
                        Escribir resultado[i,j], " "
                    Fin Para
                    Escribir ""
                Fin Para
            Caso 3:
                Si columnas <> filas Entonces
                    Escribir "Para multiplicar matrices, las columnas de la primera deben ser iguales a las filas de la segunda."
                Sino
                    Para i <- 1 Hasta filas Hacer
                        Para j <- 1 Hasta columnas Hacer
                            resultado[i,j] <- 0
                            Para k <- 1 Hasta columnas Hacer
                                resultado[i,j] <- resultado[i,j] + matriz1[i,k] * matriz2[k,j]
                            Fin Para
                        Fin Para
                    Fin Para
                    Escribir "Resultado de la multiplicación:"
                    Para i <- 1 Hasta filas Hacer
                        Para j <- 1 Hasta columnas Hacer
                            Escribir resultado[i,j], " "
                        Fin Para
                        Escribir ""
                    Fin Para
                Fin Si
            Caso 4:
                Si filas <> columnas Entonces
                    Escribir "Solo las matrices cuadradas pueden elevarse a una potencia."
                Sino
                    Escribir "Ingrese la potencia (entero >= 1): "
                    Leer potencia
                    Si potencia = 1 Entonces
                        Escribir "Resultado (potencia 1):"
                        Para i <- 1 Hasta filas Hacer
                            Para j <- 1 Hasta columnas Hacer
                                Escribir matriz1[i,j], " "
                            Fin Para
                            Escribir ""
                        Fin Para
                    Sino
                        // Copiar matriz1 en resultado
                        Para i <- 1 Hasta filas Hacer
                            Para j <- 1 Hasta columnas Hacer
                                resultado[i,j] <- matriz1[i,j]
                            Fin Para
                        Fin Para
                        // Multiplicaciones sucesivas
                        Para k <- 2 Hasta potencia Hacer
                            // Inicializar temp en 0
                            Para i <- 1 Hasta filas Hacer
                                Para j <- 1 Hasta columnas Hacer
                                    temp[i,j] <- 0
                                    Para m <- 1 Hasta columnas Hacer
                                        temp[i,j] <- temp[i,j] + resultado[i,m] * matriz1[m,j]
                                    Fin Para
                                Fin Para
                            Fin Para
                            // Copiar temp en resultado
                            Para i <- 1 Hasta filas Hacer
                                Para j <- 1 Hasta columnas Hacer
                                    resultado[i,j] <- temp[i,j]
                                Fin Para
                            Fin Para
                        Fin Para
                        Escribir "Resultado de la potencia:"
                        Para i <- 1 Hasta filas Hacer
                            Para j <- 1 Hasta columnas Hacer
                                Escribir resultado[i,j], " "
                            Fin Para
                            Escribir ""
                        Fin Para
                    Fin Si
                Fin Si
			Caso 5:
                Si filas <> columnas Entonces
                    Escribir "Solo las matrices cuadradas pueden elevarse a una potencia."
                Sino
                    Escribir "Ingrese la potencia (entero >= 1): "
                    Leer potencia
                    Si potencia = 1 Entonces
                        Escribir "Resultado (potencia 1):"
                        Para i <- 1 Hasta filas Hacer
                            Para j <- 1 Hasta columnas Hacer
                                Escribir matriz2[i,j], " "
                            Fin Para
                            Escribir ""
                        Fin Para
                    Sino
                        // Copiar matriz2 en resultado
                        Para i <- 1 Hasta filas Hacer
                            Para j <- 1 Hasta columnas Hacer
                                resultado[i,j] <- matriz2[i,j]
                            Fin Para
                        Fin Para
                        // Multiplicaciones sucesivas
                        Para k <- 2 Hasta potencia Hacer
                            // Inicializar temp en 0
                            Para i <- 1 Hasta filas Hacer
                                Para j <- 1 Hasta columnas Hacer
                                    temp[i,j] <- 0
                                    Para m <- 1 Hasta columnas Hacer
                                        temp[i,j] <- temp[i,j] + resultado[i,m] * matriz2[m,j]
                                    Fin Para
                                Fin Para
                            Fin Para
                            // Copiar temp en resultado
                            Para i <- 1 Hasta filas Hacer
                                Para j <- 1 Hasta columnas Hacer
                                    resultado[i,j] <- temp[i,j]
                                Fin Para
                            Fin Para
                        Fin Para
                        Escribir "Resultado de la potencia:"
                        Para i <- 1 Hasta filas Hacer
                            Para j <- 1 Hasta columnas Hacer
                                Escribir resultado[i,j], " "
                            Fin Para
                            Escribir ""
                        Fin Para
                    Fin Si
                Fin Si
            Caso 6:
                Escribir "Saliendo del programa... Nos vemos pronto"
            De Otro Modo:
                Escribir "Opción inválida. Intente de nuevo."
        Fin Segun
    Hasta Que opcion = 6
FinAlgoritmo