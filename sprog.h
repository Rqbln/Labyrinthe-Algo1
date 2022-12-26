
#ifndef LABYRINTE_SPROG_H
#define LABYRINTE_SPROG_H

#endif //LABYRINTE_SPROG_H

#define LARGEUR 7
#define CARTES 24
#define BUFFER_SIZE 32

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
    WHITE,
} COLORS;


void afficherTitre();

void initialisationTableau(int tab[LARGEUR][LARGEUR]);
void init_case_en_plus(int tab[LARGEUR][LARGEUR],int *carterestante);
void convertab(int tab[LARGEUR][LARGEUR]);
void coordonne(int tabfinal[21][21], int *x, int *y, int tab[LARGEUR][LARGEUR]);
void affect(int tabfinal[21][21], int *x, int *y, int cases[3][3]);

void affichageTableau(int tab[LARGEUR][LARGEUR], int tabfinal[21][21]);
void afficheplateauprog(int tab[LARGEUR][LARGEUR], int tabfinal[21][21]);
void afficheplateaubinaire(int tab[LARGEUR][LARGEUR], int tabfinal[21][21]);
void afficheplateaufinal(int tab[LARGEUR][LARGEUR], int tabfinal[21][21]);
void affiche_case_en_plus(int *carterestante);

void nombreJoueurs(int *nbJoueurs, int *nbCartesJoueurs);
void distributionCartes (int *nbJoueurs, int *nbCartesJoueurs, int cartesJoueurs[CARTES][CARTES]);
void tourjoueur(int *numjoueur, int *echap, int *nbJoueurs);

void text_color(int color); //change la couleur du texte
void bg_color(int color); //change la couleur de fond

