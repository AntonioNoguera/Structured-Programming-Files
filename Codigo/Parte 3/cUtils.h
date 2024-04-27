#include "cUtils.c"

const bool entero = false;
const bool decimal = true;

const bool positivo = false;
const bool negYpositivos = true;

void gotoxy(dataCord *data);
void clearLine(dataCord *cords); 
void centerTitle(char tituloPrincipal[]);
void errorDeValidacion( dataCord *cords, char mensajeError[]);
void capturarDato( CampoDeInformacion *data);
