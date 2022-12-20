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

void initialisationTableau(int tab[7][7]);
void affichageTableau(int tab[7][7]);
void essaieJoueur(int *ligne, int *colonne, int *point, int tab[10][10]);
void finJeu(int *ligne, int *colonne, int tab[7][7], int*n);
void convertab(int tab[7][7], char tableau[21][21]);
void text_color(int color);
//change la couleur de fond
void bg_color(int color);
void afficherTerrain4(int tab[LARGEUR][LARGEUR], int taille);