//Ej3 Solicita al usuario 10 números y 
//crea una función para calcular el promedio de estos números.?
#include <stdio.h>  
#include <stdlib.h>
#include <windows.h>

#include "cUtils.h" 

float promedioDatos(int ndatos){
	
	float promedio = 0;
	
	for(int i = 0; i<ndatos; i++){
		
		CampoDeInformacion datoCapturado = {
			{ 1, ((2*i) + 6 )},
	        "Ingresa tu valor: ",
	        NULL,
	        entero,
	        negYpositivos
		};
		
		capturarDato(&datoCapturado);
		
		promedio += atof(datoCapturado.valor);
	}
	
	return promedio / ndatos;
}

int main(){  
	//Definición de los tipos de datos requeridos
	CampoDeInformacion nDatos = {
		{ 1, 3 },
        "Ingresa el numero de valores a promediar: ",
        NULL,
        entero,
        positivo
    };
     
    centerTitle("- Promedio de N datos -");
    
    capturarDato(&nDatos); 
     
	int nDatosCasted = atoi(nDatos.valor); 
	
	printf("\n El promedio de los datos ingresados es: %0.4f",promedioDatos(nDatosCasted));
	  
    return 0;
}
