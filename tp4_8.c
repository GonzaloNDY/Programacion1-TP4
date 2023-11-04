/*Ingresar una cadena de caracteres, en caso de que la misma se corresponda con un entero,
realizar la conversión al formato número utilizando atoi(). Presentar por pantalla la cadena
ingresada y el número convertido. Tener en cuenta que para representar un entero debe poseer
solamente caracteres numéricos o el signo menos al principio. Ejemplo: Se ingresa 7291 ->
Muestra la cadena 7291 y el número 7291*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

void cargarString(char cadena[]);
int esCadenaNumerica(const char cadena[]);

int main(){
    char cadena[MAX];
    int num;
    printf("\nIngrese una cadena de caracteres: ");
    cargarString(cadena);
    printf("La cadena ingresada es: \"%s\"\n", cadena);
    if (esCadenaNumerica(cadena)){
        num = atoi(cadena);
        printf("El número es: %i\n", num);
    } else {
        printf("No se ingresó una cadena numérica\n");
    }
    return 0;
}

void cargarString(char cadena[]){
    fgets(cadena, MAX, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
}

int esCadenaNumerica(const char cadena[]){
    int inicio = 0;

    if (cadena[0] == '-'){
        inicio = 1;
    }

    for (int i = inicio; cadena[i] != '0'; i++){
        if (!isdigit(cadena[i])){
            return 0;
        }
    }
    return 1;
}