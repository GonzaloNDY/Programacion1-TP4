/*Escriba un programa en lenguaje C que permita gestionar una lista de huéspedes de un Hotel. 
El programa debe poseer un menú con las siguientes opciones:
Agregar un huésped a la lista. Consejo: Usar lo realizado en el punto 15.
Mostrar por pantalla la lista de huéspedes ordenada alfabéticamente. Consejo: Usar lo realizado en el punto 7 y 16.
Buscar huéspedes por apellido, en caso de no encontrar ninguno mostrar un mensaje.
Dada una ciudad, indicar la cantidad de huéspedes que son de esa ciudad. Consejo: Puede servir lo realizado en el ejercicio 17.
Salir del programa*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 50

#ifdef _WIN32
	#define limpiar() system("cls")
#else
	#define limpiar() system("clear")
#endif

typedef struct {
    char apellido[MAX];
    char nombre[MAX];
    char ciudad[MAX];
} huesped;

void mostrarMenu();
void pausarMenu();
int controlPositivo();
huesped cargarDatosHuesped();
void cargarNombresPropios(char cadena[]);
void ordenarVector(huesped huespedes[], int orden);
void mostrarVector(huesped huespedes[], int orden);
int huespedesPorCiudad(huesped huespedes[], int orden, char ciudad[]);
void buscarPorApellido(huesped huespedes[], int orden, char apellido[]);

int main(){
    huesped huespedes[MAX];
    char apellido[MAX], ciudad[MAX];
    int opcion, ordenMax = 0;
    do {
        limpiar();
        mostrarMenu();
        opcion = controlPositivo();
        limpiar();
        if (opcion != 5 && ordenMax == 0 && opcion != 1){
            printf("\tNo se puede acceder a la opción elegida porque aun no se cargaron datos de ningun huesped\n");
        } else {
            switch (opcion){
                case 1:
                    huespedes[ordenMax] = cargarDatosHuesped();
                    ordenMax++;
                    pausarMenu();
                    break;
                case 2:
                    ordenarVector(huespedes, ordenMax);
                    mostrarVector(huespedes, ordenMax);
                    pausarMenu();
                    break;
                case 3:
                    printf("\nIngrese el apellido a buscar: ");
                    cargarNombresPropios(apellido);
                    buscarPorApellido(huespedes, ordenMax, apellido);
                    pausarMenu();
                    break;
                case 4:
                    printf("\nIngrese una ciudad: ");
                    cargarNombresPropios(ciudad);
                    printf("La cantidad de huespedes de la ciudad de %s es: %i\n", ciudad, huespedesPorCiudad(huespedes, ordenMax, ciudad));
                    pausarMenu();
                    break;
                case 5:
                    printf("\nEl programa finalizó correctamente\n");
                    break;
                default:
                    printf("\nLa opción ingresada no existe\n");
                    break;
            }
        }
    } while (opcion != 5);

    return 0;
}

void mostrarMenu(){
    printf("\n\n\t\t\tMenú de gestión de huespedes\n");
    printf("\t\t1 -> Agregar un huésped a la lista\n");
    printf("\t\t2 -> Mostrar por pantalla la lista de huéspedes ordenada por apellidos\n");
    printf("\t\t3 -> Buscar huéspedes por apellido\n");
    printf("\t\t4 -> Mostrar la cantidad de huéspedes que son de una ciudad\n");
    printf("\t\t5 -> Salir del programa\n");
    printf("\n\tOpción ingresada: ");
}

void pausarMenu(){
    printf("\n\nPresionar enter para regresar al Menu...");
    fgetc(stdin);
}

int controlPositivo(){
    char num[MAX];
    int numero;
    do {
        fgets(num, MAX, stdin);
        num[strlen(num) - 1] = '\0';
        if (!strspn(num, "1234567890"))
            printf("El valor ingresado debe ser un número positivo, intente nuevamente: ");
    } while (!strspn(num, "1234567890"));
    numero = atoi(num);
    return numero;
}

huesped cargarDatosHuesped(){
    huesped unHuesped;
    printf(" Ingrese los datos del huesped\nApellido: ");
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
        if (!strspn(cadena, "´qwertyuiopasdfghjklñzxcvbnmQWERTYUIOPASDFGHJKLÑZXCVBNM ") || strspn(cadena, " ") > 3)
            printf("Solo puede contener caracteres alfabéticos y un máximo de 3 espacios, intente nuevamente: ");
    } while (!strspn(cadena, "´qwertyuiopasdfghjklñzxcvbnmQWERTYUIOPASDFGHJKLÑZXCVBNM ") || strspn(cadena, " ") > 3);
    
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
    // Ordenamiento ascendente por inserción:
    for (int i = 1; i < orden; i++){
        indiceAuxiliar = i - 1;
        huespedActual = huespedes[i];
        while (indiceAuxiliar >= 0 && strcmp(huespedes[indiceAuxiliar].apellido, huespedActual.apellido)  > 0 ){
            huespedes[indiceAuxiliar + 1] = huespedes[indiceAuxiliar];
            indiceAuxiliar--;
        }
        huespedes[indiceAuxiliar + 1] = huespedActual;
        // Si los apellidos son iguales, se ordenará por nombre:
        while (strcmp(huespedes[indiceAuxiliar].apellido, huespedActual.apellido)  == 0 && indiceAuxiliar >= 0 && strcmp(huespedes[indiceAuxiliar].nombre, huespedActual.nombre) > 0){
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

    printf("\nA continuación se mostrarán los datos ingresados\n");

    printf("\nHuesped:");
    for (int j = 0; j < nombreMasLargo; j++){
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

int huespedesPorCiudad(huesped huespedes[], int orden, char ciudad[]){
    int contador = 0;
    for (int i = 0; i < orden; i++){
        if (strcmp(huespedes[i].ciudad, ciudad) == 0)
            contador++;
    }
    return contador;
}

void buscarPorApellido(huesped huespedes[], int orden, char apellido[]){
    int bandera = 0, nombreMasLargo = 0, espacios;

    for (int i = 0; i < orden; i++){
        if (strlen(huespedes[i].apellido) + strlen(huespedes[i].nombre) > nombreMasLargo)
            nombreMasLargo = strlen(huespedes[i].apellido) + strlen(huespedes[i].nombre);
    }

    printf("\n Huespedes cuyo apellido es %s:\n", apellido);
    for (int i = 0; i < orden; i++){
        if (strcmp(huespedes[i].apellido, apellido) == 0){
            bandera = 1;    // [bandera] = [bandera != 0]
            printf("%i. %s, %s", bandera, huespedes[i].apellido, huespedes[i].nombre);

            espacios = nombreMasLargo - (strlen(huespedes[i].apellido) + strlen(huespedes[i].nombre)) + 5;
            for (int j = 0; j < espacios; j++){
                printf(" ");
            }

            printf("Ciudad: %s\n", huespedes[i].ciudad);
        }
    }
    
    if (!bandera)   // [!bandera] = [bandera = 0]
        printf("No se ingresaron datos de huespedes con ese apellido\n"); 
}