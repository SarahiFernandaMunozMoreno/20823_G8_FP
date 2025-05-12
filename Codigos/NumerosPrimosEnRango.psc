Algoritmo NumerosPrimosEnRango
    Definir N_1, N_2, i, j Como Entero;
    Definir esPrimo Como Logico;
    
    Escribir "Ingrese el primer número (límite inferior):";
    Leer N_1;
    
    Escribir "Ingrese el segundo número (límite superior):";
    Leer N_2;
    
    Escribir "Números primos entre ", N_1, " y ", N_2, ":";
    
    // Asegurar que _1 sea menor que _2
    Si _1 > _2 Entonces
        Definir temp Como Entero;
        temp <- N_1;
        N_1 <- _2;
        N_2 <- temp;
    FinSi
    
    // Iterar desde _1 hasta _2
    Para i <- N_1 Hasta N_2 Hacer
        // Verificar si i es primo
        esPrimo <- Verdadero;
        
        Si i <= 1 Entonces
            esPrimo <- Falso;
        Sino
            Para j <- 2 Hasta i / 2 Hacer
                Si i % j == 0 Entonces
                    esPrimo <- Falso;
                FinSi
            FinPara
        FinSi
        Si esPrimo Entonces
            Escribir i, " ";
        FinSi
    FinPara
FinAlgoritmo