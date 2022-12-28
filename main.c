#include "sprog.h"
#include <stdio.h>
#include <time.h>
int main() {   //programme principal
    int tab[LARGEUR][LARGEUR];
    char buffer[BUFFER_SIZE];
    int x,y,nbJoueurs;
    char nomJoueurs[4][LONGUEUR_NOM];
    char choix[BUFFER_SIZE];
    int choix0;
    int nbCartesJoueurs;
    int cartesJoueurs[CARTES][CARTES];
    int tabfinal[21][21];
    int partie=0;
    int sauvegarde1tab[LARGEUR][LARGEUR];
    int sauvegardetourjoueur;
    int numjoueur=1;
    int echap=0;
    int carterestante;
    int test_tresor = 0;

    int cartejoueur1=0;
    int cartejoueur2=0;
    int cartejoueur3=0;
    int cartejoueur4=0;
    int tour_joueur;

    //Positions initiale des joueurs
    int posxy1[2]={0,0};
    int posxy2[2]={0,7};
    int posxy3[2]={7,0};
    int posxy4[2]={7,7};

    color(15,0);
    printf("\n");
    afficherTitre();
    color(13,0);
    ligne();
    color(13,0);

    printf("Menu :");
    printf("\n1. Nouvelle partie\n2. Sauvegarder la partie en cours\n3. Charger une partie sauvegardee\n4. Afficher les regles / credits\n0. Quitter le jeu\n");
    color(13,0);
    ligne();
    while (partie==0){
        color(13,0);
        printf("Choix :");
        fflush(stdin);
        fgets(choix,BUFFER_SIZE,stdin);
        while (sscanf(choix, "%d", &choix0) != 1 || choix0 < 0 || choix0 > 4) {
            printf("Choix :");
            fflush(stdin);
            fgets(choix, BUFFER_SIZE, stdin);
        }

        if (choix0==0) {
            printf("Deconnexion... A bientot !\n");
            return 0;
        }
        if (choix0==1) {
            color(15,0);
            //do{
            //    test_tresor=0;
                initialisationTableau(tab);
                init_case_en_plus(tab, &carterestante, &test_tresor);
                convertab(tab, &test_tresor);
            //    printf("%d",test_tresor);
            //}while(test_tresor == 24);

            coordonne(tabfinal, &x, &y, tab);
            afficheplateauprog(tab, tabfinal);
            afficheplateaubinaire(tab, tabfinal);
            afficheplateaufinal(tab, tabfinal);
            //affichageTableau(tab, tabfinal);
            //tourjoueur(&numjoueur, &echap, &nbJoueurs);
            affiche_case_en_plus(&carterestante);
            nombreJoueurs(&nbJoueurs, &nbCartesJoueurs);
            CreationNomJoueurs(&nbJoueurs, nomJoueurs);
            srand(time(NULL));
            tour_joueur = rand()%nbJoueurs;
            distributionCartes(&nbJoueurs, &nbCartesJoueurs, nomJoueurs, cartesJoueurs);
            afficheCarteJoueur(&nbJoueurs,&nbCartesJoueurs, nomJoueurs,cartesJoueurs);
            afficheCarteJoueur1(&tour_joueur,&nbCartesJoueurs, nomJoueurs,cartesJoueurs,&cartejoueur1,&cartejoueur2,&cartejoueur3,&cartejoueur4);

            //finJeu(&ligne, &colonne, &tab[7][7], &n);
            printf("\n");
            //printf("%d", carterestante);
            //getchar(); // attend que l'utilisateur appuie sur une touche
            //fgetc(stdin);
            partie = 0;
        }
        if (choix0==2) {
            color(15,0);
            printf("Sauvegarde de la partie en cours...\n");
            for (int i = 0; i < LARGEUR; ++i) {
                for (int j = 0; j < LARGEUR; ++j) {
                    sauvegarde1tab[i][j] = tab[i][j];
                }
            }
            sauvegardetourjoueur = numjoueur;
            printf("Sauvegarde terminee\n");
            partie = 0;
        }
        if (choix0==3) {
            color(15,0);
            printf("Lancement de la partie sauvegardee...\n");
            //tab[LARGEUR][LARGEUR]=sauvegarde1tab[LARGEUR][LARGEUR];
            numjoueur = sauvegardetourjoueur;
            convertab(sauvegarde1tab, &test_tresor);
            coordonne(tabfinal, &x, &y, sauvegarde1tab);
            afficheplateaufinal(sauvegarde1tab, tabfinal);
            partie = 0;
        }
        if (choix0==4) {
            afficherRegles();
            partie = 0;
        }
        else {
            color(15,0);
            partie=0;
            choix0=-1;
        }
    }
    return 0;
}
