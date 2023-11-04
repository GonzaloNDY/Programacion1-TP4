/*Ingresar una cadena de caracteres que contenga dos o más palabras separadas por un espacio
en blanco. Luego presentar por pantalla la cadena ingresada y la cantidad de palabras que posea.
Ejemplo: Se ingresa -> Tercer evaluativo de Programación I -> Muestra: 5 palabras*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int contarPalabras(char cadena[]);

int main(){
    char cadena[MAX];
    int cantPalabras;
    printf("\nIngrese una cadena de caracteres: ");
    fgets(cadena, MAX, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
    cantPalabras = contarPalabras(cadena);
    if (cantPalabras == 0)
        printf("\nNo se ingresó ninguna palabra\n");
    else
        printf("\nLa cadena ingresada es: \"%s\"\nTiene %i palabras\n", cadena, cantPalabras);

    return 0;
}

int contarPalabras(char cadena[]){
    int cantidad;

    if (isalpha(cadena[0])){
        ++cantidad;
    }

    for (int i = 1; cadena[i] != '\0'; i++){
        if (!isalpha(cadena[i - 1]) && isalpha(cadena[i]))
            ++cantidad;
    }

    return cantidad;
}