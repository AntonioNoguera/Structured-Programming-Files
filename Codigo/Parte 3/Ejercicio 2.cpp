//Ej2  Solicita el radio al usuario y crea una funci�n que nos de 
// como resultado el �rea y el per�metro de un c�rculo. 

#include <stdio.h>  
#include <stdlib.h>
#include <windows.h>

#include "cUtils.h"



float funcionPerimetroArea(){
	
}

int main(){  
	//Definici�n de los tipos de datos requeridos
	CampoDeInformacion argumentoA = {
		{ 1, 3 },
        "Ingresa el numero de valores en tu arreglo: ",
        NULL,
        entero,
        positivo
    };
    
    CampoDeInformacion argumentoB = {
		{ 1, 5 },
        "Ingresa el numero de valores en tu arreglo: ",
        NULL,
        entero,
        negYpositivos
    };
    
    centerTitle("- Operaciones entre dos numeros usando funciones -");
    
    capturarDato(&argumentoA);
    capturarDato(&argumentoB);
    
	
	//Validacion Espec�fica
	do{
		capturarDato(&operacion);
		
		if(atof(operacion.valor)<0 || atof(operacion.valor)>3){
			printf(" El tama%co del arreglo no puede ser 0.",164);
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
