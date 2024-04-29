//Ej 5 Crea un programa que calcule el precio final de un producto con descuento mediante el uso de funciones, 
//dada su tasa de descuento y precio original.?
#include <stdio.h>  
#include <stdlib.h>
#include <windows.h>

#include "cUtils.h" 

float descuentoFinal(float precioOriginal, float tasaDescuento){
	return precioOriginal * (1 - tasaDescuento/100);
}

int main(){  
	//Definición de los tipos de datos requeridos
	CampoDeInformacion precio = {
		{ 1, 3 },
        "Ingresa el numero de valores a promediar: ",
        NULL,
        entero,
        positivo
    };
    
    CampoDeInformacion descuento = {
		{ 1, 5 },
        "Ingresa el numero de valores a promediar: ",
        NULL,
        entero,
        positivo
    };
     
    centerTitle("- Operaciones entre dos numeros usando funciones -");
    
    capturarDato(&precio); 
	capturarDato(&descuento);   
	
	printf("\n El precio final es: %0.4f",descuentoFinal(atof(precio.valor), atof(descuento.valor)));
	  
    return 0;
}
