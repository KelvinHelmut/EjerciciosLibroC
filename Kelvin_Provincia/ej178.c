/*
 * =============================================================================
 *
 *       Filename:  ej178.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27/11/13 20:59:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  KELVIN PROVINCIA (), aek6.io@gmail.com
 *   Organization:  aek6
 *
 * =============================================================================
 */
#include <stdio.h>

void inversa(float *n) {
    if (*n) *n = 1 / *n;
}

int main(void) {
    float numero;
    printf ("Dame un número: "); scanf ("%f", &numero);
    inversa(&numero);
    printf ("%.2f\n", numero);
    return 0;
}
