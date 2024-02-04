//Mikes Sandbox

#include<stdio.h>

void contador() {
	//practicamente como declarar una variable global publica ( en la misma clase-fichero, se sobre
	//entiende como publica), wtf no respeta la reasignacion
  static int var_estatica = 0;
  int var_no_estatica = 0;

  var_estatica*++;
  var_no_estatica++;
  
  printf("Estática: %d No estatica: %d\n", var_estatica, var_no_estatica);
}

int main() {
	for( int i=0; i<10; i++ ){
		printf("Calling Function: %d   -    ",i);
		contador();
	}
  
}
