//Ej 1  Crea una funci�n para cada operaci�n aritm�tica (suma, resta, multiplicaci�n, divisi�n) y 
// permite al usuario realizar c�lculos entre 2 n�meros

#include <stdio.h>  
#include <stdlib.h>
#include <windows.h>

#include "cUtils.h"

float suma(float argA, float argB){
	return (argA + argB);
}

float resta(float argA, float argB){
	return (argA - argB);
}

float multiplicacion(float argA, float argB){
	return (argA * argB);
}

float division(float argA, float argB){
	if( argB == 0){
		return argB;
	}
	return (argA / argB);		
}

int main(){  
	//Definici�n de los tipos de datos requeridos
	CampoDeInformacion argumentoA = {
		{ 1, 3 },
        "Ingresa el primer numero: ",
        NULL,
        decimal,
        negYpositivos
    };
    
    CampoDeInformacion argumentoB = {
		{ 1, 5 },
        "Ingresa el segundo numero: ",
        NULL,
        decimal,
        negYpositivos
    };
    
    centerTitle("- Operaciones entre dos numeros usando funciones -");
    
    capturarDato(&argumentoA);
    capturarDato(&argumentoB);
    
	CampoDeInformacion operacion = {
		{ 1, 7 },
        "Ingresa la operacion a realiza 0 = SUMA / 1 = RESTA / 2 = MULTIPLICACION / 3 = DIVISION: ",
        NULL,
        entero,
        positivo
    };
	
	
	//Validacion Espec�fica
	do{
		capturarDato(&operacion);
		
		if(atof(operacion.valor)<0 || atof(operacion.valor)>3){
			printf(" La opcion se debe de encontrar entre 0 y 3",164);
			getchar();getchar();
			
		}
	}while(atof(operacion.valor)<0 || atof(operacion.valor)>3);
	
	int operacionSeleccionada = atoi(operacion.valor);
	
	float argA = atof(argumentoA.valor);
	float argB = atof(argumentoB.valor);
	
	
	float resultado = 0;
	
	switch (operacionSeleccionada) {
		case 0:
			resultado = suma(argA,argB);
			break;
			
		case 1:
			resultado = resta(argA,argB);
			break;

		case 2:
			resultado = multiplicacion(argA,argB);
			break;
			
		case 3:
			resultado = division(argA,argB);
			break;
			
		default: 
			break;
	}
	 
	printf("\n El resultado de la operacion es: %0.2f",resultado);
	  
    return 0;
}
