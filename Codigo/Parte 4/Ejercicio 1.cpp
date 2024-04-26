//Ej 1.- Escribe un programa que calcule el promedio de un arreglo de números. 
//Utiliza una función para la lectura de datos y otra función para calcular el promedio.?
#include <stdio.h>  
#include <stdlib.h>
#include <windows.h>

#include "cUtils.h"

float promediarArreglo(int array[], int arraySize) {
	float finalProm = 0;
	
	for(int i=0; i < arraySize; i++){
		finalProm += array[i];
	}
	
	return finalProm/arraySize;
}

void capturarValores(int array[], int arraySize) {
	for(int i = 0; i<arraySize; i++){
		CampoDeInformacion elementoArray = {
			{ 1, ((2*i) + 6 )},
	        "Ingresa el valor del arreglo: ",
	        NULL,
	        entero,
	        negYpositivos
		};
		
		capturarDato(&elementoArray);
	 
		array[i] = atoi(elementoArray.valor);
	}
}

int main(){  
	//Definición de los tipos de datos requeridos
	CampoDeInformacion arregloSize = {
		{ 1, 3 },
        "Ingresa el numero de valores en tu arreglo: ",
        NULL,
        entero,
        positivo
    };
     
    centerTitle("- Calculadora del promedio en un arreglo -");
	
	//Validacion Específica
	do{
		capturarDato(&arregloSize);
		
		if(atof(arregloSize.valor)==0){
			printf(" El tama%co del arreglo no puede ser 0.",164);
			getchar();getchar();
		}
	}while(atof(arregloSize.valor)==0);
	
	int arraySize = atoi(arregloSize.valor);
	
	int array[arraySize];
	
	capturarValores(array, arraySize);
	
	float promedio = promediarArreglo(array, arraySize);
	
	printf("\n El promedio del arreglo capturado equivale a %0.2f",promedio);
	  
	
    return 0;
}
