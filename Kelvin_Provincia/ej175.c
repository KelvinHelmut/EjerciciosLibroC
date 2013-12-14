/*
 * =============================================================================
 *
 *       Filename:  ej175.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  23/11/13 22:15:25
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

char sonIguales(int v1[], int v2[], int talla) {
    int i;
    for (i = 0; i < talla; i++) {
        if (v1[i] != v2[i]) return 0;
    }
    return 1;
}

void inicializa(int v[], int talla) {
    int i;
    for (i = 0; i < talla; i++) {
        printf ("%d): ", i + 1); scanf ("%d", &v[i]);
    }
}

int main(void) {
    int vector1[TALLA], vector2[TALLA], t;
    printf ("Dame la talla de los vectores: "); scanf ("%d", &t);
    printf ("Vector 1\n");
    inicializa(vector1, t);
    printf ("Vector 2\n");
    inicializa(vector2, t);
    (sonIguales(vector1, vector2, t)) ? printf ("Son iguales.\n") :
                                        printf ("No son iguales.\n");
    return 0;
}
