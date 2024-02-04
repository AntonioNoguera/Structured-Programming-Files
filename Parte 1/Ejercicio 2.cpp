//2. Pide al usuario el monto principal, la tasa de interés y el tiempo en
//años. Calcula y muestra el monto total después de ese tiempo usando la
//fórmula: MontoTotal = Principal + (Principal * Tasa * Tiempo)	
#include <stdio.h>  
#include <windows.h>
  
 void gotoxy(int x,int y){  
	//Funcion fuera de mi autoria
	//no funciona Conio2.h y no recuerdo como se implementaba en devC xd
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
 
 void clearLine(int y){
 	gotoxy(1,y);
 	for(int i=0;i<300;i++){
 		printf(" ");
	}
 }
 
 void errorDeValidacion(int x, int y,char mensajeError[]){ 
 
 	gotoxy(x,y);
 	printf("%s",mensajeError);
 	getchar();
 	getchar();
 }

void validarDatoDecimal(int x, int y, char fbackString[],float *varValidada,bool intFlag, bool negFlag){ 

 	static char strHelper[100];  
 	
 	int pointCount = 0;
 	int dashCount = 0;
 	
 	//clean line
 	gotoxy(x,y);clearLine(y); 
 	
 	//print n capture
	gotoxy(x,y);
 	printf("%s", fbackString);
 	scanf("%s", strHelper);
 	
 	gotoxy(0,20);
 	printf("ESTADO INICIAL DE LA CADENA: %s /",strHelper);
 	printf("Longitud de la cadena: %d /  ",strlen(strHelper));
 	
 	//validate str
	for(int i=0; i<strlen(strHelper);i++){
 		if((strHelper[i] > 57 || strHelper[i] < 45 ) || strHelper[i] == 47){
 			//Out of Bounds 
 			errorDeValidacion(x,y,"El valor solo puede ser un numero de con difitos 0-9, '-' y '.' .");
 			validarDatoDecimal(1, 4, fbackString,varValidada, intFlag, negFlag);  
 			
		}else{
			//Over here starts the manual validation (Floats n Negatives)
			if(strHelper[i] == 46){
				if(){
					errorDeValidacion(x,y,"El formato del numero debe ser congruente. Multiples '.' encontrados .");
	 				validarDatoDecimal(1, 4, "Ingresa el monto principal: ",varValidada);	
				}else{
					dashCount++; 
					if(++pointCount > 1){ 
						errorDeValidacion(x,y,"El formato del numero debe ser congruente. Multiples '.' encontrados .");
	 					validarDatoDecimal(1, 4, "Ingresa el monto principal: ",varValidada); 
					}	
				}
				
			}
			
			if(strHelper[i] == 45){
				//the true, will be replaced with a flag of negative or int values
				if(true){
					errorDeValidacion(x,y,"Error: El valor debe de ser positivo.");
 					validarDatoDecimal(1, 4, "Ingresa el monto principal: ",varValidada); 
				}else{
					if(++dashCount > 1){ 
						errorDeValidacion(x,y,"El formato del numero debe ser congruente. Multiples '-' encontrados .");
	 					validarDatoDecimal(1, 4, "Ingresa el monto principal: ",varValidada); 
					}
				}
					
			}
		}
	}
	
	printf("%s",strHelper);
	*varValidada = atof(strHelper); 
	return ; 
 }
 
 
 
 int main(){
	float montoPrincipal,tasaInteres, montoTotal;
	int tiempo;
 
	printf("~ Calculo del Monto Total ~\n");
	//No negativo, flotante
	validarDatoDecimal(1, 4, "Ingresa el monto principal: ",&montoPrincipal,true,false);
	
	//no negativo, flotante
	//validarDatoDecimal(1, 4, "Ingresa el monto principal: ",&tasa);
	
	//no negativo, entero
	
	//validarDatoDecimal(1, 4, "Ingresa el monto principal: ",&tiempo);
	
	
	
	
	
	
	/*
	printf("Ingresa la tasa de interés: ");
	scanf("%f",&tasaInteres);
	
	
	printf("Ingresa el tiempo en años: ");
	scanf("%d",&tiempo);
	
	printf("Capturados: %f %f %d",montoPrincipal, tasaInteres, tiempo);
	
	montoTotal = montoPrincipal + (montoPrincipal * tasaInteres * (float)tiempo);
	
	printf("Resultado %f",montoTotal);
	*/
 }
