//
// Created by bapti on 30/11/2022.
//

#ifndef LABYRINTE_SPROG_H
#define LABYRINTE_SPROG_H

#endif //LABYRINTE_SPROG_H

#define LARGEUR 7
//#ifndef INITPLATEAU_H_INCLUDED
//#define AFFICHAGEC_H_INCLUDED
#include <windows.h>
typedef enum{
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    ORANGE,

    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
} COLORS;

void initialisationTableau(int tab[LARGEUR][LARGEUR]);
void affichageTableau(int tab[LARGEUR][LARGEUR], char tableau[LARGEUR][LARGEUR], int tabite[21][21]);
void essaieJoueur(int *ligne, int *colonne, int *point, int tab[10][10]);
void finJeu(int *ligne, int *colonne, int tab[LARGEUR][LARGEUR], int*n);
void convertab(int tab[LARGEUR][LARGEUR], char tableau[LARGEUR][LARGEUR]);
void text_color(int color);
//change la couleur de fond
void bg_color(int color);
void afficherTerrain4(int tab[LARGEUR][LARGEUR]);
void coordonne(int tabite[21][21], int *x, int *y, int cases[3][3], int tab[LARGEUR][LARGEUR]);
void affect(int tabite[21][21], int *x, int *y, int cases[3][3]);