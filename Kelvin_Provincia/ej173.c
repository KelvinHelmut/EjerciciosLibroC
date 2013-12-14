/*
 * =============================================================================
 *
 *       Filename:  ej173.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  23/11/13 22:00:37
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

int getMax(int v[], int talla) {
    int i, max;
    max = v[0];
    for (i = 0; i < talla; i++) {
        if (v[i] > max) max = v[i];
    }
    return max;
}

int main(void) {
    int vector[TALLA];
    int t, i;
    srand((unsigned)time(NULL));
    t = rand() % TALLA + 1;
    for (i = 0; i < t; i++) {
        vector[i] = rand() % 100 + 1;
    }
    for (i = 0; i < t; i++) {
        printf ("%d, ", vector[i]);
    }
    printf ("\nEl valor máximo es: %d\n", getMax(vector, t));
    return 0;
}
