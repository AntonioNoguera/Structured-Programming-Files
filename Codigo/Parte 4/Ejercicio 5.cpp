//Ej 5.- Escribe un programa que calcule el promedio de cada columna en una matriz bidimensional. 
//Utiliza funciones para la lectura de la matriz y el cálculo del promedio, y luego imprime los resultados.
#include <stdio.h> 
#include <stdlib.h>
#include <windows.h>

#include "cUtils.h" 

void imprimirMatriz(int** matriz, int dimension){
	
	printf("\n \n Resultado Final");
	for(int i=0; i<dimension; i++){ 
		printf("\n \n");
		for(int j=0; j<dimension; j++){
			printf(" %d  ",matriz[j][i]);
		}
	}
}

int** liberarMemoria(int** matriz , int dimensiones) {
	
	for (int i = 0; i < dimensiones; i++) {
        free(matriz[i]);
    }
    
    free(matriz);
}

int** capturarValores(int** matriz , int dimensiones, int nMatriz) {
	
	
	for (int i = 0; i < dimensiones; i++) {
        for (int j = 0; j < dimensiones; j++) {
        	
        	CampoDeInformacion datoMatriz = {
				{ 1 + i*4, j*2 + 6 + (2*dimensiones*nMatriz) },
		        "",
		        NULL,
		        entero,
		        negYpositivos
		    };
		    
        	capturarDato(&datoMatriz);
        	
            matriz[i][j] = atoi(datoMatriz.valor); 
        } 
    }
    
    return matriz;
}

int** crearMatriz(int numFilas, bool leerValores, int nMatriz) {
    int **matriz;
    int i;
    
    matriz = (int**) malloc(numFilas * sizeof(int*));
    if (matriz == NULL) {
        fprintf(stderr, "Error de asignación de memoria para las filas\n");
        return NULL;
    }
    
    for (i = 0; i < numFilas; i++) {
        matriz[i] = (int*) malloc(numFilas * sizeof(int)); 
        if (matriz[i] == NULL) {
            fprintf(stderr, "Error de asignación de memoria para la fila %d\n", i);
            
            for (int k = 0; k < i; k++) {
                free(matriz[k]);
            }
            free(matriz);
            return NULL;
        }
    }

	if(leerValores){
		return capturarValores(matriz, numFilas,nMatriz);	
	}else{
		return matriz;
	}
	
}

void promediarColumnas(int** matrizA, int dimensionMatriz){
	int **matrizResultante = crearMatriz(dimensionMatriz,false,0);
	
	
	for (int i = 0; i < dimensionMatriz; i++) {
		float promedio = 0.0;
        for (int j = 0; j < dimensionMatriz; j++) {
            promedio += matrizA[i][j];
        }
        printf("\nEl promedio de la columna %d es: %0.4f",i+1,promedio/dimensionMatriz);
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
	
	
	int dimensionCast = atoi(dimensionMatriz.valor);
	
	int **matrizA = crearMatriz(dimensionCast,true,0);  
	
	promediarColumnas(matrizA, dimensionCast); 
	
	liberarMemoria(matrizA, dimensionCast); 
		  
    return 0;
}
