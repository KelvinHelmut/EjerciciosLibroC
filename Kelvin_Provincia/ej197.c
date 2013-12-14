/*
 * =============================================================================
 *
 *       Filename:  ej197.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  30/11/13 14:24:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  KELVIN PROVINCIA (), aek6.io@gmail.com
 *   Organization:  aek6
 *
 * =============================================================================
 */
#include <stdio.h>

#define FILAS       3
#define COLUMNAS    3

#define CIRCULO     'O'
#define CRUZ        'X'
#define VACIA       32

void muestraTablero(char tablero[][COLUMNAS]) {
    int i, j, k;
    char linea[COLUMNAS * 2 + 1];
    for (i = 0; i < FILAS; i++) {
        k = 0;
        for (j = 0; j < COLUMNAS; j++) {
            if (j) printf ("|");
            printf ("%c", tablero[i][j]);
            linea[k++] = '-';
            linea[k++] = '-';
        }
        linea[--k] = '\0';
        printf ("\n");
        if (i + 1 < FILAS) printf ("%s\n", linea);
    }
}

int esLleno(char tablero[][COLUMNAS]) {
    int i, j;
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            if (tablero[i][j] == VACIA) return 0;
        }
    }
    return 1;
}

int tresEnRaya(char tablero[][COLUMNAS]) {
    int i, j;
    char fi, co;
    for (i = 0; i < FILAS; i++) {
        fi = 1; co = 1;
        for (j = 0; j < COLUMNAS - 1; j++) {
            if (tablero[i][j] != tablero[i][j + 1] || tablero[i][j] == VACIA)
                fi = 0;
            if (tablero[j][i] != tablero[j + 1][i] || tablero[j][i] == VACIA)
                co = 0;
            if (!fi && !co) break;
        }
        if (fi || co) return 1;
    }

    for (i = 0; i < FILAS - 1 && i < COLUMNAS - 1; i++) {
        if (tablero[i][i] == VACIA) break;
        if (tablero[i][i] != tablero[i + 1][i + 1]) break;
    }
    if (i >= FILAS  - 1 || i >= COLUMNAS - 1) return 1;

    for (i = 0; i < FILAS && COLUMNAS - i - 1 > 0; i++) {
        if (tablero[i][COLUMNAS - i - 1] == VACIA) break;
        if (tablero[i][COLUMNAS - i - 1] != tablero[i + 1][COLUMNAS - i - 2])
            break;
    }
    if (i >= FILAS || COLUMNAS - i - 1 <= 0) return 1;

    return 0;
}

int jugada(char tablero[][COLUMNAS]) {
    int casilla;
    printf ("Fila y columna: "); scanf ("%d", &casilla);
    if (casilla < 11 || casilla > FILAS * 10 + COLUMNAS ||
        casilla % 10 > COLUMNAS) return 0;
    if (tablero[casilla / 10 - 1][casilla % 10 - 1] != VACIA) return 0;
    tablero[casilla / 10 - 1][casilla % 10 - 1] = CIRCULO;
    return 1;
}

void jugadaAI(char tablero[][COLUMNAS]) {
    int i, j, f = -1, c = -1;
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            if (tablero[i][j] == VACIA) {
                tablero[i][j] = CRUZ;
                if (tresEnRaya(tablero)) return;
                tablero[i][j] = CIRCULO;
                if (tresEnRaya(tablero)) {
                    f = i;
                    c = j;
                }
                tablero[i][j] = VACIA;
            }
        }
    }
    if (f != -1 && c != -1) {
        tablero[f][c] = CRUZ;
        return;
    }

    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            if (tablero[i][j] == VACIA) {
                tablero[i][j] = CRUZ;
                return;
            }
        }
    }
}

void inicializaTablero(char tablero[][COLUMNAS]) {
    int i, j;
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            tablero[i][j] = VACIA;
        }
    }
}

int main(void) {
    char tablero[FILAS][COLUMNAS];
    inicializaTablero(tablero);
    muestraTablero(tablero);
    while(esLleno(tablero) == 0 && tresEnRaya(tablero) == 0) {
        while (!jugada(tablero));
        if (tresEnRaya(tablero)) {
            muestraTablero(tablero);
            printf ("Ganaste..\n");
            return 0;
        }
        jugadaAI(tablero);
        muestraTablero(tablero);
    }
    printf ("Buuuuu Perdiste.\n");
    return 0;
}
