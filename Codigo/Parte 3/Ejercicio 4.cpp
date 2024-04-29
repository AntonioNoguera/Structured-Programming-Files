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
        "Ingresa el numero de valores a promediar: ",
        NULL,
        entero,
        positivo
    };
     
    centerTitle("- Operaciones entre dos numeros usando funciones -");
    
    capturarDato(&tempCelsius);  
	
	printf("\n El promedio de estos datos es: %0.4f",conversionFarenheit(atof(tempCelsius.valor)));
	  
    return 0;
}
