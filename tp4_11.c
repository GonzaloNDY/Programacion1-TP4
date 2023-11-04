/*Ingresar dos cadenas de caracteres (apellidos y nombres). Convertir el primer carácter de cada
una a mayúscula. Recordar que una persona puede tener más de un apellido o nombre. Generar
una nueva cadena concatenando las dos anteriores. Usar strcat()*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 200

void cargarCadena(char cadena[]);
int esNombreValido(char nombre[]);
int contarPalabras(char cadena[]);
void inicialAMayuscula(char nombre[]);

int main(){
    char nombreCompleto[MAX], apellido[MAX];
    printf("\n\tIngrese el nombre y apellido de una persona\nNombre: ");
    do {
        cargarCadena(nombreCompleto);
        if (!esNombreValido(nombreCompleto)){
            printf("Solo puede contener caracteres alfabéticos y un máximo de 3 nombres por persona, intente nuevamente: ");
        }
    } while (!esNombreValido(nombreCompleto));
    printf("Apellido: ");
    do {
        cargarCadena(apellido);
        if (!esNombreValido(apellido)){
            printf("Solo puede contener caracteres alfabéticos y un máximo de 3 apellidos por persona, intente nuevamente: ");
        }
    } while (!esNombreValido(apellido));
    strcat(nombreCompleto, " ");
    strcat(nombreCompleto, apellido);
    inicialAMayuscula(nombreCompleto);
    printf("\nEl nombre completo que ingresó es: \"%s\"\n", nombreCompleto);
    return 0;
}

void cargarCadena(char cadena[]){
    fgets(cadena, MAX, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
}

int esNombreValido(char nombre[]){
    if (strlen(nombre) == strspn(nombre, "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM ") && contarPalabras(nombre) <= 3){  // Se aceptarán como válidos solo hasta 3 nombres y 3 apellidos
        return 1;
    } else {
        return 0;
    }
}

int contarPalabras(char cadena[]){
    int cantidad = 0;

    if (isalpha(cadena[0])){
        ++cantidad;
    }

    for (int i = 1; cadena[i] != '\0'; i++){
        if (!isalpha(cadena[i - 1]) && isalpha(cadena[i]))
            ++cantidad;
    }

    return cantidad;
}

void inicialAMayuscula(char nombre[]){

    nombre[0] = toupper(nombre[0]);

    for (int i = 1; nombre[i] != '\0'; i++){
        if (nombre[i] == ' '){
            nombre[i + 1] = toupper(nombre[i + 1]);
        }
    }
}