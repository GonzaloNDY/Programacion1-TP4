/*Escribir un programa que solicite al usuario una cadena de caracteres y un número entero
positivo(n). Luego, cifre la cadena utilizando el "Cifrado César" desplazando cada letra n
posiciones hacia la derecha en el alfabeto. Por ejemplo, si n=2, "HOLA" se cifraría como "JQNC"*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

void cargarString(char cadena[]);
int ingresarNumPos();
void cifrarCadena(char cadena[], int n);

int main(){
    char cadena[MAX];
    int n;
    printf("\nIngrese una cadena de caracteres: ");
    cargarString(cadena);
    printf("Ingrese un número positivo: ");
    n = ingresarNumPos();
    cifrarCadena(cadena, n);
    printf("\nLa cadena cifrada es: %s\n", cadena);
    return 0;
}

void cargarString(char cadena[]){
    fgets(cadena, MAX, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
}

int ingresarNumPos(){
    int num;
    do {
        scanf("%i", &num);
        if (num <= 0)
            printf("El número ingresado debe ser mayor a cero, intente nuevamente: ");
    } while (num <= 0);
    return num;
}

void cifrarCadena(char cadena[], int n){
    size_t longCadena = strlen(cadena);
    for (int i = 0; i < longCadena; i++){
        if (isalpha(cadena[i]))
            if (islower(cadena[i])){
                cadena[i] = (cadena[i] - 'a' + n) % 26 + 'a';
            /* Si por ejemplo: La letra es 'z' y simplemente me desplazo [2] lugares, el caracter final no será alfabetico, en cambio,
            si le resto 'a' a 'z' y le sumo [2], obtendré [28], [28] mod [26] sería [2] y al sumarle 'a' obtengo el caracter cifrado 'c', 
            de esta manera siempre se mantienen los límites validos del alfabeto y un ciclo circular */
            } else {
                cadena[i] = (cadena[i] - 'A' + n) % 26 + 'A';
            }
    }
}