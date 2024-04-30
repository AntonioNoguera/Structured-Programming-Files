//Ej4 Solicita al usuario la temperatura en grados Celsius  y crea una función para convertir estas unidades a grados Fahrenheit.?
#include <stdio.h>  
#include <stdlib.h>
#include <windows.h>

#include "cUtils.h" 

float conversionFarenheit(float datoCelsius){
	
	float promedio = 0; 
	
	return (datoCelsius * (9.0/5.0) + 32);
}

int main(){  
	//Definición de los tipos de datos requeridos
	CampoDeInformacion tempCelsius = {
		{ 1, 3 },
        "Ingresa la temperatura en grados celcius: ",
        NULL,
        entero,
        positivo
    };
     
    centerTitle("- Convertir de Celsius a Farenheit -");
    
    capturarDato(&tempCelsius);  
	
	printf("\n La temperatura en grados celsius equivale a : %0.4f grados farenheit",conversionFarenheit(atof(tempCelsius.valor)));
	  
    return 0;
}
