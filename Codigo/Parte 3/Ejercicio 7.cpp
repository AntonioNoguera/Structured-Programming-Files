//E 7 Un individuo invierte en un banco un capital específico y quiere saber cuánto obtendrá al }
// cabo de cierto tiempo, si el dinero se coloca a una determinada tasa de interés mensual. 
//Escribe el programa correspondiente recuerda hacer uso de una función. 
#include <stdio.h>  
#include <stdlib.h>
#include <windows.h>
#include "cUtils.h" 

float DineroFinal(float dinero, float tiempo, float tasa){ 
	return dinero * (1 + tiempo * (tasa/100));
}

int main(){  
	//Definición de los tipos de datos requeridos Valor maximo soportado 20! 
	
	CampoDeInformacion dinero = {
		{ 1, 3 },
        "Ingresa la cantidad de dinero: ",
        NULL,
        entero,
        positivo
    };

	CampoDeInformacion tiempo = {
		{ 1, 5 },
        "Ingresa el numero de meses en el que se plantea invertir: ",
        NULL,
        entero,
        positivo
    };
    
    CampoDeInformacion tasa = {
		{ 1, 7 },
        "Ingresa la tasa mensual de interes: ",
        NULL,
        entero,
        positivo
    };
	     
    centerTitle("- Calculadora de capitual invertido -");
    
    capturarDato(&dinero);  
    capturarDato(&tiempo);  
    capturarDato(&tasa);  
	 
	printf("\n El Capital monetario final equivale a: %0.4f ",
	
	DineroFinal(
		atof(dinero.valor),
		atof(tiempo.valor),
		atof(tasa.valor)
	));
	  
    return 0;
}
