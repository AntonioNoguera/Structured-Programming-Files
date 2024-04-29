//Ej2  Solicita el radio al usuario y crea una funci�n que nos de 
// como resultado el �rea y el per�metro de un c�rculo. 
#include <stdio.h>  
#include <stdlib.h>
#include <windows.h>

#include "cUtils.h"

const float pi = 3.14159265359;

float funcionPerimetroArea(float radio, float *perimetro, float *area){
	*perimetro = pi * (2*radio);
	
	*area = pi* (radio * radio);
}

int main(){  
	//Definici�n de los tipos de datos requeridos
	CampoDeInformacion radio = {
		{ 1, 3 },
        "Ingresa el numero de valores en tu arreglo: ",
        NULL,
        entero,
        positivo
    };
     
    centerTitle("- Operaciones entre dos numeros usando funciones -");
    
    capturarDato(&radio); 
    
    float perimetro = 0, area = 0;
	 
	float radioCasted = atof(radio.valor); 
	
	funcionPerimetroArea(radioCasted, &perimetro, &area);
	
	printf("\n Con el Radio %0.4f tu perimetro es: %0.4f y el area: %0.4f",radioCasted, perimetro, area);
	  
    return 0;
}
