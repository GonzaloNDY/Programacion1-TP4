/*Ingresar los datos de UN huésped. Luego presentar por pantalla los datos del mismo
(apellido/s, nombre/s, ciudad de origen, cantidad de días que se va a hospedar, importe
que debe abonar por los días que se quede). Para presentar por pantalla usar este formato:
Huesped: Younes, José Ciudad de origen: Cordoba
Dias Hospedaje: 5 dias Importe a abonar:7500.00 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

typedef struct {
    char apellido[MAX];
    char nombre[MAX];
    char ciudad[MAX];
    float precio;
    int dias;
} huesped;

huesped cargarDatosHuesped();
void cargarNombresPropios(char cadena[]);
void inicialAMayuscula(char nombre[]);

int main(){
    huesped elHuesped;
    elHuesped = cargarDatosHuesped();
    printf("\nHuesped: %s, %s\tCiudad de origen: %s\n", elHuesped.apellido, elHuesped.nombre, elHuesped.ciudad);
    printf("Dias de hospedaje: %i\tImporte a abonar: $%.2f\n", elHuesped.dias, elHuesped.precio);
    return 0;
}

huesped cargarDatosHuesped(){
    huesped unHuesped;

    printf("\n\tDatos del huesped\nApellido: ");
    cargarNombresPropios(unHuesped.apellido);
    inicialAMayuscula(unHuesped.apellido);

    printf("Nombre: ");
    cargarNombresPropios(unHuesped.nombre);
    inicialAMayuscula(unHuesped.nombre);

    printf("Ciudad de origen: ");
    cargarNombresPropios(unHuesped.ciudad);
    inicialAMayuscula(unHuesped.ciudad);

    printf("Cantidad de dias que se hospedará: ");
    scanf("%i", &unHuesped.dias);

    printf("Importe que deberá abonar por los días que se quede: ");
    scanf("%f", &unHuesped.precio);

    return unHuesped;
}

void cargarNombresPropios(char cadena[]){
    do {
        fgets(cadena, MAX, stdin);
        cadena[strcspn(cadena, "\n")] = '\0';
        if (strlen(cadena) != strspn(cadena, "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM ") || strspn(cadena, " ") > 4)
            printf("Solo puede contener caracteres alfabéticos y un máximo de 4 espacios, intente nuevamente: ");
    } while (!strspn(cadena, "qwertyuiopasdfghjklzxcvbnm ") || strspn(cadena, " ") > 4);    
}

void inicialAMayuscula(char nombre[]){
    size_t longNombre = strlen(nombre);
    nombre[0] = toupper(nombre[0]);
    for (size_t i = 1; i < longNombre; i++){  // el iterador 'i' es un size_t y no un int para evitar posibles advertencias del compilador relacionadas con la comparación entre un int y un size_t
        if (nombre[i] == ' ')
            nombre[i + 1] = toupper(nombre[i + 1]);
    }
}