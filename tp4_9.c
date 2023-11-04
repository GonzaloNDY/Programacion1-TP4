/*Ingresar una cadena de caracteres, en caso de que la misma se corresponda con un número
decimal positivo, es decir que posea solamente caracteres numéricos y el punto decimal,
realizar la conversión al formato número. Usar atof(). Presentar por pantalla la cadena ingresada
y el número convertido*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

void cargarString(char cadena[]);
int esCadenaNumerica(const char cadena[]);

int main(){
    char cadena[MAX];
    float num;
    printf("\nIngrese una cadena de caracteres: ");
    cargarString(cadena);
    printf("La cadena ingresada es: \"%s\"\n", cadena);
    if (esCadenaNumerica(cadena)){
        num = atof(cadena);
        printf("El número es: %.2f\n", num);
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
    if (!isdigit(cadena[0]) && cadena[0] != '-'){
        return 0;
    }
    for (int i = 1; i < strlen(cadena); i++){
        if (!isdigit(cadena[i]) && cadena[i] != '.'){
            return 0;
        }
    }
    return 1;
}