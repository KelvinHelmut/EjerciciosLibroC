/*
 * =============================================================================
 *
 *       Filename:  ej199.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/12/13 12:10:23
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

#define TALLA 20
#define BOMBA -1

enum {facil = 1, medio, dificil};

int talla;

void menu(int *talla, int *bomba){
    int op;
    char linea[10];
    printf ("Seleccione dificultad:\n"
            "1) Fácil\n2) Medio\n3)Difícil\nOpción: ");
    gets(linea); sscanf (linea, "%d", &op);
    switch (op) {
        case facil:	
            *talla = 8;
            *bomba = 10;
            break;

        case medio:	
            *talla = 15;
            *bomba = 40;
            break;

        case dificil:	
            *talla = 20;
            *bomba = 100;
            break;

        default:	
            *talla = 0;
            *bomba = 0;
            break;
    }
}

char esBomba(char tablero[][talla], int fi, int ci) {
    if (tablero[fi][ci] == BOMBA) return 1;
    return 0;
}

int getBombasVecinas(char tablero[][talla], int fi, int ci) {
    int i, j, bombas = 0;
    for (i = fi - 1; i <= fi + 1; i++) {
        if (i < 0 || i >= talla) continue;
        for (j = ci - 1; j <= ci + 1; j++) {
            if (j < 0 || j >= talla) continue;
            if (i == fi && j == ci) continue;
            if (esBomba(tablero, i, j)) bombas++;
        }
    }
    return bombas;
}

int modificar(char tablero[][talla], int fi, int ci) {
    if (esBomba(tablero, fi, ci)) {
        return 0;
    } else {
        tablero[fi][ci] = getBombasVecinas(tablero, fi, ci);
    }
    return 1;
}

int mostrar(char tablero[][talla]) {
    int i, j, restantes;
    printf ("  ");
    for (i = 0; i < talla; i++) {
        printf ("%c", i + 97);
    }
    printf ("\n");
    for (i = 0; i < talla; i++) {
        printf ("%c ", i + 97);
        for (j = 0; j < talla; j++) {
            if (tablero[i][j] == 32 || tablero[i][j] == BOMBA){
                printf ("-");
                restantes++;
            } else {
                printf ("%d", tablero[i][j]);
            }
        }
        printf ("\n");
    }
    return restantes;
}

int main(void) {
    char tablero[TALLA][TALLA];
    int bomba, indice, i;
    char fila, columna;
    char linea[10];

    menu(&talla, &bomba);
    for (i = 0; i < talla * talla; i++) {
        tablero[0][i] = 32;
    }
    i = 0;
    srand(time(NULL));
    while(i < bomba) {
        indice = rand() % (talla * talla);
        if (tablero[0][indice] == 32) {
            tablero[0][indice] = BOMBA;
            i++;
        }
    }
    while (mostrar(tablero) != bomba) {
        printf ("Fila: "); gets(linea); sscanf (linea, "%c", &fila);
        printf ("Columna: "); gets(linea); sscanf (linea, "%c", &columna);
        fila -= 97;
        columna -= 97;
        if ((fila < 0 || fila >= talla) || (columna < 0 || columna >= talla)) {
            continue;
        }
        if (!modificar(tablero, fila, columna)) {
            printf ("PERDISTE!!!\n");
            return 0;
        }
    }; // while(modificar(tablero, fila, columna));
    printf ("Ganaste!\n");
    return 0;
}
