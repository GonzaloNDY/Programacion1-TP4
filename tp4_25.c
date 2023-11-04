/*Escribe un programa en C que reciba una cadena de caracteres como argumento en la función
main y muestre la longitud de la cadena por pantalla*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    if (argc != 2){
        printf("\nDebe ingresarse solo 1 argumento en la llamada al programa (sin incluir el nombre)\n");
        return 0;
    }
    printf("\nLa cadena ingresada tiene una longitud lógica de %d\n", strlen(argv[1]));
    return 0;
}