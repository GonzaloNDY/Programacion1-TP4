/*Ingresar los datos de N huéspedes de un Hotel, y solicitar una ciudad. Luego mostrar por
pantalla solamente a las personas que provengan de esa ciudad. Usar strcmp. En caso de
no haber huéspedes de esa ciudad mostrar un mensaje indicando esa situación*/

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
void cargarVector(huesped huespedes[], int orden);
huesped cargarDatosHuesped();
void cargarNombresPropios(char cadena[]);
void mostrarPorCiudad(huesped huespedes[], int orden, char ciudad[]);

int main(){
    huesped huespedes[MAX];
    char ciudad[MAX];
    int ordenMax;

    printf("\nIngrese la cantidad de huespedes que registrará: ");
    ordenMax = controlOrdenMax();
    getchar();

    printf("\nIngrese una ciudad: ");
    cargarNombresPropios(ciudad);

    cargarVector(huespedes, ordenMax);
    mostrarPorCiudad(huespedes, ordenMax, ciudad);

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

void cargarVector(huesped huespedes[], int orden){
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

void mostrarPorCiudad(huesped huespedes[], int orden, char ciudad[]){
    int bandera = 0;
    printf("\n Huespedes cuya ciudad de origen es %s:\n", ciudad);
    for (int i = 0; i < orden; i++){
        if (strcmp(huespedes[i].ciudad, ciudad) == 0){
            bandera++;
            printf("%i. %s, %s\n", bandera, huespedes[i].apellido, huespedes[i].nombre);
        }
    }
    if (!bandera){
        printf("No se ingresaron datos de huespedes provenientes de esa ciudad\n");
    }    
}