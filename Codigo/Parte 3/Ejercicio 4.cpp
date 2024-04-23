//Ej4 Solicita al usuario la temperatura en grados Celsius  y crea una función para convertir estas unidades a grados Fahrenheit.?

 
#include <stdio.h>  
#include <stdlib.h>
#include <windows.h>

const bool entero = false;
const bool decimal = true;

const bool positivo = false;
const bool negYpositivos = true;

// Main Structures
struct dataCord{
	int x;
	int y;
};

struct CampoDeInformacion{
	struct dataCord dataCord;
	char fallbackString[100];
	char *valor;
	bool permiteDecimal;
	bool permiteNegativ;
};

// Visual UI functions
 void gotoxy(struct dataCord *data){  
	//Funcion fuera de mi autoria
	//no funciona Conio2.h y no recuerdo como se implementaba en devC xd
	HANDLE hcon;  
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
	COORD dwPos;  
	dwPos.X = data->x;  
	dwPos.Y = data->y;  
	SetConsoleCursorPosition(hcon,dwPos);  
 }
 
 void clearLine(struct dataCord *cords){
	gotoxy(cords);
	for(int i=0;i<500;i++){
		printf("%c",32);
	}
 }
 
 void centerTitle(char tituloPrincipal[]){
 	
 	int cordX = (120 - strlen(tituloPrincipal))/2;
 	
 	struct dataCord titulo = { cordX, 1 };
 	
 	gotoxy(&titulo);
 	printf("%s",tituloPrincipal); 
 }
 

void errorDeValidacion(struct dataCord *cords, char mensajeError[]){ 
	clearLine(cords);
	gotoxy(cords);
	printf("%s",mensajeError);
	getchar();
	getchar();
}

// General Validation Function
void capturarDato(struct CampoDeInformacion *data){
 	static char strHelper[100];
 	
 	int pointCount = 0;
 	int dashCount = 0;
 	
 	//clean line
 	gotoxy(&data->dataCord);
	clearLine(&data->dataCord); 
 	
 	//print n capture
	gotoxy(&data -> dataCord);
 	printf("%s", data->fallbackString);
 	scanf("%s", strHelper);
 	
 	//validate str
	for(int i=0; i<strlen(strHelper);i++){
 		if((strHelper[i] > 57 || strHelper[i] < 45 ) || strHelper[i] == 47){
 			//Out of Bounds
 			errorDeValidacion(&data->dataCord, "El valor solo puede ser un numero de con difitos 0-9, '-' y '.' .");
 			capturarDato(data);
		}else{
			//Over here starts the manual validation (Floats n Negatives)
			if(strHelper[i] == 46){
				if(data->permiteDecimal){
					//Allows
					dashCount++; 
					if(++pointCount > 1){ 
						errorDeValidacion(&data -> dataCord, "El formato del numero debe ser congruente. Multiples '.' encontrados .");
	 					capturarDato(data);   
					}
				}else{
					//Doesnt
					errorDeValidacion(&data -> dataCord, "El formato del numero debe ser congruente. Multiples '.' encontrados .");
	 				capturarDato(data); 	
				}
				
			}
			
			if(strHelper[i] == 45){
				//the true, will be replaced with a flag of negative or int values
				if(!data->permiteNegativ){
					//Not allowed
					errorDeValidacion(&data -> dataCord, "Error: El valor debe de ser positivo.");
 					capturarDato(data);   
				}else{
					if(++dashCount > 1){ 
						errorDeValidacion(&data -> dataCord, "El formato del numero debe ser congruente. Multiples '-' encontrados .");
	 					
						capturarDato(data);   
					}
				}
					
			}
		}
	}
	 
    data->valor = (char *)malloc(strlen(strHelper) + 1);
    if (data->valor == NULL) { 
        exit(EXIT_FAILURE);
    }
    
    // Copiar el valor ingresado en el espacio de memoria asignado
    strcpy(data->valor, strHelper);

	return ; 
 }
 
 
 double suma(){
 	
 }
 
 
 
 
 
 
 
 int main(){  
	//Definición de los tipos de datos requeridos
	struct CampoDeInformacion precio = {
		{ 1, 3 },
        "Ingresa el precio del producto: ",
        NULL,
        decimal,
        positivo
    };
    
    struct CampoDeInformacion tipoUsuario = {
		{ 1, 5 },
        "Ingresa el tipo de usuario 1 = No afiliado, 2 = Afiliado, 3 = Ejecutivo: ",
        NULL,
        entero,
        positivo
    };
    
    centerTitle("- Calculadora del precio final de un producto, dado un tipo de usuario -");
	
	do{
		capturarDato(&precio);
		
		if(atof(precio.valor)==0){
			printf(" El precio no puede ser 0.");
			getchar();getchar();
		}
	}while(atof(precio.valor)==0);
	
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
	
	struct dataCord resultadoLine = { 1, 7 }; gotoxy(&resultadoLine);
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
