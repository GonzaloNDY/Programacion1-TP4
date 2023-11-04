/*Ingresar N apellidos (tener en cuenta que cada persona puede tener uno o más apellidos), luego
presentar por pantalla los apellidos ordenados en forma alfabética y con la primera letra de cada
apellido en mayúsculas y el resto en minúsculas*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int controlOrdenMax();
void cargarStruct(char apellidos[][MAX], int orden);
void ordenarApellidos(char apellidos[][MAX], int orden);
void mostrarStruct(char apellidos[][MAX], int orden);

int main(){
    char apellidos[MAX][MAX];
    int ordenMax;

    printf("\nIndique la cantidad de apelidos  que ingresará: ");
    ordenMax = controlOrdenMax();

    cargarStruct(apellidos, ordenMax);
    ordenarApellidos(apellidos, ordenMax);
    mostrarStruct(apellidos, ordenMax);
    
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

void cargarStruct(char apellidos[][MAX], int orden){
    int longApellido;
    printf("\nIngrese %i apellidos:\n", orden);
    for (int i = 0; i < orden; i++){
        printf("%i --> ", i + 1);

        do {
            fgets(apellidos[i], MAX, stdin);
            apellidos[i][strcspn(apellidos[i], "\n")] = '\0';
            if (!strspn(apellidos[i], "´qwertyuiopasdfghjklñzxcvbnmQWERTYUIOPASDFGHJKLÑZXCVBNM ") || strspn(apellidos[i], " ") > 4)
                printf("Solo puede contener caracteres alfabéticos y un máximo de 4 espacios, intente nuevamente: ");
        } while (!strspn(apellidos[i], "´qwertyuiopasdfghjklñzxcvbnmQWERTYUIOPASDFGHJKLÑZXCVBNM ") || strspn(apellidos[i], " ") > 4);
        
        apellidos[i][0] = toupper(apellidos[i][0]);
        longApellido = strlen(apellidos[i]);  // Se guarda el valor de strlen() en una variable para evitar llamar a esta funcion en cada una de las repeticiones del bucle for
        for (int j = 1; j < longApellido; j++){
            if (apellidos[i][j] != ' ' && apellidos[i][j - 1] != ' '){
                apellidos[i][j] = tolower(apellidos[i][j]);
            } else {
                apellidos[i][j] = toupper(apellidos[i][j]);
            }
        }
    }
}

void ordenarApellidos(char apellidos[][MAX], int orden){
    int indiceAux;
    char apellidoActual[MAX];
    for (int i = 1; i < orden; i++){
        indiceAux = i - 1;
        strcpy(apellidoActual, apellidos[i]);
        // Ordenamiento de apellidos:
        while (indiceAux >= 0 && strcmp(apellidos[indiceAux], apellidoActual) > 0){
            strcpy(apellidos[indiceAux + 1], apellidos[indiceAux]);
            indiceAux--;
        }
        strcpy(apellidos[indiceAux + 1], apellidoActual);
    }
}

void mostrarStruct(char apellidos[][MAX], int orden){
    printf("\nA continuación se mostrarán todos los apellidos ordenados alfabeticamente:\n");
    for (int i = 0; i < orden; i++){
        printf("%i: %s\n", i + 1, apellidos[i]);
    }
}