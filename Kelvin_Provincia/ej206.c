/*
 * =============================================================================
 *
 *       Filename:  ej206.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/12/13 11:22:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  KELVIN PROVINCIA (), aek6.io@gmail.com
 *   Organization:  aek6
 *
 * =============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define FILAS           9
#define COLUMNAS        20
#define TALLACAD        80
#define MAX_NAUFRAGOS   20
#define SONDAS          20

#define NO_SONDEADA     '+'
#define RESCATADO       'X'
#define SONDEADA        '.'

#define NAUFRAGO        100
#define NORMAL          50

typedef struct {
    char tipo;
    char estado;
} Casilla;

typedef struct {
    Casilla casillas[FILAS][COLUMNAS];
    int sondas_disponibles;
    int perdidos;
    int naufragos;
} Tablero;

int de_numero_y_letra_a_fila_y_columna(char coordenadas[], int *fila,
        int *columna) {
    printf (">>> %s\n", coordenadas);
    if (strlen(coordenadas) != 2) return 0;
    if (coordenadas[0] >= '0' && coordenadas[0] < '0' + FILAS &&
            isalpha(coordenadas[1])) {
        *fila = coordenadas[0] - '0';
        *columna = toupper(coordenadas[1]) - 'A';
        if (*columna >= COLUMNAS) return 0;
        return 1;
    }
    if (coordenadas[1] >= '0' && coordenadas[1] < '0' + FILAS &&
            isalpha(coordenadas[0])) {
        *columna = toupper(coordenadas[0]) - 'A';
        *fila = coordenadas[1] - '0';
        if (*columna >= COLUMNAS) return 0;
        return 1;
    }
    return 0;
}

void pon_naufragos(Tablero *tablero) {
    int fila, columna, cantidad = 0;
    while(cantidad < tablero -> naufragos) {
        fila = rand() % FILAS;
        columna = rand() % COLUMNAS;
        if (tablero -> casillas[fila][columna].tipo == NORMAL) {
            tablero -> casillas[fila][columna].tipo = NAUFRAGO;
            cantidad++;
        }
    }
}

int hay_naufrago(int fila, int columna, Tablero *tablero) {
    if (tablero -> casillas[fila][columna].tipo == NAUFRAGO) return 1;
    return 0;
}

void inicializa_tablero(Tablero *tablero) {
    int i, j;

    /* tablero -> sondas_disponibles = SONDAS; */
    /* tablero -> perdidos = MAX_NAUFRAGOS; */
    tablero -> perdidos = tablero -> naufragos;
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            tablero -> casillas[i][j].tipo = NORMAL;
            tablero -> casillas[i][j].estado = NO_SONDEADA;
        }
    }
}

void muestra_tablero(Tablero *tablero) {
    int i, j;

    printf ("  ");
    for (i = 0; i < COLUMNAS; i++) printf ("%c", 'A' + i);
    printf ("\n");

    for (i = 0; i < FILAS; i++) {
        printf ("%d ", i);
        for (j = 0; j < COLUMNAS; j++) {
            if (tablero -> casillas[i][j].estado <= 9) {
                printf ("%c", tablero -> casillas[i][j].estado + '0');
            } else {
                printf ("%c", tablero -> casillas[i][j].estado);
            }
        }
        printf ("\n");
    }
}

void lanzar_sonda(int fila, int columna, Tablero *tablero) {
    int i, j, detectados = 0;

    for (i = 0; i < FILAS; i++) {
        if (hay_naufrago(i, columna, tablero)) detectados++;
        if (tablero -> casillas[i][columna].estado == NO_SONDEADA)
            tablero -> casillas[i][columna].estado = SONDEADA;
    }

    for (i = 0; i < COLUMNAS; i++) {
        if (hay_naufrago(fila, i, tablero)) detectados++;
        if (tablero -> casillas[fila][i].estado == NO_SONDEADA)
            tablero -> casillas[fila][i].estado = SONDEADA;
    }

    i = (fila > columna) ? fila - columna - 1 : -1;
    j = (columna > fila) ? columna - fila - 1: -1;
    while(++i < FILAS && ++j < COLUMNAS) {
        if (hay_naufrago(i, j, tablero)) detectados++;
        if (tablero -> casillas[i][j].estado == NO_SONDEADA)
            tablero -> casillas[i][j].estado = SONDEADA;
    }

    i = fila - (COLUMNAS - columna) - 1;
    if (i < 0) i = -1;
    j = (columna + fila < COLUMNAS) ? columna + fila + 1 : COLUMNAS;
    while(++i < FILAS && --j >= 0) {
        if (hay_naufrago(i, j, tablero)) detectados++;
        if (tablero -> casillas[i][j].estado == NO_SONDEADA)
            tablero -> casillas[i][j].estado = SONDEADA;
    }

    if (hay_naufrago(fila, columna, tablero)) {
        tablero -> casillas[fila][columna].estado = RESCATADO;
        tablero -> perdidos--;
    } else {
        tablero -> casillas[fila][columna].estado = detectados;
    }
}

void muestra_naufragos(Tablero *tablero) {
    int i, j;
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            if (tablero -> casillas[i][j].tipo == NAUFRAGO)
                printf ("%d%c\n", i, j + 'A');
        }
    }
}

void seleccion_de_dificultad(Tablero *tablero) {
    int n = 0;
    char linea[TALLACAD + 1];
    while(n <= 0 || n > 20) {
        printf ("Número de náufragos perdidos (0 - 20): "); 
        gets(linea); sscanf (linea, "%d", &n);
    }
    tablero -> naufragos = n;
    printf ("Número de sondas: ");
    gets(linea); sscanf (linea, "%d", &tablero -> sondas_disponibles);
}


int main(void) {
    Tablero espacio;
    char coordenadas[TALLACAD + 1];
    int fila, columna;

    srand(time(0));

    seleccion_de_dificultad(&espacio);
    inicializa_tablero(&espacio);
    pon_naufragos(&espacio);
    muestra_tablero(&espacio);

    while(espacio.sondas_disponibles > 0 && espacio.perdidos > 0) {
        /* muestra_naufragos(&espacio); */
        printf ("Hay %d náufragos\n", espacio.perdidos);
        printf ("Dispones de %d sondas\n", espacio.sondas_disponibles);
        printf ("Coordenadas: "); scanf ("%s", coordenadas);
        while(!de_numero_y_letra_a_fila_y_columna(coordenadas, &fila, &columna))
        {
            printf ("Coordenadas no válidas. Inténtelo de nuevo. "
                    "\nCoordenadas: ");
            scanf ("%s", coordenadas);
        }
        lanzar_sonda(fila, columna, &espacio);
        muestra_tablero(&espacio);
        espacio.sondas_disponibles--;
    }
    if (!espacio.perdidos) {
        printf ("Has ganado. Puntuación: %d puntos.\n",
                SONDAS * espacio.sondas_disponibles);
    } else {
        printf ("Has perdido. Por tu culpa han muerto %d náufragos.\n",
                espacio.perdidos);
    }
    return 0;
}
