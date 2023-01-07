// main.c
#include "sprog.h"

int main() {   //programme principal
    int tab[LARGEUR][LARGEUR];
    char buffer[BUFFER_SIZE];
    int x=0,y=0,nbJoueurs=0;
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
    int memoricase[4];
    int fin=0;
    int chargePartie=0;

    int cartejoueurtab[4]={0,0,0,0};
    int tourJoueur, nbTours=1, verifTours=0;
    int ligne_ou_colonne, numero_ligne_colonne, direction;

    int cartejoueur1=0;
    int cartejoueur2=0;
    int cartejoueur3=0;
    int cartejoueur4=0;
    Sauvegarde state;
    int posxy[4][2]={0,0,6,0,0,6,6,6};


    color(15,0);
    printf("\n");
    afficherTitre();
    ligne();
    color(13,0);

    printf("Menu :\n");
    printf("1. Nouvelle partie\n2. Sauvegarder la partie en cours\n3. Charger une partie sauvegardee\n4. Afficher les regles / credits\n0. Quitter le jeu\n");
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
            printf("Sortie du labyrinthe... A bientot dans le royaume des illusions jeune aventurier !\n");
            return 0;
        }
        if (choix0==1) {
            if (chargePartie==0){
                nouvellePartie(tab, buffer, &x, &y, &nbJoueurs, pionsJoueurs, nomJoueurs, choix, &choix0, &nbCartesJoueurs, cartesJoueurs, tabfinal, &partie, sauvegarde1tab, &sauvegardetourjoueur, &numjoueur, &echap, &carterestante, &test_tresor, memoricase, &fin, cartejoueurtab, &tourJoueur, &nbTours, &verifTours, &ligne_ou_colonne, &numero_ligne_colonne, &direction, &cartejoueur1, &cartejoueur2, &cartejoueur3, &cartejoueur4, posxy);
                //remise des valeurs à 0 si l'utilisateur ne charge pas une partie
            }
            system("cls");
            afficherTitre();
            ligne();
            //couleur noir
            color(15,0);




            //affichageTableau(tab, tabfinal);                 //affichage
            //afficheplateauprog(tab, tabfinal);
           //afficheplateaubinaire(tab, tabfinal);


            //tourjoueur(&numjoueur, &echap, &nbJoueurs);

            //joueur.c ligne 6
            nombreJoueurs(&nbJoueurs, &nbCartesJoueurs);
            printf("%d aventuriers se disputerons le titre de roi du labyrinthe !\n",nbJoueurs);
            //joueur.c ligne 23
            CreationNomJoueurs(&nbJoueurs, nomJoueurs);

            system("cls");
            afficherTitre();
            ligne();
            printf("Les noms des aventuriers sont :\n"); // Affiche les noms des joueurs
            for (int i = 0; i < nbJoueurs; i++) {
                printf("- %s\n", nomJoueurs[i]);
            }
            srand(time(NULL));
            tourJoueur=rand() % nbJoueurs;
            //joueur.c ligne 31
            distributionPions(&nbJoueurs,nomJoueurs,pionsJoueurs); // il y a : system("cls");afficherTitre();ligne();
            //joueur.c ligne 104
            distributionCartes(&nbJoueurs, &nbCartesJoueurs, nomJoueurs, cartesJoueurs);
            //joueur.c ligne 89
            debutPartie(&nbJoueurs, &tourJoueur, nomJoueurs, pionsJoueurs, &nbTours);// il y a : system("cls");afficherTitre();ligne();

            //initialisation jeu plateau.c
            initialisationTableau(tab);
            init_case_en_plus(tab, &carterestante, &test_tresor);
            convertab(tab, &test_tresor);
            coordonne(tabfinal, &x, &y, tab, posxy, pionsJoueurs, &tourJoueur);

            memoricase[0]=tabfinal[(posxy[0][0])*3+2][(posxy[0][1])*3+2];
            tabfinal[(posxy[0][0])*3+2][(posxy[0][1])*3+2] = 2; //pionsJoueurs[0]+1

            memoricase[1]=tabfinal[(posxy[1][0])*3+2][(posxy[1][1])*3+2];
            tabfinal[(posxy[1][0])*3+2][(posxy[1][1])*3+2] = 3;

            memoricase[2]=tabfinal[(posxy[2][0])*3+2][(posxy[2][1])*3+2];
            tabfinal[(posxy[2][0])*3+2][(posxy[2][1])*3+2] = 4;

            memoricase[3]=tabfinal[(posxy[3][0])*3+2][(posxy[3][1])*3+2];
            tabfinal[(posxy[3][0])*3+2][(posxy[3][1])*3+2]= 5;

            while(fin==0){
                if (verifTours==nbJoueurs){
                    nbTours+=1;
                    verifTours=0;
                }
                else{
                    verifTours+=1;
                }



                //joueur.c ligne 134
                afficheCarteJoueur(&tourJoueur,&nbCartesJoueurs, nomJoueurs,cartesJoueurs,cartejoueurtab);//caractere(&caracteres);
                //deplacement.c ligne 130
                selection_ligne_colonne(tab,tabfinal, &ligne_ou_colonne, &numero_ligne_colonne,&direction, &carterestante, nomJoueurs, &tourJoueur, &nbCartesJoueurs, cartesJoueurs, cartejoueurtab, &nbTours);//afficheplateaufinal(tab, tabfinal);affiche_case_en_plus(&*carterestante);system("cls");afficherTitre();ligne();
                //deplacement.c ligne 279

                deplacement_de_tuile(tab, tabfinal, &carterestante, &ligne_ou_colonne, &numero_ligne_colonne,&direction, posxy, pionsJoueurs, &tourJoueur, &nbTours);//afficheplateaufinal(tab, tabfinal);affiche_case_en_plus(&*carterestante);system("cls");afficherTitre();ligne();
                //plateau.c ligne 62

                convertab(tab, &test_tresor);
                //plateau.c ligne 89
                coordonne(tabfinal, &x, &y, tab, posxy, pionsJoueurs, &tourJoueur);
                afficheCarteJoueur(&tourJoueur,&nbCartesJoueurs, nomJoueurs,cartesJoueurs,cartejoueurtab);
                //deplacement.c ligne 17   //afficheplateaufinal(tab, tabfinal);affiche_case_en_plus(&*carterestante);
                deplacementJoueur(tabfinal, tab, nomJoueurs, pionsJoueurs, &tourJoueur,memoricase,&carterestante,posxy,&echap, cartejoueurtab,cartesJoueurs,&nbCartesJoueurs, &fin, &nbTours, &nbJoueurs);                 //deplacement joueur
                    if (fin==0){
                        afficheCarteJoueur(&tourJoueur,&nbCartesJoueurs, nomJoueurs,cartesJoueurs,cartejoueurtab);

                        //affiche_case_en_plus(&carterestante);
                        //finJeu(&ligne, &colonne, &tab[7][7], &n);
                        printf("\n");
                        tourJoueur+=1;
                        if (tourJoueur==nbJoueurs){
                            tourJoueur=0;
                        }
                        //printf("%d", carterestante);
                        //getchar(); // attend que l'utilisateur appuie sur une touche
                        //fgetc(stdin);
                    }
                    else{
                        system("cls");
                        afficherTitre();
                        ligne();
                        color(15,0);
                        printf("Menu :\n");
                        printf("1. Nouvelle partie\n2. Sauvegarder la partie en cours\n3. Charger une partie sauvegardee\n4. Afficher les regles / credits\n0. Quitter le jeu\n");
                        ligne();
                        color(13,0);
                    }
            }
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
            coordonne(tabfinal, &x, &y, sauvegarde1tab, posxy, pionsJoueurs, &tourJoueur);
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
