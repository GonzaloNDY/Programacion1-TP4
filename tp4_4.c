/*Solicitar al usuario el ingreso del apellido y nombre de una persona y almacenarlos en una
cadena de caracteres, luego mostrarla por pantalla. Realizar la lectura y presentación por
pantalla empleando todas las funciones vistas: scanf(), fscanf(), fgets(), printf(), fprintf() y fputs().
Analizar las diferencias y qué sucede con el salto de línea (enter) y los espacios*/

#include <stdio.h>
#define MAX 200

int main(int argc, char *argv[]){
    char nombre[MAX];

    printf("Ingrese el nombre y apellido a guardar:\t");
    
    scanf("%[a-zA-Z ^\n]s", nombre);

    // fgets(nombre, 99, stdin);
    // cadena2[strlen(cadena2)-1] = '\0';

    // fscanf(stdin, "%s, nombre");

    // fputs("\nEl nombre guardado es: ", stdout);
    // fputs(nombre, stdout);

    // fprintf(stdout, "\nEl nombre y apellido guardado es: %s\n", nombre);

    printf("\nEl nombre guardado es: %s\n", nombre);
    
    return 0;
}