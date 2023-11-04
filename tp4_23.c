/*Escribe un programa en C que reciba dos números enteros como argumentos en la función main
y muestre la suma de los dos números por pantalla*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]){
    int suma = 0;
    if (argc != 3){
        printf("\nDeben ingresarse 2 argumentos en la llamada al programa (sin incluir el nombre)\n");
        return 0;
    } else {
        for (int i = 1; i < argc; i++){
            if (strspn(argv[i], "1234567890"  && atoi(argv[i]) < INT_MAX && atoi(argv[i]) > INT_MIN)){
                suma += atoi(argv[i]);
            } else {
                printf("\nTodos los argumentos ingresados deben ser números enteros dentro de los límites soportados (a excepción del nombre)\n");
                return 0;
            }
        }
    }
    printf("\nLa suma de los números ingresados es: %i\n", suma);
    return 0;
}