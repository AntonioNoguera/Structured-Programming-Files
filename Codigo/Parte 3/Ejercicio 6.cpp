//Ej6 Construye programa en C que, al recibir como dato un 
// número entero N, calcule el factorial de dicho número mediante el uso de una función.?
#include <stdio.h>  
#include <stdlib.h>
#include <windows.h>

#include "cUtils.h" 

unsigned long long factorial(unsigned long long datoFact){
	if(datoFact != 1){
		return datoFact * factorial(datoFact-1);
	}else{ 
		return 1;
	}
}

int main(){  
	//Definición de los tipos de datos requeridos
	//Valor maximo soportado 20! 
	
	CampoDeInformacion precio = {
		{ 1, 3 },
        "Ingresa el numero a calcular el factorial: ",
        NULL,
        entero,
        positivo
    };
     
    centerTitle("- Calculadora Factorial -");
    
    capturarDato(&precio);  
	 
	printf("\n El factorial del valor es: %llu ",factorial(atol(precio.valor)));
	  
    return 0;
}
