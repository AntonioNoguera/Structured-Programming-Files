//Ej2  Solicita el radio al usuario y crea una función que nos de 
// como resultado el área y el perímetro de un círculo. 
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
	//Definición de los tipos de datos requeridos
	CampoDeInformacion radio = {
		{ 1, 3 },
        "Ingresa el radio de tu circulo:  ",
        NULL,
        entero,
        positivo
    };
     
    centerTitle("- Calcular Area y Perimetro de un Circulo Usando Funciones -");
    
    capturarDato(&radio); 
    
    float perimetro = 0, area = 0;
	 
	float radioCasted = atof(radio.valor); 
	
	funcionPerimetroArea(radioCasted, &perimetro, &area);
	
	printf("\n Con el Radio %0.4f tu perimetro es: %0.4f y el area: %0.4f",radioCasted, perimetro, area);
	  
    return 0;
}
