/*
 * =============================================================================
 *
 *       Filename:  ej183.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27/11/13 21:37:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  KELVIN PROVINCIA (), aek6.io@gmail.com
 *   Organization:  aek6
 *
 * =============================================================================
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TALLA 20

void suma(int *n, int v[], int talla) {
    int i;
    *n = 0;
    for (i = 0; i < talla; i++) {
        *n += v[i];
    }
}

int main(void) {
    int vector[TALLA], numero, talla, i;
    srand(time(NULL));
    talla = rand() % TALLA + 1;
    for (i = 0; i < talla; i++) {
        vector[i] = rand() % 100 + 1;
    }
    suma(&numero, vector, talla);
    printf ("Vector: ");
    for (i = 0; i < talla; i++) {
        printf ("%d, ", vector[i]);
    }
    printf ("\nSuma: %d\n", numero);
    return 0;
}
