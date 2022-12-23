#include "sprog.h"
#include <stdio.h>
int main() {   //programme principale
    int tab[LARGEUR][LARGEUR];
    int choix;
    int x,y;
    int nbJoueurs;
    int tabfinal[21][21];

    printf("\n");
    //afficherTitre();

    printf("Menu :\n1. Nouvelle partie\n2. Sauvegarder la partie en cours\n3. Charger une partie sauvegardee\n4. Afficher les regles / credits\n0. Quitter le jeu\nChoix :");
    scanf("%d",&choix);
    if (choix==1){
        printf("Nombre de joueurs :");
        scanf("%d",&nbJoueurs);
        printf("Nombre de joueurs choisis : %d\n\n",nbJoueurs);
        initialisationTableau(tab);
        convertab(tab);
        coordonne(tabfinal, &x, &y, tab);
        affichageTableau(tab, tabfinal);
        //afficherTerrain4(&tab[LARGEUR][LARGEUR]);
        //finJeu(&ligne, &colonne, &tab[7][7], &n);
    }
    if (choix==2){

    }
    if (choix==3){

    }
    if (choix==4){

    }
    if (choix==0){

    }


    return 0;
}
