/*Ingresar una cadena de caracteres, contabilizar cuántos caracteres alfabéticos, numéricos y de
otro tipo hay en la misma. Mostrar la cadena leída y las cantidades encontradas*/

#include <stdio.h>
#include <ctype.h>

#define MAX 100

void controlVector(char cadena[], int *letras, int *numeros, int *otros);

int main(){
    char cadena[MAX];
    int cantLetras, cantNumeros, cantOtros;
    printf("\nIngrese una cadena de caracteres: ");
    scanf("%[^\n]s", cadena);
    controlVector(cadena, &cantLetras, &cantNumeros, &cantOtros);
    printf("\nLa cadena ingresada es: %s\nSe ingresaron %i letras, %i números y %i caracteres de otro tipo (el espacio tambien se considerará como un caracter)\n", cadena, cantLetras, cantNumeros, cantOtros);
    return 0;
}

void controlVector(char cadena[], int *letras, int *numeros, int *otros){
    for (int i = 0; cadena[i] != '\0'; i++){
        if (isalpha(cadena[i])){
            ++*letras;
        } else if (isdigit(cadena[i])){
            ++*numeros;
        } else {
            ++*otros;
        }
    }
    
}