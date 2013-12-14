/*
 * =============================================================================
 *
 *       Filename:  ej177.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  23/11/13 22:30:21
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
#include <time.h>

#define TALLA 20

void mostrar(float v[], int talla) {
    int i, c = 0;
    char fin;
    for (i = 0; i < talla; i++) {
        c++;
        fin = ',';
        if (c == 6) {
            c = 0;
            fin = '\n';
        }
        printf (" %.3f%c", v[i], fin);
    }
}

int main(void) {
    float numeros[TALLA];
    int i, t;
    srand((unsigned)time(NULL));
    t = rand() % TALLA + 1;
    for (i = 0; i < t; i++) {
        numeros[i] = (rand() % 100 + 1) / (float)(rand() % 100 + 1);
    }
    mostrar(numeros, t);
    return 0;
}
