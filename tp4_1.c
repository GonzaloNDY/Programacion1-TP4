/*Solicitar el nombre de una persona y almacenarla en una cadena de caracteres al usuario y luego
mostrarla por pantalla. Emplear las diferentes funciones para lectura y presentación por pantalla
y las opciones de juegos de inspección para scanf(), formato de salida para printf()*/

#include <stdio.h>
#define MAX 100

int main(int argc, char *argv[]){
    char nombre[MAX];
    printf("Ingrese el nombre a guardar:\t");
    scanf("%[a-zA-Z]s", nombre);
    printf("\nEl nombre guardado es: %s\n", nombre);
    return 0;
}