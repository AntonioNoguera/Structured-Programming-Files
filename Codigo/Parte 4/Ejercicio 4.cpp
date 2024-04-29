//Ej4.- Desarrolla un programa que calcule el producto de dos matrices bidimensionales. 
//Utiliza funciones para la lectura de matrices, el cálculo del producto y la impresión del resultado.
#include <stdio.h> 
#include <stdlib.h>
#include <windows.h>

#include "cUtils.h" 

int** liberarMemoria(int** matriz , int dimensiones) {
	
	for (int i = 0; i < dimensiones; i++) {
        free(matriz[i]);
    }
    
    free(matriz);
}

int** capturarValores(int** matriz , int dimensiones) {
	
	for (int i = 0; i < dimensiones; i++) {
        for (int j = 0; j < dimensiones; j++) {
            matriz[i][j] = i + j; 
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    return matriz;
}


int** crearMatriz(int numFilas, int numColumnas) {
    int **matriz;
    int i;

    // Asignar memoria para el arreglo de punteros (filas)
    matriz = (int**) malloc(numFilas * sizeof(int*));  // Cast explícito necesario en C++ 
    if (matriz == NULL) {
        fprintf(stderr, "Error de asignación de memoria para las filas\n");
        return NULL;
    }

    // Asignar memoria para cada fila
    for (i = 0; i < numFilas; i++) {
        matriz[i] = (int*) malloc(numColumnas * sizeof(int));  // Cast explícito necesario en C++
        if (matriz[i] == NULL) {
            fprintf(stderr, "Error de asignación de memoria para la fila %d\n", i);
            // Liberar memoria asignada hasta el momento antes de salir
            for (int k = 0; k < i; k++) {
                free(matriz[k]);
            }
            free(matriz);
            return NULL;
        }
    }

    return capturarValores(matriz, numFilas);
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
	
	
	int dimensionCast = atoi(dimensionMatriz.valor);
	
	int **matrizA = crearMatriz(dimensionCast, dimensionCast);
	//int **matrizB = crearMatriz(dimensionCast);
	
	//int **matrizC;
	
	/*
	int dMatriz = atoi(dimensionMatriz.valor);
	
	int matrizA[dMatriz][dMatriz], matrizB[dMatriz][dMatriz], matrizC[dMatriz][dMatriz]; 
	
	capturarMatriz(matrizA, dMatriz); 
	capturarMatriz(matrizB, dMatriz); 
	
	*/
	//multiplicarMatrices(matrizA, matrizB, matrizC, dMatriz);
	     
//	printf("\n La posicion en el arreglo es: %d , (recordar que la primer posicion es 0)",sentinelSearch(array, arraySize, atoi(target.valor)));
	  
    return 0;
}
