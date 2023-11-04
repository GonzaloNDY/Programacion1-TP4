/*Ingresar los datos de N fechas en un arreglo de estructuras y mostrar el vector de fechas
resultantes en el main. Usar la siguiente estructura:
struct fecha {
int dia, mes, anio;
};
Realizar una función fecha leerFecha(); que deberá :
i. realizar el ingreso de datos como caracteres,
ii. verificar que cada carácter sea un entero (*) y
iii. realizar la conversión a entero
iv. si se convierte correctamente validar el rango de valores:
1. día debe estar entre 1 y 30 (para todos los meses),
2. el mes entre 1 y 12
3. y el año debe ser menor o igual al año actual, omitir consideraciones
como años bisiestos, etc
Luego de corroborar esto, deberá dentro de esta misma función llamar a
int control Fecha(fecha una Fecha);
Que se encargará de verificar si la fecha leída es menor a la fecha actual. En caso de serlo
devolverá 1, en caso contrario -1. Si retorna -1 dentro de leerFecha deberá volver a solicitar el
ingreso de la fecha. Para la fecha actual cargarla en el programa como un valor fijo.
(*)Por ejemplo si por teclado se ingresa dia = "ab" se deberá volver a solicitar la carga del valor
del día, ahora bien si se ingresa dia = "23" se procederá a solicitar el mes realizar el mismo
control y lo mismo con el año.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 50

// Fecha actual:
int diaActual = 13, mesActual = 6, anioActual = 2023;

typedef struct {
    int dia, mes, anio;
} fecha;

int ingresarNumPos();
void cargarFechas(fecha fechas[], int orden);
fecha cargarFechaValida();
int controlFecha(fecha unaFecha);
void mostrarFechas(fecha fechas[], int orden);

int main(){
    fecha fechas[MAX];
    int orden;

    printf("\nIndique la cantidad de fechas que ingresará: ");
    orden = ingresarNumPos();

    cargarFechas(fechas, orden);
    mostrarFechas(fechas, orden);

    return 0;
}

int ingresarNumPos(){
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

void cargarFechas(fecha fechas[], int orden){
    for (int i = 0; i < orden; i++){
        printf("\n\tFecha %i", i + 1);
        fechas[i] = cargarFechaValida();
        while (controlFecha(fechas[i]) == -1){
            printf("La fecha ingresada debe ser menor a la fecha actual, intente nuevamente:");
            fechas[i] = cargarFechaValida();
        }
    }
}

fecha cargarFechaValida(){
    fecha unaFecha;
    char dia[MAX], mes[MAX], anio[MAX];

    printf("\nDia: ");
    do {
        fgets(dia, MAX, stdin);
        dia[strcspn(dia, "\n")] = '\0';
        if (!strspn(dia, "1234567890") || atoi(dia) < 1 || atoi(dia) > 30)
            printf("El día debe ser un número mayor que cero y menor o igual que 30, intente nuevamente: ");
    } while (!strspn(dia, "1234567890") || atoi(dia) < 1 || atoi(dia) > 30);
    unaFecha.dia = atoi(dia);

    printf("Mes: ");
    do {
        fgets(mes, MAX, stdin);
        mes[strcspn(mes, "\n")] = '\0';
        if (!strspn(mes, "1234567890") || atoi(mes) < 1 || atoi(mes) > 12)
            printf("El mes debe ser un número mayor que cero y menor o igual que 12, intente nuevamente: ");
    } while (!strspn(mes, "1234567890") || atoi(mes) < 1 || atoi(mes) > 12);
    unaFecha.mes = atoi(mes);

    printf("Año: ");
    do {
        fgets(anio, MAX, stdin);
        dia[strcspn(anio, "\n")] = '\0';
        if (!strspn(anio, "1234567890") || atoi(anio) < 1 || atoi(anio) > anioActual)
            printf("El año debe ser un número mayor que cero y menor o igual que %i, intente nuevamente: ", anioActual);
    } while (!strspn(anio, "1234567890") || atoi(anio) < 1 || atoi(anio) > anioActual);
    unaFecha.anio = atoi(anio);

    return unaFecha;
}

int controlFecha(fecha unaFecha){
    if (anioActual == unaFecha.anio && (mesActual < unaFecha.mes || (mesActual == unaFecha.mes && diaActual < unaFecha.dia))){
        return -1;
    }
    return 1;
}

void mostrarFechas(fecha fechas[], int orden){
    printf("\nLas fechas ingresadas son:");
    for (int i = 0; i < orden; i++){
        printf("\n\tFecha %i\n", i + 1);
        printf("%i/%i/%i", fechas[i].dia, fechas[i].mes, fechas[i].anio);
    }
}