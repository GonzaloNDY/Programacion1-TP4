/*Ingresar los datos de N huéspedes de un Hotel, luego mostrarlos por pantalla:
Huesped Ciudad de origen
Younes, José Cordoba
Juarez, Julio José Misiones
Rodriguez, María Cordoba*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

typedef struct {
    char apellido[MAX];
    char nombre[MAX];
    char ciudad[MAX];
} huesped;

huesped cargarDatosHuesped();
void cargarNombresPropios(char cadena[]);
void inicialAMayuscula(char nombre[]);
int controlOrdenMax();
void cargarvector(huesped huespedes[], int orden);
void mostrarVector(huesped huespedes[], int orden);

int main(){
    huesped huespedes[MAX];
    int ordenMax;
    printf("\nIngrese la cantidad de huespedes que registrará: ");
    ordenMax = controlOrdenMax();
    getchar();
    cargarvector(huespedes, ordenMax);
    mostrarVector(huespedes, ordenMax);
    return 0;
}

huesped cargarDatosHuesped(){
    huesped unHuesped;

    printf("Apellido: ");
    cargarNombresPropios(unHuesped.apellido);
    inicialAMayuscula(unHuesped.apellido);

    printf("Nombre: ");
    cargarNombresPropios(unHuesped.nombre);
    inicialAMayuscula(unHuesped.nombre);

    printf("Ciudad de origen: ");
    cargarNombresPropios(unHuesped.ciudad);
    inicialAMayuscula(unHuesped.ciudad);

    return unHuesped;
}

void cargarNombresPropios(char cadena[]){
    do {
        fgets(cadena, MAX, stdin);
        cadena[strcspn(cadena, "\n")] = '\0';
        if (!strspn(cadena, "´qwertyuiopasdfghjklñzxcvbnmQWERTYUIOPASDFGHJKLÑZXCVBNM ") || strspn(cadena, " ") > 4)
            printf("Solo puede contener caracteres alfabéticos y un máximo de 4 espacios, intente nuevamente: ");
    } while (!strspn(cadena, "´qwertyuiopasdfghjklñzxcvbnmQWERTYUIOPASDFGHJKLÑZXCVBNM ") || strspn(cadena, " ") > 4);    
}

void inicialAMayuscula(char nombre[]){
    size_t longNombre = strlen(nombre);
    nombre[0] = toupper(nombre[0]);
    for (size_t i = 1; i < longNombre; i++){  // el iterador 'i' es un size_t y no un int para evitar posibles advertencias del compilador relacionadas con la comparación entre un int y un size_t
        if (nombre[i] == ' ')
            nombre[i + 1] = toupper(nombre[i + 1]);
    }
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

void mostrarVector(huesped huespedes[], int orden){
    int nombreMasLargo = 0, espacios;
    for (int i = 0; i < orden; i++){
        if (strlen(huespedes[i].apellido) + strlen(huespedes[i].nombre) > nombreMasLargo)
            nombreMasLargo = strlen(huespedes[i].apellido) + strlen(huespedes[i].nombre);
    }
    printf("\n\t Huesped:");
    for (int j = 0; j < nombreMasLargo; j++){
        printf(" ");
    }
    printf("Ciudad de origen:\n");
    for (int i = 0; i < orden; i++){
        printf("\t%s, %s", huespedes[i].apellido, huespedes[i].nombre);
        espacios = nombreMasLargo - (strlen(huespedes[i].apellido) + strlen(huespedes[i].nombre)) + 6;
        for (int j = 0; j < espacios; j++){
            printf(" ");
        }
        printf("%s\n", huespedes[i].ciudad);
    }
}