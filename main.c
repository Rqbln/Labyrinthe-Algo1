#include "sprog.h"
#include <stdio.h>
int main() {   //programme principale
    int tab[LARGEUR][LARGEUR];
    int choix;
    int x,y;
    int nbJoueurs;
    int tabfinal[21][21];
    int partie = 0;
    int credit =0;
    int sauvegarde1tab[LARGEUR][LARGEUR];
    int sauvegardetourjoueur;
    int numjoueur;

    printf("\n");
    afficherTitre();

    printf("Menu :\n1. Nouvelle partie\n2. Sauvegarder la partie en cours\n3. Charger une partie sauvegardee\n4. Afficher les regles / credits\nEntrez n'importe quelle valeur pour quitter le jeu\n\n");

    while (partie==0){
        printf("Choix :");
        scanf("%d",&choix);
        printf("\n");
        switch (choix) {
            case 1:
                printf("Nombre de joueurs :");
                scanf("%d",&nbJoueurs);
                printf("Nombre de joueurs choisis : %d\n\n",nbJoueurs);
                initialisationTableau(tab);
                convertab(tab);
                coordonne(tabfinal, &x, &y, tab);
                //afficheplateauprog(tab, tabfinal);
                //afficheplateaubinaire(tab, tabfinal);
                afficheplateaufinal(tab, tabfinal);
                //affichageTableau(tab, tabfinal);


                //afficherTerrain4(&tab[LARGEUR][LARGEUR]);
                //finJeu(&ligne, &colonne, &tab[7][7], &n);
                break;
            case 2:
                printf("Sauvegarde de la partie en cours...\n");
                for (int i = 0; i < LARGEUR; ++i) {
                    for (int j = 0; j < LARGEUR; ++j) {
                        sauvegarde1tab[i][j]=tab[i][j];
                    }
                }
                sauvegardetourjoueur=numjoueur;
                printf("Sauvegarde terminee\n");


                break;
            case 3:
                printf("Lancement de la partie sauvegardee...\n");
                //tab[LARGEUR][LARGEUR]=sauvegarde1tab[LARGEUR][LARGEUR];
                numjoueur=sauvegardetourjoueur;
                convertab(sauvegarde1tab);
                coordonne(tabfinal, &x, &y, sauvegarde1tab);
                afficheplateaufinal(sauvegarde1tab, tabfinal);
                break;
            case 4:
                printf("Vous avez %d credit(s)\n\n", credit);
                printf("Regles du jeu de societe Labyrinthe:\n\n");
                printf("Le but du jeu est d'etre le premier a trouver la sortie du labyrinthe avec son pion.\n");
                printf("Pour se deplacer, les joueurs tirent un de et avancent leur pion du nombre de cases correspondant.\n");
                printf("Si un joueur tombe sur une case avec un objet, il peut le prendre et le garder jusqu'a ce qu'il en ait besoin ou decider de le donner a un autre joueur.\n");
                printf("Les objets peuvent etre utilises pour ouvrir des portes ou des passages secrets, ou pour deplacer des obstacles dans le labyrinthe.\n");
                printf("Le premier joueur a sortir du labyrinthe est declare vainqueur.\n");
                break;
            default:
                printf("Deconnexion... A bientot !\n");
                partie=1;
        }


    }


    return 0;
}
