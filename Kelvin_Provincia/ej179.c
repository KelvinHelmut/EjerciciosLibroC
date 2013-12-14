/*
 * =============================================================================
 *
 *       Filename:  ej179.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27/11/13 21:07:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  KELVIN PROVINCIA (), aek6.io@gmail.com
 *   Organization:  aek6
 *
 * =============================================================================
 */
#include <stdio.h>

void intercambia(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main(void) {
    int n1, n2;
    printf ("Dame un número: "); scanf ("%d", &n1);
    printf ("Dame otro número: "); scanf ("%d", &n2);
    intercambia(&n1, &n2);
    printf ("%d   %d\n", n1, n2);
    return 0;
}
