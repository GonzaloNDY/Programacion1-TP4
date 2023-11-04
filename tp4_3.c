/*Solicitar al usuario el ingreso de una cadena de caracteres que puede contener solamente
caracteres alfabéticos, luego presentarla por pantalla. Realizar el ingreso usando scanf() con las
opciones de juego de inspección*/

#include <stdio.h>
#define MAX 100

int main(int argc, char *argv[]){
    char palabra[MAX];
    printf("Ingrese la palabra a guardar:\t");
    scanf("%[a-zA-Z]s", palabra);
    printf("\nLa palabra guardada es: %s\n", palabra);
    return 0;
}