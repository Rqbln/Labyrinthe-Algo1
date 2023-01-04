// deplacement.c
// Created by bapti on 27/12/2022.
//
#include "sprog.h"

#include <time.h>
#include <fcntl.h>
#include <io.h>
// Ce programme crée un tableau de caractères représentant un plateau de jeu
// et déplace un pion sur ce plateau en fonction des entrées de l'utilisateur.
// Les flèches du clavier permettent de déplacer le pion et la touche 'q' permet de quitter le programme.





void deplacementJoueur(int tabfinal[LARGEUR_FINALE][LARGEUR_FINALE], int tab[LARGEUR][LARGEUR], char nomJoueurs[4][LONGUEUR_NOM], int pionsJoueurs[4], int *tourJoueur, int memoricase[4], int *carterestante,int posxy[4][2], int* echap){
    // Déclaration du tableau et du pion
    // Le tableau est initialisé à '-' pour chaque case
    // Le pion est placé en position (0, 0) au début du programme
    int pion_row, pion_col;
    int stop=0;

        switch (pionsJoueurs[*tourJoueur]) {
            case 1:
                pion_row = pion_row1;
                pion_col = pion_col1;
                break;
            case 2:
                pion_row = pion_row2;
                pion_col = pion_col2;
                break;
            case 3:
                pion_row = pion_row3;
                pion_col = pion_col3;
                break;
            case 4:
                pion_row = pion_row4;
                pion_col = pion_col4;
                break;
        }

//innitialisation des cases de depart

        memoricase[0]=tabfinal[(posxy[0][0])*3+2][(posxy[0][1])*3+2];
        tabfinal[(posxy[0][0])*3+2][(posxy[0][1])*3+2] = pionsJoueurs[0]+1;

        memoricase[1]=tabfinal[(posxy[1][0])*3+2][(posxy[1][1])*3+2];
        tabfinal[(posxy[1][0])*3+2][(posxy[1][1])*3+2] = pionsJoueurs[1]+1;

        memoricase[2]=tabfinal[(posxy[2][0])*3+2][(posxy[2][1])*3+2];
        tabfinal[(posxy[2][0])*3+2][(posxy[2][1])*3+2] = pionsJoueurs[2]+1;

        memoricase[3]=tabfinal[(posxy[3][0])*3+2][(posxy[3][1])*3+2];
        tabfinal[(posxy[3][0])*3+2][(posxy[3][1])*3+2]= pionsJoueurs[3]+1;
        //permet d enregistrer le motif des cases de depart
        *echap=1;


    char demarrage;
    afficheplateaufinal(tab, tabfinal);
    printf("Le tableau a ete modifie.\n%s, appuyez sur 'Entree' pour deplacer votre pion\n",nomJoueurs[*tourJoueur]);
    do {
        demarrage=getchar();
    }
    while (demarrage!='\n');

    // Boucle principale de déplacement du pion
    // Le programme tourne en boucle jusqu'à ce que l'utilisateur appuie sur la touche 'q'
    while (stop==0){
        system("cls");
        afficherTitre();
        ligne();
        // Affichage du tableau et du pion
        afficheplateaufinal(tab, tabfinal);
        affiche_case_en_plus(&*carterestante);
        printf("\n");
        printf("Deplacez vous avec les touches 'z', 'q', 's', 'd' du clavier.\nAppuyez sur 'Entree' Pour arreter de deplacer le pion.");
        printf("\n");
        // Lecture de l'entrée utilisateur
        int c = getch();
        if (c == 'z' || c == 'q' || c == 's' || c == 'd' || c == 13) // Touches 'z', 'q', 's', 'd' et 'Entree'
        {
            if (c == 'z') // touche 'z'
            {
// Déplacement du pion vers le haut si possible
                if (pion_row > 0 + 3 && tabfinal[pion_row-1][pion_col] == 1 && tabfinal[pion_row-2][pion_col] == 1)
                {
                    tabfinal[pion_row][pion_col] = memoricase[pionsJoueurs[*tourJoueur]-1];
                    pion_row-=3;
                    posxy[*tourJoueur][0]-=1;
                    memoricase[pionsJoueurs[*tourJoueur]-1]=tabfinal[pion_row][pion_col];
                    tabfinal[pion_row][pion_col] = pionsJoueurs[*tourJoueur]+1;
                }
            }
            else if (c == 's') // touches 's'
            {
// Déplacement du pion vers le bas si possible
                if (pion_row < 21 - 3 && tabfinal[pion_row+1][pion_col] == 1 && tabfinal[pion_row+2][pion_col] == 1)
                {
                    tabfinal[pion_row][pion_col] = memoricase[pionsJoueurs[*tourJoueur]-1];
                    pion_row+=3;
                    posxy[*tourJoueur][0]+=1;
                    memoricase[pionsJoueurs[*tourJoueur]-1]=tabfinal[pion_row][pion_col];
                    tabfinal[pion_row][pion_col] = pionsJoueurs[*tourJoueur]+1;
                }
            }
            else if (c == 'q') // touche 'q'
            {
// Déplacement du pion vers la gauche si possible
                if (pion_col > 0 + 3 && tabfinal[pion_row][pion_col-1] == 1 && tabfinal[pion_row][pion_col-2] == 1)
                {
                    tabfinal[pion_row][pion_col] = memoricase[pionsJoueurs[*tourJoueur]-1];
                    pion_col-=3;
                    posxy[*tourJoueur][1]-=1;
                    memoricase[pionsJoueurs[*tourJoueur]-1]=tabfinal[pion_row][pion_col];
                    tabfinal[pion_row][pion_col] = pionsJoueurs[*tourJoueur]+1;
                }
            }
            else if (c == 'd') // touche 'd'
            {
// Déplacement du pion vers la droite si possible
                if (pion_col < 21 - 3 && tabfinal[pion_row][pion_col+1] == 1 && tabfinal[pion_row][pion_col+2] == 1)
                {
                    tabfinal[pion_row][pion_col] = memoricase[pionsJoueurs[*tourJoueur]-1];
                    pion_col+=3;
                    posxy[*tourJoueur][1]+=1;
                    memoricase[pionsJoueurs[*tourJoueur]-1]=tabfinal[pion_row][pion_col];
                    tabfinal[pion_row][pion_col] = pionsJoueurs[*tourJoueur]+1;
                }
            }
            else { // Touche entrée
                stop=1;
            }
        }
    }
}
void selection_ligne_colonne(int tab[LARGEUR][LARGEUR],int tabfinal[LARGEUR_FINALE][LARGEUR_FINALE],int *ligne_ou_colonne, int *numero_ligne_colonne,int *direction, int *carterestante){
    int i,j;
    int select=0;
    while (1) {
        // Affichage du tableau et du pion
        system("cls");
        afficherTitre();
        ligne();
        afficheplateaufinal(tab, tabfinal);
        affiche_case_en_plus(&*carterestante);
        printf("\nAppuyez sur :\n- Fleche Haut\n- Fleche Bas\npour deplacer la tuile.\nAppuyez deux fois sur Entree pour confirmer votre selection.");


        // Lecture de l'entrée utilisateur
        int c = getch();
        if (c == 0 || c == 0xE0 || c == 13) {// Flèche du clavier
            switch (select) {
                case 1:
                    tabfinal[0][5]=9;
                    break;
                case 2:
                    tabfinal[0][11]=9;
                    break;
                case 3:
                    tabfinal[0][17]=9;
                    break;
                case 4:
                    tabfinal[5][22]=9;
                    break;
                case 5:
                    tabfinal[11][22]=9;
                    break;
                case 6:
                    tabfinal[17][22]=9;
                    break;
                case 7:
                    tabfinal[22][17]=9;
                    break;
                case 8:
                    tabfinal[22][11]=9;
                    break;
                case 9:
                    tabfinal[22][5]=9;
                    break;
                case 10:
                    tabfinal[17][0]=9;
                    break;
                case 11:
                    tabfinal[11][0]=9;
                    break;
                case 12:
                    tabfinal[5][0]=9;
                    break;

            }
            c = getch();
            if (c == 72) { // Flèche haut
                select+=1;
                if (select>12) {
                    select=1;
                }
            }
            else if (c == 80) { // Flèche bas
                select-=1;
                if (select<1) {
                    select=12;
                }
            }
            switch (select) {
                case 1:
                    tabfinal[0][5] = 8;
                    i = 0;
                    j = 5;
                    break;
                case 2:
                    tabfinal[0][11] = 8;
                    i = 0;
                    j = 11;
                    break;
                case 3:
                    tabfinal[0][17] = 8;
                    i = 0;
                    j = 17;
                    break;
                case 4:
                    tabfinal[5][22] = 8;
                    i = 5;
                    j = 22;
                    break;
                case 5:
                    tabfinal[11][22] = 8;
                    i = 11;
                    j = 22;
                    break;
                case 6:
                    tabfinal[17][22] = 8;
                    i = 17;
                    j = 22;
                    break;
                case 7:
                    tabfinal[22][17] = 8;
                    i = 22;
                    j = 17;
                    break;
                case 8:
                    tabfinal[22][11] = 8;
                    i = 22;
                    j = 11;
                    break;
                case 9:
                    tabfinal[22][5] = 8;
                    i = 22;
                    j = 5;
                    break;
                case 10:
                    tabfinal[17][0] = 8;
                    i = 17;
                    j = 0;
                    break;
                case 11:
                    tabfinal[11][0] = 8;
                    i = 11;
                    j = 0;
                    break;
                case 12:
                    tabfinal[5][0] = 8;
                    i = 5;
                    j = 0;
                    break;
            }
            if (c == 13) { // Entrée
                if (select==4 || select==5 || select==6 || select==10 || select==11 || select==12){
                    *ligne_ou_colonne=0;
                    *numero_ligne_colonne=(i-2)/3;
                    *direction=j;
                    break;
                }
                if (select==1 || select==2 || select==3 || select==7 || select==8 || select==9){
                    *ligne_ou_colonne=1;
                    *numero_ligne_colonne=(j-2)/3;
                    *direction=i;
                    break;
                }
            }
            system("cls");
        }
    }
}
void deplacement_de_tuile(int tab[LARGEUR][LARGEUR], int tabfinal[LARGEUR_FINALE][LARGEUR_FINALE],int *carterestante,int *ligne_ou_colonne, int *numero_ligne_colonne,int *direction, int posxy[4][2]) {
    int i, temp;
    afficheplateaufinal(tab, tabfinal);
    affiche_case_en_plus(&*carterestante);
    for (int k = 0; k < 4; ++k) {
        for (int l = 0; l < 2; ++l) {
            if(posxy[k][l]==1 || posxy[k][l] == 3 || posxy[k][l] == 5){
                tabfinal[(posxy[k][0])*3+2][(posxy[k][1])*3+2]=0;
                if (l==0){
                    switch (*direction) {
                        case 22:
                            posxy[k][l]-=1;
                            break;
                        case 0:
                            posxy[k][l]+=1;
                            break;
                    }
                }
                if (l==1){
                    switch (*direction) {

                        case 22:
                            posxy[k][l]-=1;
                            break;
                        case 0:
                            posxy[k][l]+=1;
                            break;
                    }
                }
                tabfinal[(posxy[k][0])*3+2][(posxy[k][1])*3+2]=3;
            }
        }

    }
    switch (*ligne_ou_colonne) {
        case 0:
            if (*numero_ligne_colonne == 1 || *numero_ligne_colonne == 3 || *numero_ligne_colonne == 5) {
                switch (*direction) {
                    case 22:
                        temp = tab[*numero_ligne_colonne][0];
                        for (i = 0; i < LARGEUR - 1; i++) {
                            tab[*numero_ligne_colonne][i] = tab[*numero_ligne_colonne][i + 1];
                        }
                        tab[*numero_ligne_colonne][LARGEUR - 1] = *carterestante;
                        *carterestante = temp;
                        break;

                    case 0:
                        temp = tab[*numero_ligne_colonne][LARGEUR -
                                                          1]; // variable *carterestanteoraire pour stocker la dernière valeur de la colonne
                        // déplacer chaque élément vers la droite
                        for (i = LARGEUR - 1; i > 0; i--) {
                            tab[*numero_ligne_colonne][i] = tab[*numero_ligne_colonne][i - 1];
                        }

                        tab[*numero_ligne_colonne][0] = *carterestante; // assigner la valeur temporaire à la première case
                        *carterestante = temp;
                        break;
                }
            }

            break;

        case 1:
            if (*numero_ligne_colonne == 1 || *numero_ligne_colonne == 3 || *numero_ligne_colonne == 5) {
                switch (*direction) {

                    case 22:
                        temp = tab[0][*numero_ligne_colonne];
                        for (i = 0; i < LARGEUR - 1; i++) {
                            tab[i][*numero_ligne_colonne] = tab[i + 1][*numero_ligne_colonne];
                        }
                        tab[LARGEUR - 1][*numero_ligne_colonne] = *carterestante;
                        *carterestante = temp;
                        break;

                    case 0:
                        temp = tab[LARGEUR -1][*numero_ligne_colonne]; // variable *carterestanteoraire pour stocker la dernière valeur de la colonne
                        // déplacer chaque élément vers la droite
                        for (int i = LARGEUR - 1; i > 0; i--) {
                            tab[i][*numero_ligne_colonne] = tab[i - 1][*numero_ligne_colonne];
                        }
                        tab[0][*numero_ligne_colonne] = *carterestante; // assigner la valeur temporaire à la première case
                        *carterestante = temp;
                        break;
                }
            }

            break;
    }
    system("cls");
    afficherTitre();
    ligne();
}