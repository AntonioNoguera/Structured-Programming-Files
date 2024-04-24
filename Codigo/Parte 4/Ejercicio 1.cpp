//Ej 1.- Escribe un programa que calcule el promedio de un arreglo de n�meros. 
//Utiliza una funci�n para la lectura de datos y otra funci�n para calcular el promedio.?
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
	//Definici�n de los tipos de datos requeridos
	CampoDeInformacion arregloSize = {
		{ 1, 3 },
        "Ingresa el numero de valores en tu arreglo: ",
        NULL,
        entero,
        positivo
    };
     
    centerTitle("- Calculadora del promedio en un arreglo -");
	
	//Validacion Espec�fica
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
