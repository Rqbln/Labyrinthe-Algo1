#include "sprog.h"
#include <stdio.h>
int main() {   //programme principale
    int joueur1;
    int joueur2;
    int point;
    int ligne, colonne;
    int tab[LARGEUR][LARGEUR];

    int n;
    int choix;
    char**terrain;
    int cases[3][3];
    int x,y;
    int tabfinal[21][21];
    //bg_color(WHITE);
    //text_color(RED);
    //printf("\n\t\t LA MEME MATRICE MAIS 4 AFFICHAGES DIFFERENTS !\n\n");
    //bg_color(BLACK);
    //text_color(WHITE);
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
    initialisationTableau(tab);  //initialise un tableau  de chiffre entre 0 et 5
    convertab(tab);
    coordonne(tabfinal, &x, &y, tab);
    affichageTableau(tab, tabfinal);
    //afficherTerrain4(&tab[LARGEUR][LARGEUR]);
    //finJeu(&ligne, &colonne, &tab[7][7], &n);

    return 0;
}
