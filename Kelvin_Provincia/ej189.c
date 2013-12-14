/*
 * =============================================================================
 *
 *       Filename:  ej189.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  28/11/13 20:52:02
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

void muestra_punto(struct Punto p) {
    printf ("(%f, %f)\n", p.x, p.y);
}

void lee_punto(struct Punto *p) {
    printf ("Dame el valor de \"x\": "); scanf ("%f", &p->x);
    printf ("Dame el valor de \"y\": "); scanf ("%f", &p->y);
}

int main(void) {
    struct Punto p1;
    lee_punto(&p1);
    muestra_punto(p1);
    return 0;
}
