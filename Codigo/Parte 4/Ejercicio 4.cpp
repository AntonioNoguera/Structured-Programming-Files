//Ej4.- Desarrolla un programa que calcule el producto de dos matrices bidimensionales. 
//Utiliza funciones para la lectura de matrices, el cálculo del producto y la impresión del resultado.
#include <stdio.h> 
#include <stdlib.h>
#include <windows.h>

#include "cUtils.h"

int bDimention = 4;

void multiplicarMatrices(int matA[][bDimention], int matB[][bDimention], int matB[][bDimention], int size) { 
	
}

void capturarValores(int array[][bDimention], int arraySize) {
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
	CampoDeInformacion dimensionMatriz = {
		{ 1, 3 },
        "Ingresa la dimension de tus matrices cuadradas: ",
        NULL,
        entero,
        positivo
    };
     
    centerTitle("- Multiplicacion de dos matrices de mismo orden -");
	
	//Validacion Específica
	do{
		capturarDato(&dimensionMatriz);
		
		if(atof(dimensionMatriz.valor) == 0) {
			printf(" El tama%co de la matriz no puede ser 0.",164);
			getchar();getchar();
		}
		
	}while(atof(dimensionMatriz.valor)==0);
	
	bDimention = atoi(dimensionMatriz.valor);
	
	int dMatriz = atoi(dimensionMatriz.valor);
	
	int matrizA[dMatriz][dMatriz], matrizB[dMatriz][dMatriz], matrizC[dMatriz][dMatriz]; 
	
	capturarMatriz(matrizA, dMatriz); 
	capturarMatriz(matrizB, dMatriz); 
	
	
	//multiplicarMatrices(matrizA, matrizB, matrizC, dMatriz);
	     
//	printf("\n La posicion en el arreglo es: %d , (recordar que la primer posicion es 0)",sentinelSearch(array, arraySize, atoi(target.valor)));
	  
    return 0;
}
