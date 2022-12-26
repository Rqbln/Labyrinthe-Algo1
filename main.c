#include "sprog.h"
#include <stdio.h>
#include <stdlib.h> // bibliothèque pour la fonction system
int main() {   //programme principale
    int tab[LARGEUR][LARGEUR];
    int x,y;
    char choix, nbJoueurs;
    int nbCartesJoueurs;
    int cartesJoueurs[nbJoueurs][nbCartesJoueurs];
    int tabfinal[21][21];
    int tresor[24],tresor1[24],tresor2[24],tresor3[24],tresor4[24];
    int partie=0;
    int sauvegarde1tab[LARGEUR][LARGEUR];
    int sauvegardetourjoueur;
    int numjoueur=1;
    int echap=0;
    int carterestante;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    printf("\n");
    afficherTitre();

    printf("Menu :\n1. Nouvelle partie\n2. Sauvegarder la partie en cours\n3. Charger une partie sauvegardee\n4. Afficher les regles / credits\n0. Quitter le jeu\n\n");

    while (partie==0){

        printf("Choix :");
        scanf("%s",&choix);
        switch (choix) {

            case '0':
                printf("Deconnexion... A bientot !\n");
                partie=1;
            case '1':

                while (nbJoueurs!='2' && nbJoueurs!='3' && nbJoueurs!='4'){

                    printf("Nombre de joueurs (entre 2 et 4) :");
                    scanf("%s",&nbJoueurs);
                }

                printf("Nombre de joueurs choisis : %c\n\n",nbJoueurs);
                initialisationTableau(tab);
                init_case_en_plus(tab, &carterestante);
                convertab(tab);
                coordonne(tabfinal, &x, &y, tab);
                //afficheplateauprog(tab, tabfinal);
                //afficheplateaubinaire(tab, tabfinal);
                afficheplateaufinal(tab, tabfinal);
                //affichageTableau(tab, tabfinal);
                //tourjoueur(&numjoueur, &echap, &nbJoueurs);
                distributionCartes(&nbJoueurs, tresor, tresor1, tresor2, tresor3, tresor4);

                //afficherTerrain4(&tab[LARGEUR][LARGEUR]);
                //finJeu(&ligne, &colonne, &tab[7][7], &n);
                printf("\n");
                printf("\n");
                //printf("%d", carterestante);
                affiche_case_en_plus(&carterestante);


                //getchar(); // attend que l'utilisateur appuie sur une touche
                //fgetc(stdin);


                break;
            case '2':
                printf("Sauvegarde de la partie en cours...\n");
                for (int i = 0; i < LARGEUR; ++i) {
                    for (int j = 0; j < LARGEUR; ++j) {
                        sauvegarde1tab[i][j]=tab[i][j];
                    }
                }
                sauvegardetourjoueur=numjoueur;
                printf("Sauvegarde terminee\n");


                break;
            case '3':
                printf("Lancement de la partie sauvegardee...\n");
                //tab[LARGEUR][LARGEUR]=sauvegarde1tab[LARGEUR][LARGEUR];
                numjoueur=sauvegardetourjoueur;
                convertab(sauvegarde1tab);
                coordonne(tabfinal, &x, &y, sauvegarde1tab);
                afficheplateaufinal(sauvegarde1tab, tabfinal);
                break;
            case '4':
                printf("Regles du jeu de societe Labyrinthe:\n\n");
                printf("Le but du jeu est d'etre le premier a trouver la sortie du labyrinthe avec son pion.\n");
                printf("Pour se deplacer, les joueurs tirent un de et avancent leur pion du nombre de cases correspondant.\n");
                printf("Si un joueur tombe sur une case avec un objet, il peut le prendre et le garder jusqu'a ce qu'il en ait besoin ou decider de le donner a un autre joueur.\n");
                printf("Les objets peuvent etre utilises pour ouvrir des portes ou des passages secrets, ou pour deplacer des obstacles dans le labyrinthe.\n");
                printf("Le premier joueur a sortir du labyrinthe est declare vainqueur.\n");
                break;
            default:
                partie=0;
                choix=-1;

        }


    }


    return 0;
}
