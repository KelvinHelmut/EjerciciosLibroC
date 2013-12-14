/*
 * =============================================================================
 *
 *       Filename:  ej171.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  23/11/13 21:22:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  KELVIN PROVINCIA (), aek6.io@gmail.com
 *   Organization:  aek6
 *
 * =============================================================================
 */
#include <stdio.h>
#include <string.h>

#define MAXLON 80

int getFrecuencia(char cadena[], char c) {
    int i, f = 0, lon = strlen(cadena);
    for (i = 0; i < lon; i++) {
        if (cadena[i] == c) f++;
    }
    return f;
}

int main(void) {
    char cadena[MAXLON + 1], caracter;
    printf ("Dame una cadena: "); gets(cadena);
    printf ("Dame un caracter: "); scanf ("%c", &caracter);
    printf ("El caracter \"%c\" aparece %d veces en la cadena \"%s\".\n",
            caracter, getFrecuencia(cadena, caracter), cadena);
    return 0;
}
