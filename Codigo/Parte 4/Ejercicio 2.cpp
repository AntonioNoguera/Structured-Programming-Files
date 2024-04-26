//Ej 2.- Realiza la suma de dos arreglos ingresados por el usuario mediante el uso de funciones.? 
#include <stdio.h>  
#include <stdlib.h>
#include <windows.h>

#include "cUtils.h"

void sumarArreglos(int arrayA[], int arrayB[], int arraySize, int resultado[]) {
	
	
	for(int i=0; i < arraySize; i++){
		resultado[i] = arrayA[i] + arrayB[i];
	}
	 
}

void capturarValores(int array[], int arraySize, int saltoLinea) {
	for(int i = 0; i<arraySize; i++){
		CampoDeInformacion elementoArray = {
			{ 1, (((2 * i) + 6 + (3*saltoLinea) )) },
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
     
    centerTitle("- Calculadora de la suma de dos arreglos -");
	
	//Validacion Específica
	do{
		capturarDato(&arregloSize);
		
		if(atof(arregloSize.valor) == 0){
			printf(" El tama%co del arreglo no puede ser 0.",164);
			getchar();getchar();
		}
	}while(atof(arregloSize.valor)==0);
	
	int arraySize = atoi(arregloSize.valor);
	
	int arrayA[arraySize];
	 
	int arrayB[arraySize];
	
	capturarValores(arrayA, arraySize, 0);
	capturarValores(arrayB, arraySize, arraySize);
	
	int arregloSumado[arraySize];
	
	sumarArreglos(arrayA, arrayB, arraySize, arregloSumado);
	
	
	printf("\n El valor sumado del arreglo es: [");
	for(int i=0; i<arraySize; i++){
		if(i==arraySize-1){
			printf("%d] ",arregloSumado[i]);
		}else{
			printf("%d, ",arregloSumado[i]); 
		}
		
	}
	
    return 0;
}
