//Ej 2.- Realiza la suma de dos arreglos ingresados por el usuario mediante el uso de funciones.?
#include <stdio.h>  
#include <stdlib.h>
#include <windows.h>

void sumarArreglos () {
	
}

void generarArreglo () {
	
}

int main(){  
	//Definici�n de los tipos de datos requeridos
	CampoDeInformacion precio = {
		{ 1, 3 },
        "Ingresa el precio del producto: ",
        NULL,
        decimal,
        positivo
    };
    
    CampoDeInformacion tipoUsuario = {
		{ 1, 5 },
        "Ingresa el tipo de usuario 1 = No afiliado, 2 = Afiliado, 3 = Ejecutivo: ",
        NULL,
        entero,
        positivo
    };
    
    centerTitle("- Calculadora del precio final de un producto, dado un tipo de usuario -");
	
	
	//Validacion Espec�fica
	do{
		capturarDato(&precio);
		
		if(atof(precio.valor)==0){
			printf(" El precio no puede ser 0.");
			getchar();getchar();
		}
	}while(atof(precio.valor)==0);
	
	//Validdacion Especifica!
	do{
		capturarDato(&tipoUsuario);
		
		if(atoi(tipoUsuario.valor)<1 || atoi(tipoUsuario.valor)>3){
			printf(" El valor debe de ser desde 1 hasta 3, intenta nuevamente");
			getchar();getchar();
		}
	}while(atoi(tipoUsuario.valor)<1 || atoi(tipoUsuario.valor)>3);
	
	
	
	//Codificaci�n espec�fica
	
	float precioCrudo = atof(precio.valor);
	int numUsuario = atoi(tipoUsuario.valor); 
	 
    
    return 0;
}
