/*Ingresar por línea de comandos, dos palabras (realizar el control de la cantidad de palabras
ingresadas). Luego mostrar por pantalla las palabras ordenadas en forma alfabética, o un
mensaje en caso de que sean iguales*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    int comparacionDePalabras;

    if (argc != 3){
        printf("\nDeben ingresarse solo 2 argumentos en la llamada al programa (sin incluir el nombre)\n");
        return 0;
    }
    if (strchr(argv[1], ' ') || strchr(argv[2], ' ')){
        printf("\nDebe ingresar solo dos palabras\n");
        return 0;
    }
    
    comparacionDePalabras = strcmp(argv[1], argv[2]);
    if (comparacionDePalabras > 0){
        printf("\nLas palabras ordenadas en forma alfabetica son:\n%s\n%s\n", argv[2], argv[1]);
    } else if (comparacionDePalabras < 0){
        printf("\nLas palabras ordenadas en forma alfabetica son:\n%s\n%s\n", argv[1], argv[2]);
    } else {
        printf("\nLas palabras ingresadas son iguales\n");
    }

    return 0;
}