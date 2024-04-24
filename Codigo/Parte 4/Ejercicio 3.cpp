//Ej3.- Crea un programa que realice la b�squeda de un elemento en un arreglo. 
//Utiliza una funci�n para buscar el elemento y retorna la posici�n si se encuentra o -1 si no est� presente. 
// La funci�n debe recibir el arreglo, el tama�o y el valor a buscar.?
#include <stdio.h>  
#include <stdlib.h>
#include <windows.h>

int searchArrayValue() {
	
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
