/*
 * =============================================================================
 *
 *       Filename:  ej214.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/12/13 09:53:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  KELVIN PROVINCIA (), aek6.io@gmail.com
 *   Organization:  aek6
 *
 * =============================================================================
 */
#include <stdio.h>

#define ABS(N) ((N < 0) ? (-(N)) : N)

int main(void) {
    printf (">> %d\n", ABS(-5));
    printf (">> %d\n", ABS(4));
    printf (">> %f\n", ABS(-2.0));
    printf (">> %f\n", ABS(9.4 * -5));
    return 0;
}
