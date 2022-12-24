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
void afficherTitre();

void initialisationTableau(int tab[LARGEUR][LARGEUR]);
void convertab(int tab[LARGEUR][LARGEUR]);
void coordonne(int tabfinal[21][21], int *x, int *y, int tab[LARGEUR][LARGEUR]);
void affect(int tabfinal[21][21], int *x, int *y, int cases[3][3]);

void affichageTableau(int tab[LARGEUR][LARGEUR], int tabfinal[21][21]);
void afficheplateauprog(int tab[LARGEUR][LARGEUR], int tabfinal[21][21]);
void afficheplateaubinaire(int tab[LARGEUR][LARGEUR], int tabfinal[21][21]);
void afficheplateaufinal(int tab[LARGEUR][LARGEUR], int tabfinal[21][21]);

void tourjoueur(int *numjoueur, int *echap, int *nbJoueurs);







void essaieJoueur(int *ligne, int *colonne, int *point, int tab[7][7]);
void finJeu(int *ligne, int *colonne, int tab[LARGEUR][LARGEUR], int*n);
void text_color(int color);
//change la couleur de fond
void bg_color(int color);
void afficherTerrain4(int tab[LARGEUR][LARGEUR]);
