//Ej 5.- Escribe un programa que calcule el promedio de cada columna en una matriz bidimensional. 
//Utiliza funciones para la lectura de la matriz y el cálculo del promedio, y luego imprime los resultados.
#include <stdio.h>  
#include <stdlib.h>
#include <windows.h>
int main(){  
	//Definición de los tipos de datos requeridos
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
	
	
	//Validacion Específica
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
	
	
	
	//Codificación específica
	
	float precioCrudo = atof(precio.valor);
	int numUsuario = atoi(tipoUsuario.valor);
	
	dataCord resultadoLine = { 1, 7 }; gotoxy(&resultadoLine);
	printf("El precio para el usuario ");
	
	switch(numUsuario) {
        case 1:
        	printf("no afiliado %0.4f, no hay descuento",precioCrudo);
            break;
            
        case 2:
        	precioCrudo = precioCrudo - precioCrudo*.10;
        	printf("afiliado %0.4f, descuento de 10%c",precioCrudo,37);
            break;
            
        case 3: 
        	precioCrudo = precioCrudo - precioCrudo*.30;
        	printf("ejecutivo %0.4f , descuento de 30%c",precioCrudo,37);
            break;
            
        default:
            printf("Sobrepasaste la validacion increible!");
            break;
    }
    
    return 0;
 }
