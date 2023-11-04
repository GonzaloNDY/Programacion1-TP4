/*Ingresar dos cadenas de caracteres y presentarlas por pantalla en el orden en que se encuentran
en el diccionario. Usar strcmp(). Ejemplo se ingresan "Sanchez Mateo" y "Sanchez Mariana" y se
debe mostrar "Sanchez Mariana" , "Sanchez Mateo" */

#include <stdio.h>
#include <string.h>

#define MAX 100

void cargarString(char cadena[]);

int main(){
    char cadena1[MAX], cadena2[MAX];
    printf("\nIngrese una cadena de caracteres: ");
    cargarString(cadena1);
    printf("\nIngrese otra cadena de caracteres: ");
    cargarString(cadena2);
    if (strcmp(cadena1, cadena2) < 0){
        printf("\nLas cadenas ingresadas son: \"%s\" y \"%s\"\n", cadena1, cadena2);
    } else {
        printf("\nLas cadenas ingresadas son: \"%s\" y \"%s\"\n", cadena2, cadena1);
    }
    return 0;
}

void cargarString(char cadena[]){
    fgets(cadena, MAX, stdin);     // fgets evita desbordamientos de buffer y consume el enter
    cadena[strcspn(cadena, "\n")] = '\0';     // Reemplazamos el enter por el caracter nulo
}