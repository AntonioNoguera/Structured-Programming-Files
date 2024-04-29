//E 7 Un individuo invierte en un banco un capital específico y quiere saber cuánto obtendrá al }
// cabo de cierto tiempo, si el dinero se coloca a una determinada tasa de interés mensual. 
//Escribe el programa correspondiente recuerda hacer uso de una función. 
#include <stdio.h>  
#include <stdlib.h>
#include <windows.h>
#include "cUtils.h" 

float DineroFinal(float dinero, float tiempo, float tasa){ 
	return dinero * tiempo * (tasa/100);
}

int main(){  
	//Definición de los tipos de datos requeridos Valor maximo soportado 20! 
	
	CampoDeInformacion dinero = {
		{ 1, 3 },
        "Ingresa el numero a calcular el factorial: ",
        NULL,
        entero,
        positivo
    };

	CampoDeInformacion tiempo = {
		{ 1, 5 },
        "Ingresa el numero a calcular el factorial: ",
        NULL,
        entero,
        positivo
    };
    
    CampoDeInformacion tasa = {
		{ 1, 7 },
        "Ingresa el numero a calcular el factorial: ",
        NULL,
        entero,
        positivo
    };
	     
    centerTitle("- Calculadora Factorial -");
    
    capturarDato(&dinero);  
    capturarDato(&tiempo);  
    capturarDato(&tasa);  
	 
	printf("\n El factorial del valor es: %0.4f ",
	
	DineroFinal(
		atof(dinero.valor),
		atof(tiempo.valor),
		atof(tasa.valor)
	));
	  
    return 0;
}
