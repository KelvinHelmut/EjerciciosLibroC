/*
 * =============================================================================
 *
 *       Filename:  ej176.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  23/11/13 22:24:01
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

void mostrar(int v[], int talla) {
    int i;
    for (i = 0; i < talla - 1; i++) {
        printf ("%d, ", v[i]);
    }
    printf ("%d\n", v[i]);
}

int main(void) {
    int numeros[TALLA], i, t;
    srand((unsigned)time(NULL));
    t = rand() % TALLA + 1;
    for (i = 0; i < t; i++) {
        numeros[i] = rand() % 100 + 1;
    }
    mostrar(numeros, t);
    return 0;
}
