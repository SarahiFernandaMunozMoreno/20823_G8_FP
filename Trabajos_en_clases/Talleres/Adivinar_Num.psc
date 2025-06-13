Algoritmo AdivinarNumero
    Definir N_S, intento,N_U Como Entero
    Definir acierto Como Logico
    N_S <- azar(100) + 1
    acierto <- Falso
    Para intento <- 1 Hasta 5 Hacer
        Escribir "Intento ", intento, ": Ingrese un número entre 1 y 100"
        Leer N_U
        Si N_U = N_S Entonces
            Escribir "¡Felicidades! Has adivinado el número secreto"
            acierto <- Verdadero
            intento <- 6
        Sino
            Si N_U < N_S Entonces
                Escribir "El número secreto es mayor que ", N_U
            Sino
                Escribir "El número secreto es menor que ", N_U
            Fin Si
        Fin Si
    Fin Para
    Si acierto = Falso Entonces
        Escribir "Lo siento, no has adivinado el número secreto. El número secreto era ", N_S
    Fin Si
FinAlgoritmo
