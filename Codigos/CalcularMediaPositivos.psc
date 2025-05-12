Proceso CalcularMediaPositivos
	Definir n1, n2, n3, mas, cont, r Como Real
	mas=0
	cont=0
	Escribir "Insertar el Primer numero"
	Leer n1
	Si n1>0 Entonces
		mas = mas+n1
		cont = cont+1
	FinSi
	Escribir "Insertar el Segundo numero"
	Leer n2
	Si n2>0 Entonces
		mas = mas+n2
		cont = cont+1
	FinSi
	Escribir "Insertar el Tercer numero"
	Leer n3
	Si n3>0 Entonces
		mas = mas+n3
		cont = cont+1
	FinSi
	Si cont>0 Entonces
		r = mas/cont
		Escribir 'Media: ', r
	SiNo
		Escribir 'No se introdujeron números positivos.'
	FinSi
FinProceso
