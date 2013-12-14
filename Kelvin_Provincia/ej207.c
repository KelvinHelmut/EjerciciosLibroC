/*
 * =============================================================================
 *
 *       Filename:  ej207.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/12/13 18:11:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  KELVIN PROVINCIA (), aek6.io@gmail.com
 *   Organization:  aek6
 *
 * =============================================================================
 */
#include <stdio.h>

double potencia(float x, int n) {
    if (n == 0) return 1;
    if (n > 0) return x * potencia(x, --n);
    return 1 / x * potencia(x, ++n);
}

int main(void) {
    float base;
    int expo;
    printf ("Dame un número: "); scanf ("%f", &base);
    printf ("Dame un otro número: "); scanf ("%d", &expo);
    printf ("%.2f ^ %d = %.2f\n", base, expo, potencia(base, expo));
    return 0;
}
