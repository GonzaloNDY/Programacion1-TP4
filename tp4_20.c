/*Ingresar N cadenas de caracteres. Luego ingresar otra cadena y buscar si dicha cadena se
encuentra en el arreglo, presentar por pantalla la cantidad de veces que se encontró dicha
cadena*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int controlOrdenMax();
void cargarCadena(char cadenas[][MAX], int orden);
int compararCadenas(char cadenas[][MAX], int orden, char unaCadena[]);

int main(){
    char cadenas[MAX][MAX], unaCadena[MAX];
    int ordenMax;

    printf("\nIndique la cantidad de cadenas que ingresará: ");
    ordenMax = controlOrdenMax();

    cargarCadena(cadenas, ordenMax);

    printf("\nIngrese la cadena que se buscará en el arreglo de cadenas: ");
    fgets(unaCadena, MAX, stdin);
    unaCadena[strlen(unaCadena) - 1] = '\0';

    printf("\nLa cadena \"%s\" se encontró %i veces en el arreglo anterior\n", unaCadena, compararCadenas(cadenas, ordenMax, unaCadena));
    
    return 0;
}

int controlOrdenMax(){
    char num[MAX];
    int numero;
    do {
        fgets(num, MAX, stdin);
        num[strlen(num) - 1] = '\0';
        if (!strspn(num, "1234567890") && atoi(num) <= 0 || atoi(num) > MAX)
            printf("El valor ingresado debe ser un número mayor que cero y menor a %i, intente nuevamente: ", MAX);
    } while (!strspn(num, "1234567890") && atoi(num) <= 0 || atoi(num) > MAX);
    numero = atoi(num);
    return numero;
}

void cargarCadena(char cadenas[][MAX], int orden){
    printf("\n\tA continuación tendrá que ingresar %i cadenas\n", orden);
    for (int i = 0; i < orden; i++){
        printf("cadena %i: ", i + 1);
        fgets(cadenas[i], MAX, stdin);
        cadenas[i][strlen(cadenas[i]) - 1] = '\0';
    }
}

int compararCadenas(char cadena[][MAX], int orden, char unaCadena[]){
    int cantCoincidencias = 0;
    for (int i = 0; i < orden; i++){
        if (strcmp(cadena[i], unaCadena) == 0)
            cantCoincidencias++;
    }
    return cantCoincidencias;
}