/*
 * =============================================================================
 *
 *       Filename:  ej198.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/12/13 10:49:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  KELVIN PROVINCIA (), aek6.io@gmail.com
 *   Organization:  aek6
 *
 * =============================================================================
 */
#include <stdio.h>

#define FILAS       10
#define COLUMNAS    10

int getVecinos(char tablero[][COLUMNAS], int fi, int ci) {
    int i, j, vecinos = 0;
    for (i = fi - 1; i <= fi + 1; i++) {
        if (i < 0 || i >= FILAS) continue;
        for (j = ci - 1; j <= ci + 1; j++) {
            if (j < 0 || j >= COLUMNAS) continue;
            if (i == fi && j == ci) continue;
            if (tablero[i][j]) vecinos++;
        }
    }
    return vecinos;
}

void vidaomuerte(char tablero[][COLUMNAS]) {
    int i, j;
    char vecinos;
    char aux[FILAS][COLUMNAS];
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            aux[i][j] = tablero[i][j];
        }
    }
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            vecinos = getVecinos(aux, i, j);
            if (aux[i][j] && (vecinos <= 1 || vecinos == 4)) tablero[i][j] = 0;
            if (!aux[i][j] && vecinos == 3) tablero[i][j] = 1;
        }
    }
}

void mostrar(char tablero[][COLUMNAS]) {
    int i, j;
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            if (tablero[i][j]) {
                printf ("x");
            } else {
                printf ("-");
            }
        }
        printf ("\n");
    }
}

int main(void) {
    char matriz[FILAS][COLUMNAS];
    char linea[80];
    int i, j, ciclos;
    printf ("Configuración inicial:\n");
    for (i = 0; i < FILAS; i++) {
        gets(linea);
        for (j = 0; j < COLUMNAS; j++) {
            if (linea[j] == 'x') {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
    printf ("Ciclos: "); scanf ("%d", &ciclos);
    for (i = 0; i < ciclos; i++) {
        vidaomuerte(matriz);
        mostrar(matriz);
        printf ("\n");
    }
    return 0;
}
