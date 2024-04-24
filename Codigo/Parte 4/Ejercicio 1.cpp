//Ej 1.- Escribe un programa que calcule el promedio de un arreglo de números. 
//Utiliza una función para la lectura de datos y otra función para calcular el promedio.?
#include <stdio.h>  
#include <stdlib.h>
#include <windows.h>

#include "cUtils.h"

void calcularPromedio() {
	
}

void capturarValores(int array[], int arraySize) {
	for(int i = 0; i<arraySize; i++){
		CampoDeInformacion elementoArray = {
			{ 1, ((2*i) + 6 )},
	        "Ingresa el valor del arreglo: ",
	        NULL,
	        entero,
	        positivo
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
	
	for(int i=0; i<atoi(arregloSize.valor); i++){
		printf("%d ",array[i]);
	}
	  
	
    return 0;
}
