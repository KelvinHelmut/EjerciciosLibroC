/*
 * =============================================================================
 *
 *       Filename:  ej215.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/12/13 10:04:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  KELVIN PROVINCIA (), aek6.io@gmail.com
 *   Organization:  aek6
 *
 * =============================================================================
 */
#include <stdio.h>

#define DECREMENTAPOSITIVO(N) ((N > 0) ? --(N) : N)

int main(void) {
    int numero;
    printf ("Dame un número entero: "); scanf ("%d", &numero);
    printf (">> %d\n", DECREMENTAPOSITIVO(numero));
    return 0;
}
