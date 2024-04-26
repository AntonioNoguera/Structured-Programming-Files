//Ej3.- Crea un programa que realice la b�squeda de un elemento en un arreglo. 
//Utiliza una funci�n para buscar el elemento y retorna la posici�n si se encuentra o -1 si no est� presente. 
// La funci�n debe recibir el arreglo, el tama�o y el valor a buscar.? 
#include <stdio.h>  
#include <stdlib.h>
#include <windows.h>

#include "cUtils.h"

int sentinelSearch(int arr[], int size, int target) {
    int last = arr[size - 1];
    arr[size - 1] = target;  // Establece el centinela
    int i = 0;

    while (arr[i] != target) {
        i++;
    }

    arr[size - 1] = last;  // Restaura el �ltimo elemento
    if (i < size - 1 || arr[size - 1] == target) {
        return i;  // Elemento encontrado
    }
    return -1;  // Elemento no encontrado
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
	//Definici�n de los tipos de datos requeridos
	CampoDeInformacion arregloSize = {
		{ 1, 3 },
        "Ingresa el numero de valores en tu arreglo: ",
        NULL,
        entero,
        positivo
    };
    
     
     
    centerTitle("- Busqueda en un arreglo -");
	
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
	
	capturarValores(array,arraySize);
	
	CampoDeInformacion target = {
		{ 1, 5 + (2 *( arraySize + 1) ) },
        "Ingresa el numero a buscar en tu arreglo: ",
        NULL,
        entero,
        negYpositivos
    };
    
	capturarDato(&target);
	 
	printf("\n La posicion en el arreglo es: %d , (recordar que la primer posicion es 0)",sentinelSearch(array, arraySize, atoi(target.valor)));
	  
    return 0;
}
