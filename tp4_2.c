/*Solicitar al usuario el ingreso de una cadena de caracteres que puede contener solamente los
dígitos 0-9, luego presentarla por pantalla. Realizar el ingreso usando scanf() con las opciones de
juego de inspección*/

#include <stdio.h>
#define MAX 100

int main(int argc, char *argv[]){
    char numeros[MAX];
    printf("Ingrese los numeros a guardar:\t");
    scanf("%[1-9]s", numeros);
    printf("\nLos numeros guardados son: %s\n", numeros);
    return 0;
}