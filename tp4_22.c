/*Ingresar N cadenas de caracteres. Luego imprimir en pantalla solamente las cadenas que
comiencen con un carácter alfabético en mayúscula.
Ejemplo: se ingresan 6 cadenas de carácter: primer cuaderno; Segunda persona; computadora;
Pre procesador; Apellido; silla lado pasillo. Debe mostrar las cadenas: Segunda persona; Pre
procesador, Apellido*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int controlOrdenMax();
void cargarCadena(char cadenas[][MAX], int orden);
void mostrarSiInicialEsMayuscula(char cadenas[][MAX], int orden);

int main(){
    char cadenas[MAX][MAX];
    int ordenMax;

    printf("\nIndique la cantidad de cadenas que ingresará: ");
    ordenMax = controlOrdenMax();

    cargarCadena(cadenas, ordenMax);
    mostrarSiInicialEsMayuscula(cadenas, ordenMax);
    
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
        printf("Cadena %i: ", i + 1);
        fgets(cadenas[i], MAX, stdin);
        cadenas[i][strlen(cadenas[i]) - 1] = '\0';
    }
}

void mostrarSiInicialEsMayuscula(char cadenas[][MAX], int orden){
    printf("\nLas cadenas que comienzan con un carácter alfabético en mayúscula son:\n");
    for (int i = 0; i < orden; i++){
        if (isalpha(cadenas[i][0]) && isupper(cadenas[i][0]))  // Se añadió isalpha() porque isupper() considera los caracteres no alfabeticos como mayúsculas 
            printf("%s\n", cadenas[i]);
    }
}