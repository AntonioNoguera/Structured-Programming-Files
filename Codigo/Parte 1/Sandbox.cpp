#include <stdio.h>

int main() {
    // Definir una variable de tipo int
    int numero = 42;

    // Definir un puntero void y asignarle la dirección de la variable int
    void *punteroVoid = &numero;

    // Para acceder al valor almacenado en el puntero void, es necesario realizar una conversión de tipo
    // En este caso, convertimos el puntero void de nuevo a un puntero int y luego dereferenciamos para obtener el valor
    int *punteroInt = (int *)punteroVoid;
    int valor = *punteroInt;

    // Imprimir el valor
    printf("El valor almacenado es: %d\n", valor);

    return 0;
}
