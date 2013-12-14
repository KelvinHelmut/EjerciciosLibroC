/*
 * =============================================================================
 *
 *       Filename:  ej181.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27/11/13 21:17:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  KELVIN PROVINCIA (), aek6.io@gmail.com
 *   Organization:  aek6
 *
 * =============================================================================
 */
#include <stdio.h>

#define TALLA 20

void asigna(int v[], int talla, int valor) {
    int i;
    for (i = 0; i < talla; i++) {
        v[i] = valor;
    }
}

int main(void) {
    int vector[TALLA], talla, valor, i;
    printf ("Número de elementos: "); scanf ("%d", &talla);
    printf ("Valor para los elementos: "); scanf ("%d", &valor);
    asigna(vector, talla, valor);
    for (i = 0; i < talla; i++) {
        printf ("%d, ", vector[i]);
    }
    return 0;
}
