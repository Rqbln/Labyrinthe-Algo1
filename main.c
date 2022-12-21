#include "sprog.h"
#include <stdio.h>
int main() {   //programme principale
    int joueur1;
    int joueur2;
    int point;
    int ligne, colonne;
    int tab[7][7];
    char tableau[21][21];
    int n;
    int choix;
    char**terrain;
    //bg_color(WHITE);
    text_color(RED);
    printf("\n\t\t LA MEME MATRICE MAIS 4 AFFICHAGES DIFFERENTS !\n\n");
    bg_color(BLACK);
    text_color(WHITE);
    printf("Menu :\n1. Nouvelle partie\n2. Sauvegarder la partie en cours\n3. Charger une partie sauvegardee\n4. Afficher les regles / credits\n0. Quitter le jeu\nChoix :");
    scanf("%d",&choix);
    if (choix==1){

    }
    if (choix==2){

    }
    if (choix==3){

    }
    if (choix==4){

    }
    if (choix==0){

    }
    initialisationTableau(&tab[7][7]);  //initialise un tableau  de chiffre entre 0 et 5
    convertab(&tab[7][7], &tableau[21][21]);
    affichageTableau(&tab[7][7]);
    afficherTerrain4(&tab[LARGEUR][LARGEUR]);
    //finJeu(&ligne, &colonne, &tab[7][7], &n);
    do {
        printf("joueur 1\n");
        essaieJoueur(&ligne, &colonne, &point, &tab[7][7]);
        joueur1+= point;
        printf("ton nombre de point est egale a : %d\n",joueur1);
        printf("joueur 2\n");
        essaieJoueur(&ligne, &colonne, &point, &tab[10][10]);
        joueur2+= point;
        printf("ton nombre de point est egale a : %d\n",joueur2);
        finJeu(&ligne, &colonne,&tab[10][10], &n);
    }
    while(n == 0);
    return 0;
}
