/*
 * =============================================================================
 *
 *       Filename:  ej208.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/12/13 18:24:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  KELVIN PROVINCIA (), aek6.io@gmail.com
 *   Organization:  aek6
 *
 * =============================================================================
 */
#include <stdio.h>

long fibo(int n, int a, int b) {
    if (n > 1) return a + fibo(--n, a + b, a);
    return 1;
}

long fibonacci(int n) {
    return fibo(n, 0, 1);
}

int main(void) {
    int numero;
    int i;
    printf ("Dame un número: "); scanf ("%d", &numero);
    printf ("El número %d de la serie de Fibonacci es: %ld\n", numero,
            fibonacci(numero));
    for (i = 1; i < 20; i++) {
        printf ("%ld ", fibonacci(i));
    }
    return 0;
}
