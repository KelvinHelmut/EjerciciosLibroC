/*
 * =============================================================================
 *
 *       Filename:  ej194.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  28/11/13 21:15:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  KELVIN PROVINCIA (), aek6.io@gmail.com
 *   Organization:  aek6
 *
 * =============================================================================
 */
#include <stdio.h>

struct Punto {
    float x, y;
};

int iguales(struct Punto p1, struct Punto p2) {
    if (p1.x == p2.x && p1.y == p2.y) return 1;
    return 0;
}

int main(void) {
    struct Punto p1, p2;
    printf ("Dame el valore de p1_x: "); scanf ("%f", &p1.x);
    printf ("Dame el valore de p1_y: "); scanf ("%f", &p1.y);
    printf ("Dame el valore de p2_x: "); scanf ("%f", &p2.x);
    printf ("Dame el valore de p2_y: "); scanf ("%f", &p2.y);
    (iguales(p1, p2)) ? printf ("Son iguales.\n") : printf ("No son iguales.\n");
    return 0;
}
