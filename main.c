#include "sprog.h"
#include <stdio.h>
int main() {   //programme principal
    int tab[LARGEUR][LARGEUR];
    char buffer[BUFFER_SIZE];
    int x,y,nbJoueurs;
    char choix;
    int nbCartesJoueurs;
    int cartesJoueurs[CARTES][CARTES];
    int tabfinal[21][21];
    int partie=0;
    int sauvegarde1tab[LARGEUR][LARGEUR];
    int sauvegardetourjoueur;
    int numjoueur=1;
    int echap=0;
    int carterestante;

    //Positions initiale des joueurs
    int posxy1[2]={0,0};
    int posxy2[2]={0,7};
    int posxy3[2]={7,0};
    int posxy4[2]={7,7};

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

                initialisationTableau(tab);
                init_case_en_plus(tab, &carterestante);
                convertab(tab);
                coordonne(tabfinal, &x, &y, tab);
                afficheplateauprog(tab, tabfinal);
                afficheplateaubinaire(tab, tabfinal);
                afficheplateaufinal(tab, tabfinal);
                //affichageTableau(tab, tabfinal);
                //tourjoueur(&numjoueur, &echap, &nbJoueurs);
                affiche_case_en_plus(&carterestante);
                nombreJoueurs(&nbJoueurs,&nbCartesJoueurs);
                distributionCartes(&nbJoueurs, &nbCartesJoueurs,cartesJoueurs);
                //afficherTerrain4(&tab[LARGEUR][LARGEUR]);
                //finJeu(&ligne, &colonne, &tab[7][7], &n);
                printf("\n");
                //printf("%d", carterestante);



                //getchar(); // attend que l'utilisateur appuie sur une touche
                //fgetc(stdin);
                partie=0;
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
                partie=0;


                break;
            case '3':
                printf("Lancement de la partie sauvegardee...\n");
                //tab[LARGEUR][LARGEUR]=sauvegarde1tab[LARGEUR][LARGEUR];
                numjoueur=sauvegardetourjoueur;
                convertab(sauvegarde1tab);
                coordonne(tabfinal, &x, &y, sauvegarde1tab);
                afficheplateaufinal(sauvegarde1tab, tabfinal);
                partie=0;
                break;
            case '4':
                printf("Regles du jeu de societe Labyrinthe:\n\n");
                printf("Le but du jeu est d'etre le premier a trouver la sortie du labyrinthe avec son pion.\n");
                printf("Pour se deplacer, les joueurs tirent un de et avancent leur pion du nombre de cases correspondant.\n");
                printf("Si un joueur tombe sur une case avec un objet, il peut le prendre et le garder jusqu'a ce qu'il en ait besoin ou decider de le donner a un autre joueur.\n");
                printf("Les objets peuvent etre utilises pour ouvrir des portes ou des passages secrets, ou pour deplacer des obstacles dans le labyrinthe.\n");
                printf("Le premier joueur a sortir du labyrinthe est declare vainqueur.\n");
                partie=0;
                break;
            default:
                partie=0;
                choix=-1;

        }


    }


    return 0;
}
