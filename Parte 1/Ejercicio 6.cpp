////Pregunta al usuario la distancia recorrieda enKm, el tiempo en horas, Velocidad promedio por hora
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
	 					
						 (data);   
					}
				}
					
			}
		}
	}
	
	// Pendiente regvisar
	// Asignar memoria din�mica para almacenar el valor ingresado
    data->valor = (char *)malloc(strlen(strHelper) + 1); // +1 para el car�cter nulo
    if (data->valor == NULL) {
        // Manejo de error si malloc falla
        exit(EXIT_FAILURE);
    }
    
    // Copiar el valor ingresado en el espacio de memoria asignado
    strcpy(data->valor, strHelper);

	return ; 
 }
 
 int main(){  
	//Definici�n de los tipos de datos requeridos
	struct CampoDeInformacion masa = {
		{ 1, 3 },
        "Ingrese la distancia recorrida en Kilometros: ",
        NULL,
        decimal,
        positivo
    };
    
    struct CampoDeInformacion peso = {
		{ 1, 5 },
        "Ingrese el numero de horas en la que se recorrio la distancia: ",
        NULL,
        decimal,
        positivo
    };
    
    struct CampoDeInformacion altura = {
		{ 1, 5 },
        "Ingrese el numero de horas en la que se recorrio la distancia: ",
        NULL,
        decimal,
        positivo
    };
    
    
    centerTitle("- Calculadora de Indice de Masa Corporal -");
	
	do{
		capturarDato(&distanciaKm);
		
		if(atof(distanciaKm.valor) == 0){
			printf("El valor no puede ser 0");
			getchar();getchar();
		}
		
	}while(atof(distanciaKm.valor) == 0);
	
	do{
		capturarDato(&tiempoHoras);
		
		if(atof(tiempoHoras.valor) == 0 ){
			printf("El valor no puede ser 0");
			getchar();getchar();
		}
	}while(atof(tiempoHoras.valor) == 0 );
	
	struct dataCord final = { 1, 7 }; gotoxy(&final);
	
	float valorFinal = atof(distanciaKm.valor) / atof(tiempoHoras.valor);
	
	printf("La velocidad promedio fue: %0.4f km/h",valorFinal);
 }
