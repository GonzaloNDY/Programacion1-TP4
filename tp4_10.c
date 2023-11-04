/* Leer una fecha de caracteres que sólo puede contener dígitos y barra, con el formato
dd/mm/aaaa. Mostrar por pantalla un mensaje indicando si la fecha ingresada es una fecha
válida, es decir:
a. solo puede contener números y barra
b. los valores de día, mes y año se encuentran en los rangos permitidos:
■ el día debe estar entre 1 y 30 (para todos los meses).
■ el mes entre 1 y 12 .
■ el año debe ser menor o igual a 2023.
Por ejemplo: 34/05/2018, no es válida porque no hay meses de 34 días.
Sugerencia: investigar qué función de string.h puede servir para esto*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50
void cargarString(char fecha[]);
int esFechaValida(const char fecha[]);

int main(){
    char fecha[MAX];

    printf("\nIngrese una fecha (con el formato dd/mm/aaaa) el día debe estar entre 1 y 30, el mes entre 1 y 12 y el año debe ser menor o igual a 2023: ");
    
    do {
        cargarString(fecha);
        if (!esFechaValida(fecha)){
            printf("\nLa fecha ingresada no cumple con el formato solicitado (dd/mm/aaaa), intente nuevamente: ");
        }
    } while (!esFechaValida(fecha));

    printf("\nLa fecha ingresada es: %s\n", fecha);
    
    return 0;
}

void cargarString(char fecha[]){
    fgets(fecha, MAX, stdin);
    fecha[strcspn(fecha, "\n")] = '\0';
}

int esFechaValida(const char fecha[]){
    int numDia, numMes, numAnio;

    // Verifico si la cadena contiene solo dígitos y barras y si tiene el formato adecuado:
    if (strspn(fecha, "1234567890/") == 10 && fecha[2] == '/' && fecha[5] == '/'){
        // atoi(variable + n) permite comenzar la conversión desde el carácter en la posición "n" de la cadena "variable":
        numDia = atoi(fecha);   // atoi(fecha) == atoi(fecha + 0)
        numMes = atoi(fecha + 3);
        numAnio = atoi(fecha + 6);  

        if (numDia >= 1 && numDia <= 30 && numMes >= 1 && numMes <= 12 && numAnio <= 2023) {
            return 1;   // Fecha válida
        }
    } else {
        return 0;   //  Fecha inválida o formato incorrecto
    }
}
