/*
 * =============================================================================
 *
 *       Filename:  ej187.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  28/11/13 18:53:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  KELVIN PROVINCIA (), aek6.io@gmail.com
 *   Organization:  aek6
 *
 * =============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TALLA 10

int busca(int v[], int talla, int buscado, int *distancia, int *proximo) {
    int i, diferencia;
    *distancia = (v[0] > buscado) ? v[0] - buscado : buscado - v[0];
    *proximo = v[0];
    for (i = 0; i < talla; i++) {
        if (v[i] == buscado) return 1;
        diferencia = (v[i] > buscado) ? v[i] - buscado : buscado - v[i];
        if (diferencia < *distancia) {
            *distancia = diferencia;
            *proximo = v[i];
        }
    }
    return 0;
}

int main(void) {
    int vector[TALLA], talla, i, buscado, distancia, proximo;
    srand(time(NULL));
    talla = rand() % TALLA + 1;
    for (i = 0; i < talla; i++) {
        vector[i] = rand() % 20 + 1;
    }
    printf ("Ingrese el número buscado: "); scanf ("%d", &buscado);
    for (i = 0; i < talla; i++) {
        printf ("%d, ", vector[i]);
    }
    if (busca(vector, talla, buscado, &distancia, &proximo)) {
        printf ("\nEncontre el valor %d.\n", buscado);
    } else {
        printf ("\nNo está. El elemento mas próximo está a distancia %d, y es: "
                "%d.\n", distancia, proximo);
    }
    return 0;
}
