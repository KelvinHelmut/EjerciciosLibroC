/*
 * =============================================================================
 *
 *       Filename:  ej174.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  23/11/13 22:08:18
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

char esPalindromo(int v[], int talla) {
    int i;
    for (i = 0; i < talla / 2; i++) {
        if (v[i] != v[talla - i -1]) return 0;
    }
    return 1;
}

int main(void) {
    int numeros[TALLA];
    int t, i;
    printf ("Cantidad de números: "); scanf ("%d", &t);
    for (i = 0; i < t; i++) {
        printf ("%d): ", i + 1); scanf ("%d", &numeros[i]);
    }
    if (esPalindromo(numeros, t)) {
        printf ("Es palindromo\n");
    } else {
        printf ("No es palindromo\n");
    }
    return 0;
}
