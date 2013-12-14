/*
 * =============================================================================
 *
 *       Filename:  ej182.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27/11/13 21:24:30
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

void intercambia(int v1[], int v2[], int talla) {
    int i, aux;
    for (i = 0; i < talla; i++) {
        aux = v1[i];
        v1[i] = v2[i];
        v2[i] = aux;
    }
}

void mostrar(int v[], int talla) {
    int i;
    for (i = 0; i < talla; i++) {
        printf ("%d, ", v[i]);
    }
    printf ("\n");
}

int main(void) {
    int vector1[TALLA], vector2[TALLA];
    int talla, i;
    srand(time(NULL));
    talla = rand() % TALLA + 1;
    for (i = 0; i < talla; i++) {
        vector1[i] = rand() % 100 + 1;
        vector2[i] = rand() % 100 + 1;
    }
    printf ("Vector 1\n");
    mostrar(vector1, talla);
    printf ("Vector 2\n");
    mostrar(vector2, talla);

    intercambia(vector1, vector2, talla);

    printf ("Despues...\n");
    printf ("Vector 1\n");
    mostrar(vector1, talla);
    printf ("Vector 2\n");
    mostrar(vector2, talla);
    return 0;
}
