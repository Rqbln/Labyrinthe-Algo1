// main.c
#include "sprog.h"

int main() {   //programme principal
    int tab[LARGEUR][LARGEUR];
    char buffer[BUFFER_SIZE];
    int x,y,nbJoueurs;
    int pionsJoueurs[4];
    char nomJoueurs[4][LONGUEUR_NOM];
    char choix[BUFFER_SIZE];
    int choix0;
    int nbCartesJoueurs;
    int cartesJoueurs[CARTES][CARTES];
    int tabfinal[LARGEUR_FINALE][LARGEUR_FINALE];
    int partie=0;
    int sauvegarde1tab[LARGEUR][LARGEUR];
    int sauvegardetourjoueur;
    int numjoueur=1;
    int echap=0;
    int carterestante;
    int test_tresor = 0;
    int memoricase[4][1];

    int cartejoueurtab[4]={0,0,0,0};
    int tourJoueur, nbTours=0;
    int ligne_ou_colonne, numero_ligne_colonne, direction;

    Sauvegarde state;


    color(15,0);
    printf("\n");
    afficherTitre();
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
            system("cls");
            afficherTitre();
            ligne();
            color(15,0);
            nbTours+=1;
            initialisationTableau(tab);                        //initialisation
            init_case_en_plus(tab, &carterestante, &test_tresor);
            convertab(tab, &test_tresor);
            coordonne(tabfinal, &x, &y, tab);

            //affichageTableau(tab, tabfinal);                 //affichage
            //afficheplateauprog(tab, tabfinal);
            //afficheplateaubinaire(tab, tabfinal);


            //tourjoueur(&numjoueur, &echap, &nbJoueurs);

            nombreJoueurs(&nbJoueurs, &nbCartesJoueurs);
            printf("%d joueurs seront dans cette partie.\n",nbJoueurs);
            CreationNomJoueurs(&nbJoueurs, nomJoueurs);

            system("cls");
            afficherTitre();
            ligne();
            printf("Les noms des joueurs sont :\n"); // Affiche les noms des joueurs
            for (int i = 0; i < nbJoueurs; i++) {
                printf("- %s\n", nomJoueurs[i]);
            }
            srand(time(NULL));
            distributionPions(&nbJoueurs,nomJoueurs,pionsJoueurs);
            distributionCartes(&nbJoueurs, &nbCartesJoueurs, nomJoueurs, cartesJoueurs);

            save_game(&state);
            debutPartie(&nbJoueurs, &tourJoueur, nomJoueurs, pionsJoueurs, &nbTours);
            afficheCarteJoueur(&tourJoueur,&nbCartesJoueurs, nomJoueurs,cartesJoueurs,cartejoueurtab);
            selection_ligne_colonne(tab,tabfinal, &ligne_ou_colonne, &numero_ligne_colonne,&direction, &carterestante);
            deplacement_de_tuile(tab, tabfinal, &carterestante, &ligne_ou_colonne, &numero_ligne_colonne,&direction);
            convertab(tab, &test_tresor);
            coordonne(tabfinal, &x, &y, tab);
            deplacementJoueur(tabfinal, tab, nomJoueurs, pionsJoueurs, &tourJoueur,memoricase,&carterestante);                 //deplacement joueur
            selection_ligne_colonne(tab,tabfinal, &ligne_ou_colonne, &numero_ligne_colonne,&direction, &carterestante);
            deplacement_de_tuile(tab, tabfinal, &carterestante, &ligne_ou_colonne, &numero_ligne_colonne,&direction);
            convertab(tab, &test_tresor);
            coordonne(tabfinal, &x, &y, tab);
            deplacementJoueur(tabfinal, tab, nomJoueurs, pionsJoueurs, &tourJoueur,memoricase,&carterestante);                 //deplacement joueur
            selection_ligne_colonne(tab,tabfinal, &ligne_ou_colonne, &numero_ligne_colonne,&direction, &carterestante);
            deplacement_de_tuile(tab, tabfinal, &carterestante, &ligne_ou_colonne, &numero_ligne_colonne,&direction);
            convertab(tab, &test_tresor);
            coordonne(tabfinal, &x, &y, tab);
            //affiche_case_en_plus(&carterestante);
            //finJeu(&ligne, &colonne, &tab[7][7], &n);
            printf("\n");
            //printf("%d", carterestante);
            //getchar(); // attend que l'utilisateur appuie sur une touche
            //fgetc(stdin);
            partie = 0;
        }
        if (choix0==2) {
            color(15,0);
            save_game(&state);

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
            afficherCredits();
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
