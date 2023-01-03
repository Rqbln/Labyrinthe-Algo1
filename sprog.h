// sprog.h
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
#define pion_col3 11 //20 c est juste pour le test
#define pion_col2 2
#define pion_col4 20

//#ifndef INITPLATEAU_H_INCLUDED
//#define AFFICHAGEC_H_INCLUDED
#include <windows.h>
#include <time.h>
#include <fcntl.h>
#include <io.h>
#include <stdio.h> // Pour utiliser la fonction printf
#include <stdlib.h> // Pour utiliser la fonction getch
#include <conio.h> // Pour utiliser la fonction getch

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
void afficheCarteJoueur(int *tourJoueur,int *nbCartesJoueurs, char nomJoueurs[4][LONGUEUR_NOM],int cartesJoueurs[CARTES][CARTES],int cartejoueurtab[4]);


void nombreJoueurs(int *nbJoueurs, int *nbCartesJoueurs);
void CreationNomJoueurs(int *nbJoueurs,char nomJoueurs[4][LONGUEUR_NOM]);
void distributionPions(int *nbJoueurs,char nomJoueurs[4][LONGUEUR_NOM],int pionsJoueurs[4]);
void distributionCartes (int *nbJoueurs, int *nbCartesJoueurs, char nomJoueurs[4][LONGUEUR_NOM], int cartesJoueurs[CARTES][CARTES]);
void debutPartie (int *nbJoueurs, int *tourJoueur, char nomJoueurs[4][LONGUEUR_NOM], int pionsJoueurs[4], int* nbTours);


void deplacementJoueur(int tabfinal[LARGEUR_FINALE][LARGEUR_FINALE], int tab[LARGEUR][LARGEUR], char nomJoueurs[4][LONGUEUR_NOM], int pionsJoueurs[4],int *tourJoueur, int memoricase[4][1], int *carterestante);
void deplacement_de_tuile(int tab[LARGEUR][LARGEUR], int tabfinal[LARGEUR_FINALE][LARGEUR_FINALE],int *carterestante,int *ligne_ou_colonne, int *numero_ligne_colonne,int *direction);
void selection_ligne_colonne(int tab[LARGEUR][LARGEUR],int tabfinal[LARGEUR_FINALE][LARGEUR_FINALE],int *ligne_ou_colonne, int *numero_ligne_colonne,int *direction, int *carterestante);

void color(int couleurDuTexte,int couleurDeFond);
