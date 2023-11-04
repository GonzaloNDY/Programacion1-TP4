/*Ingresar los datos de N huéspedes de un Hotel, luego mostrarlos por pantalla ordenados
alfabéticamente por su apellido*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

typedef struct {
    char apellido[MAX];
    char nombre[MAX];
    char ciudad[MAX];
} huesped;

int controlOrdenMax();
void cargarvector(huesped huespedes[], int orden);
huesped cargarDatosHuesped();
void cargarNombresPropios(char cadena[]);
void ordenarVector(huesped huespedes[], int orden);
void mostrarVector(huesped huespedes[], int orden);

int main(){
    huesped huespedes[MAX];
    int ordenMax;
    printf("\nIngrese la cantidad de huespedes que registrará: ");
    ordenMax = controlOrdenMax();
    getchar();
    cargarvector(huespedes, ordenMax);
    ordenarVector(huespedes, ordenMax);
    mostrarVector(huespedes, ordenMax);
    return 0;
}

int controlOrdenMax(){
    int num;
    do {
        scanf("%i", &num);
        if (num <= 0)
            printf("El valor ingresado debe ser un número entero mayor a cero, intente nuevamente: ");
    } while (num <= 0);
    return num;
}

void cargarvector(huesped huespedes[], int orden){
    for (int i = 0; i < orden; i++){
        printf("\n\tDatos del huesped %i\n", i + 1);
        huespedes[i] = cargarDatosHuesped();
    }
}

huesped cargarDatosHuesped(){
    huesped unHuesped;

    printf("Apellido: ");
    cargarNombresPropios(unHuesped.apellido);

    printf("Nombre: ");
    cargarNombresPropios(unHuesped.nombre);

    printf("Ciudad de origen: ");
    cargarNombresPropios(unHuesped.ciudad);

    return unHuesped;
}

void cargarNombresPropios(char cadena[]){
    int longCadena;
    do {
        fgets(cadena, MAX, stdin);
        cadena[strcspn(cadena, "\n")] = '\0';
        if (!strspn(cadena, "´qwertyuiopasdfghjklñzxcvbnmQWERTYUIOPASDFGHJKLÑZXCVBNM ") || strspn(cadena, " ") > 4)
            printf("Solo puede contener caracteres alfabéticos y un máximo de 4 espacios, intente nuevamente: ");
    } while (!strspn(cadena, "´qwertyuiopasdfghjklñzxcvbnmQWERTYUIOPASDFGHJKLÑZXCVBNM ") || strspn(cadena, " ") > 4);
    cadena[0] = toupper(cadena[0]);
    longCadena = strlen(cadena);
    for (int i = 1; i < longCadena; i++){
        if (cadena[i] == ' ')
            cadena[i + 1] = toupper(cadena[i + 1]);
    }
}

void ordenarVector(huesped huespedes[], int orden){
    int indiceAuxiliar;
    huesped huespedActual;
    for (int i = 1; i < orden; i++){
        indiceAuxiliar = i - 1;
        huespedActual = huespedes[i];
        while (indiceAuxiliar >= 0 && strcmp(huespedes[indiceAuxiliar].apellido, huespedActual.apellido)  > 0 ){
            huespedes[indiceAuxiliar + 1] = huespedes[indiceAuxiliar];
            indiceAuxiliar--;
        }
        huespedes[indiceAuxiliar + 1] = huespedActual;
    }
}

void mostrarVector(huesped huespedes[], int orden){
    int nombreMasLargo = 0, espacios;
    for (int i = 0; i < orden; i++){
        if (strlen(huespedes[i].apellido) + strlen(huespedes[i].nombre) > nombreMasLargo)
            nombreMasLargo = strlen(huespedes[i].apellido) + strlen(huespedes[i].nombre);
    }
    printf("\n Huesped:");
    for (int j = 1; j < nombreMasLargo; j++){
        printf(" ");
    }
    printf("Ciudad de origen:\n");
    for (int i = 0; i < orden; i++){
        printf("%s, %s", huespedes[i].apellido, huespedes[i].nombre);
        espacios = nombreMasLargo - (strlen(huespedes[i].apellido) + strlen(huespedes[i].nombre)) + 6;
        for (int j = 0; j < espacios; j++){
            printf(" ");
        }
        printf("%s\n", huespedes[i].ciudad);
    }
}