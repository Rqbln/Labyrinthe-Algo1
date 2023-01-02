
#ifndef LABYRINTE_SPROG_H
#define LABYRINTE_SPROG_H

#endif //LABYRINTE_SPROG_H

#define LARGEUR 7
#define LARGEUR_FINALE 23
#define CARTES 24
#define BUFFER_SIZE 32
#define LONGUEUR_NOM 50
#define pion_row1 2
#define pion_row3 2
#define pion_row2 20
#define pion_row4 20
#define pion_col1 2
#define pion_col3 20
#define pion_col2 2
#define pion_col4 20

//#ifndef INITPLATEAU_H_INCLUDED
//#define AFFICHAGEC_H_INCLUDED
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <conio.h> // Pour utiliser la fonction getch
#include <stdlib.h>
#include <fcntl.h>
#include <io.h>

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
void ligne();
void caractere(int *caracteres);
void afficherRegles();
void afficherCredits();
void oui_non(int *menu);

void initialisationTableau(int tab[LARGEUR][LARGEUR]);
void init_case_en_plus(int tab[LARGEUR][LARGEUR],int *carterestante, int *test_tresor);
void convertab(int tab[LARGEUR][LARGEUR], int *test_tresor);
void coordonne(int tabfinal[LARGEUR_FINALE][LARGEUR_FINALE], int *x, int *y, int tab[LARGEUR][LARGEUR]);
void affect(int tabfinal[LARGEUR_FINALE][LARGEUR_FINALE], int *x, int *y, int cases[3][3]);

void affichageTableau(int tab[LARGEUR][LARGEUR], int tabfinal[LARGEUR_FINALE][LARGEUR_FINALE]);
void afficheplateauprog(int tab[LARGEUR][LARGEUR], int tabfinal[LARGEUR_FINALE][LARGEUR_FINALE]);
void afficheplateaubinaire(int tab[LARGEUR][LARGEUR], int tabfinal[LARGEUR_FINALE][LARGEUR_FINALE]);
void afficheplateaufinal(int tab[LARGEUR][LARGEUR], int tabfinal[LARGEUR_FINALE][LARGEUR_FINALE]);
void affiche_case_en_plus(int *carterestante);
void afficheCarteJoueur(int *nbJoueurs,int *nbCartesJoueurs, char nomJoueurs[4][LONGUEUR_NOM],int cartesJoueurs[CARTES][CARTES]);
void afficheCarteJoueur1(int *tourJoueur,int *nbCartesJoueurs, char nomJoueurs[4][LONGUEUR_NOM],int cartesJoueurs[CARTES][CARTES],int cartejoueurtab[4]);


void nombreJoueurs(int *nbJoueurs, int *nbCartesJoueurs);
void CreationNomJoueurs(int *nbJoueurs,char nomJoueurs[4][LONGUEUR_NOM]);
void distributionPions(int *nbJoueurs,char nomJoueurs[4][LONGUEUR_NOM],int pionsJoueurs[4]);
void distributionCartes (int *nbJoueurs, int *nbCartesJoueurs, char nomJoueurs[4][LONGUEUR_NOM], int cartesJoueurs[CARTES][CARTES]);
void debutPartie (int *nbJoueurs, int *tourJoueur, char nomJoueurs[4][LONGUEUR_NOM], int pionsJoueurs[4], int* nbTours);

//void deplacementJoueur(int tab[LARGEUR][LARGEUR],int numjoueur,int *posxy[2]);
void deplacementJoueur1(int tabfinal[LARGEUR_FINALE][LARGEUR_FINALE], int tab[LARGEUR][LARGEUR], char nomJoueurs[4][LONGUEUR_NOM], int pionsJoueurs[4],int *tourJoueur, int memoricase[4][1], int *carterestante);
void deplacement_de_tuile(int tab[LARGEUR][LARGEUR], int tabfinal[LARGEUR_FINALE][LARGEUR_FINALE],int *carterestante,int *ligne_ou_colonne, int *numero_ligne_colonne,int *direction);
void selection_ligne_colonne(int tab[LARGEUR][LARGEUR],int tabfinal[LARGEUR_FINALE][LARGEUR_FINALE],int *ligne_ou_colonne, int *numero_ligne_colonne,int *direction, int *carterestante);

void color(int couleurDuTexte,int couleurDeFond);
void text_color(int color); //change la couleur du texte
void bg_color(int color); //change la couleur de fond

