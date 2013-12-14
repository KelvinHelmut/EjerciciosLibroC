/*
 * =============================================================================
 *
 *       Filename:  ej170.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  23/11/13 20:53:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  KELVIN PROVINCIA (), aek6.io@gmail.com
 *   Organization:  aek6
 *
 * =============================================================================
 */
#include <stdio.h>

#define TALLA 11

void suma(float p[], float q[], float r[]) {
    int i;
    for (i = 0; i < TALLA; i++) {
        r[i] = p[i] + q[i];
    }
}

int getGrado(char c) {
    int g;
    do {
        printf ("Grado de %c (entre 0 y %d): ", c, TALLA - 1); scanf ("%d", &g);
    } while(g < 0 || g >= TALLA);
    return g;
}

void llenaPolinomio(float v[], char c) {
    int i, g = getGrado(c);
    for (i = 0; i <= g; i++) {
        printf ("%c_%d: ", c, i); scanf ("%f", &v[i]);
    }
    for (i = g + 1; i < TALLA; i++) {
        v[i] = 0.0;
    }
}

void mostrarVector(float v[], char c) {
    int i;
    for (i = 0; i < TALLA; i++) {
        printf ("%c_%d -> %.3f\n", c, i, v[i]);
    }
}

int main(void) {
    float p[TALLA], q[TALLA], r[TALLA];
    llenaPolinomio(p, 'p');
    llenaPolinomio(q, 'q');
    suma(p, q, r);
    mostrarVector(r, 'r');
    return 0;
}
