/*
 * =============================================================================
 *
 *       Filename:  ej196.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  28/11/13 21:27:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  KELVIN PROVINCIA (), aek6.io@gmail.com
 *   Organization:  aek6
 *
 * =============================================================================
 */
#include <stdio.h>
#include <string.h>

#define MES 10

typedef struct {
    int dia, mes, anio;
} Fecha;

void ddmmaaaa(Fecha *fecha) {
    printf ("%02d/%02d/%04d\n", fecha->dia, fecha->mes, fecha->anio);
}

void nombreMes(int mes, char nombre[]) {
    char meses[][MES + 1] = {"enero", "febrero", "marzo", "abril", "mayo",
                            "junio", "julio", "agosto", "septiembre", "octubre",
                            "noviembre", "diciembre"};
    strcpy(nombre, meses[--mes]);
}

void texto(Fecha *fecha) {
    char mes[MES + 1];
    nombreMes(fecha->mes, mes);
    printf ("%d de %s de %d\n", fecha->dia, mes, fecha->anio);
}

void leerFecha(Fecha *fecha) {
    printf ("Dame la fecha dd mm aaaa: "); scanf ("%d %d %d", &fecha->dia,
            &fecha->mes, &fecha->anio);
}

int esBisiesto(Fecha *fecha) {
    if (fecha->anio % 4 == 0 && (fecha->anio % 100 != 0 || fecha->anio % 400 == 0))
        return 1;
    return 0;
}

int cmpFecha(Fecha *fecha1, Fecha *fecha2) {
    if (fecha1->anio > fecha2->anio) return 1;
    else if (fecha1->anio < fecha2->anio) return -1;

    if (fecha1->mes > fecha2->mes) return 1;
    else if (fecha1->mes < fecha2->mes) return -1;

    if (fecha1->dia > fecha2->dia) return 1;
    else if (fecha1->dia < fecha2->dia) return -1;
    
    return 0;
}

int diasMes(Fecha *fecha) {
    if (fecha->mes == 2 && !esBisiesto(fecha)) return 28;
    if (fecha->mes == 2 && esBisiesto(fecha)) return 29;
    if (fecha->mes <= 7 && fecha->mes % 2 == 0) return 30;
    if (fecha->mes <= 7 && fecha->mes % 2 != 0) return 31;
    if (fecha->mes <= 12 && fecha->mes % 2 != 0) return 30;
    if (fecha->mes <= 12 && fecha->mes % 2 == 0) return 31;
    return 0;
}

int existe(Fecha *fecha) {
    if (fecha->dia > 0 && fecha->dia <= diasMes(fecha)) return 1;
    return 0;
}

int diferenciaDias(Fecha *fecha1, Fecha *fecha2) {
    int anios, meses, dias;
    anios = fecha1->anio - fecha2->anio;
    meses = fecha1->mes - fecha2->mes;
    dias = fecha1->dia - fecha2->dia;
    return dias + (anios * 365) + (meses * 30);
}

int main(void) {
    Fecha fecha, fecha2;
    leerFecha(&fecha);
    ddmmaaaa(&fecha);
    texto(&fecha);
    if (esBisiesto(&fecha)) printf ("El año es Bisiesto.\n");
    leerFecha(&fecha2);
    printf ("Comparacion: %d\n", cmpFecha(&fecha, &fecha2));
    if (!existe(&fecha)) {
        ddmmaaaa(&fecha);
        printf ("No Existe.\n");
    }
    printf ("Diferencia dias: %d\n", diferenciaDias(&fecha, &fecha2));
    return 0;
}
