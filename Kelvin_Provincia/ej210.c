/*
 * =============================================================================
 *
 *       Filename:  ej210.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/12/13 19:46:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  KELVIN PROVINCIA (), aek6.io@gmail.com
 *   Organization:  aek6
 *
 * =============================================================================
 */
#include <stdio.h>

void muestra_bin(int n) {
    if (n <= 1) {
        printf ("%d", n);
    } else {
        muestra_bin(n / 2);
        printf ("%d", n % 2);
    }
}

int main(void) {
    int numero;
    printf ("Dame un número: "); scanf ("%d", &numero);
    muestra_bin(numero);
    return 0;
}
