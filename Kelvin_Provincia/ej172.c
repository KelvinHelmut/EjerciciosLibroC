/*
 * =============================================================================
 *
 *       Filename:  ej172.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  23/11/13 21:36:18
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

void ordena(int v[], int talla) {
    int i, aux;
    for (i = 1; i < talla; i++) {
        if (i < 1) continue;
        if (v[i] < v[i - 1]) {
            aux = v[i];
            v[i] = v[i - 1];
            v[i - 1] = aux;
            i -= 2;
        }
    }
}

void mostrar(int v[], int talla) {
    int i;
    for (i = 0; i < talla; i++) {
        printf ("(%d) %d\n", i, v[i]);
    }
}

int main(void) {
    int vector[TALLA];
    int i, t;
    srand((unsigned)time(NULL));
    t = rand() % TALLA + 1;
    for (i = 0; i < t; i++) {
        vector[i] = rand() % 100 + 1;
    }
    mostrar(vector, t);
    ordena(vector, t);
    printf ("Despues de ordenar.\n");
    mostrar(vector, t);
    return 0;
}
