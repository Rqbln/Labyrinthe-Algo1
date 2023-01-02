#include "sprog.h"

// Déclare les variables globales pour la couleur de fond et de texte
static int __BACKGROUND = BLACK;
static int __FOREGROUND = WHITE;

// Change la couleur du texte de la console

void color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}


void text_color(int color) {
    __FOREGROUND = color;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, __FOREGROUND + (__BACKGROUND << 4));
}

// Change la couleur de fond de la console
void bg_color(int color) {
    __BACKGROUND = color;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, __FOREGROUND + (__BACKGROUND << 4));
}
void affichageTableau(int tab[LARGEUR][LARGEUR], int tabfinal[LARGEUR_FINALE][LARGEUR_FINALE]) {                   //sous programme pour les afficher le tableau
    //int tab[10][10];
    for (int i = 0; i < (LARGEUR); i++) {
        for (int j = 0; j < (LARGEUR); j++) {
            printf("%d ", tab[i][j]); //affichage des valeur
        }
        printf("\n");

    }
    printf("\n");
    printf("\n");
    /* for (int i = 0; i < (LARGEUR); i++) {
         for (int j = 0; j < (LARGEUR); j++) {
             printf("%c ", tableau[i][j]); //affichage des valeur
         }
         printf("\n");
     }*/
    for (int i = 0; i < (21); i++) {
        for (int j = 0; j < (21); j++) {
            printf("%d ", tabfinal[i][j]); //affichage des valeur
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    for (int i = 0; i < (21); i++) {
        for (int j = 0; j < (21); j++) {
            if (tabfinal[i][j]==0) {
                _setmode(_fileno(stdout), _O_U16TEXT);
                wprintf(L"\x2588\x2588"); //affichage des valeur
            }
            if (tabfinal[i][j]==1) {
                _setmode(_fileno(stdout), _O_U16TEXT);
                wprintf(L"\x00A0\x00A0"); //affichage des valeur
            }
            if (tabfinal[i][j]==8) {
                _setmode(_fileno(stdout), _O_U16TEXT);
                wprintf(L"\x0054\x0052"); //affichage des valeur
            }
        }
        _setmode(_fileno(stdout), _O_U16TEXT);
        wprintf(L"\n");
    }

    _setmode(_fileno(stdout), _O_TEXT);
}
void selection_ligne_colonne1(int tab[LARGEUR][LARGEUR],int tabfinal[LARGEUR_FINALE][LARGEUR_FINALE]){
    // Déclaration du tableau et du pion
    int pion_row = 0, pion_col = 0;
    int verif=1;
    // Initialisation du tableau et du pion
    tabfinal[pion_row][pion_col] = 8;

    // Boucle principale de déplacement du pion
    while (verif==1) {
        // Affichage du tableau et du pion
        afficheplateaufinal(tab, tabfinal);
        printf("\n");


        // Lecture de l'entrée utilisateur
        int c = getch();
        system("cls");
        if (c == 0 || c == 0xE0 || c==13) {// Flèche du clavier
            c = getch();
            if (c == 72) // Flèche haut
            {
                if (pion_row > 0 && (pion_col == 0 || pion_col == LARGEUR_FINALE - 1)) {
                    tabfinal[pion_row][pion_col] = 9;
                    pion_row--;
                    // Vérifier si le personnage arrive sur un coin et sauter par-dessus si cest le cas
                    if ((pion_row == 0 || pion_row == LARGEUR_FINALE - 1) &&
                        (pion_col == 0 || pion_col == LARGEUR_FINALE - 1)) {
                        pion_row = (pion_row == 0) ? LARGEUR_FINALE - 1 : 0;
                        pion_col = (pion_col == 0) ? LARGEUR_FINALE - 1 : 0;
                    }
                    tabfinal[pion_row][pion_col] = 8;
                }
            } else if (c == 80) // Flèche bas
            {
                if (pion_row < LARGEUR_FINALE - 1 && (pion_col == 0 || pion_col == LARGEUR_FINALE - 1)) {
                    tabfinal[pion_row][pion_col] = 9;
                    pion_row++;
// Vérifier si le personnage arrive sur un coin et sauter par-dessus si c'est le cas
                    if ((pion_row == 0 || pion_row == LARGEUR_FINALE - 1) &&
                        (pion_col == 0 || pion_col == LARGEUR_FINALE - 1)) {
                        pion_row = (pion_row == 0) ? LARGEUR_FINALE - 1 : 0;
                        pion_col = (pion_col == 0) ? LARGEUR_FINALE - 1 : 0;
                    }
                    tabfinal[pion_row][pion_col] = 8;
                }
            } else if (c == 75) // Flèche gauche
            {
                if (pion_col > 0 && (pion_row == 0 || pion_row == LARGEUR_FINALE - 1)) {
                    tabfinal[pion_row][pion_col] = 9;
                    pion_col--;
// Vérifier si le personnage arrive sur un coin et sauter par-dessus si c'est le cas
                    if ((pion_row == 0 || pion_row == LARGEUR_FINALE - 1) &&
                        (pion_col == 0 || pion_col == LARGEUR_FINALE - 1)) {
                        pion_row = (pion_row == 0) ? LARGEUR_FINALE - 1 : 0;
                        pion_col = (pion_col == 0) ? LARGEUR_FINALE - 1 : 0;
                    }
                    tabfinal[pion_row][pion_col] = 8;
                }
            }
            else if (c == 77) // Flèche droite
            {
                if (pion_col < LARGEUR_FINALE - 1 && (pion_row == 0 || pion_row == LARGEUR_FINALE - 1)) {
                    tabfinal[pion_row][pion_col] = 9;
                    pion_col++;
// Vérifier si le personnage arrive sur un coin et sauter par-dessus si c'est le cas
                    if ((pion_row == 0 || pion_row == LARGEUR_FINALE - 1) && (pion_col == 0 || pion_col == LARGEUR_FINALE - 1)) {
                        pion_row = (pion_row == 0) ? LARGEUR_FINALE - 1 : 0;
                        pion_col = (pion_col == 0) ? LARGEUR_FINALE - 1 : 0;
                    }
                    tabfinal[pion_row][pion_col] = 8;
                }
            }
            if (c==13){
                verif=0;
            }
        }
    }
}
void deplacementJoueur(int tab[LARGEUR][LARGEUR],int numjoueur,int *posxy[2])
// il faudrait rajouter le posxy des 4 joueurs dans l'affichage du tableau
{
    int input,exit;
    while (exit ==0) {
        printf("Deplacement du personnage (Joueur %d) :\n 1.Vers le haut\n2.Vers la gauche\n3.Vers la droite\n4.Vers le bas\n0.Terminer votre tour",numjoueur);
        scanf("%d", &input);
        switch (input) {
            //Ajouter les cases trésors aussi !!
            case 1:
                // "Monte" la position du joueur de 1 si la case supérieure le permet
                if (*posxy[0]>0 && (tab[*posxy[0]-1][*posxy[1]] == 1 || tab[*posxy[0]-1][*posxy[1]] == 2 || tab[*posxy[0]-1][*posxy[1]] == 6 || tab[*posxy[0]-1][*posxy[1]] ==50  || tab[*posxy[0]-1][*posxy[1]] ==  7|| tab[*posxy[0]-1][*posxy[1]] ==  10|| tab[*posxy[0]-1][*posxy[1]] ==  11|| tab[*posxy[0]-1][*posxy[1]] ==  51|| tab[*posxy[0]-1][*posxy[1]] ==  4|| tab[*posxy[0]-1][*posxy[1]] == 5 || tab[*posxy[0]-1][*posxy[1]] ==  8|| tab[*posxy[0]-1][*posxy[1]] == 53 || tab[*posxy[0]-1][*posxy[1]] == 0 || tab[*posxy[0]-1][*posxy[1]] == 61 || tab[*posxy[0]-1][*posxy[1]] == 71 || tab[*posxy[0]-1][*posxy[1]] == 3 || tab[*posxy[0]-1][*posxy[1]] ==  62|| tab[*posxy[0]-1][*posxy[1]] ==  72|| tab[*posxy[0]-1][*posxy[1]] ==  80))
                {*posxy[0]=-1;}
                else;
            case 2:
                if (*posxy[1]>0 && (tab[*posxy[0]][*posxy[1]-1]==12||tab[*posxy[0]][*posxy[1]-1]==60||tab[*posxy[0]][*posxy[1]-1]==70||tab[*posxy[0]][*posxy[1]-1]==0||tab[*posxy[0]][*posxy[1]-1]==61||tab[*posxy[0]][*posxy[1]-1]==71||tab[*posxy[0]][*posxy[1]-1]==1||tab[*posxy[0]][*posxy[1]-1]==2||tab[*posxy[0]][*posxy[1]-1]==6||tab[*posxy[0]][*posxy[1]-1]==50||tab[*posxy[0]][*posxy[1]-1]==9||tab[*posxy[0]][*posxy[1]-1]==13||tab[*posxy[0]][*posxy[1]-1]==14||tab[*posxy[0]][*posxy[1]-1]==52||tab[*posxy[0]][*posxy[1]-1]==4||tab[*posxy[0]][*posxy[1]-1]==5||tab[*posxy[0]][*posxy[1]-1]==8||tab[*posxy[0]][*posxy[1]-1]==53||tab[*posxy[0]][*posxy[1]-1]==81))
                {*posxy[1]=-1;}
            case 3:
                if (*posxy[1]<7 && (tab[*posxy[0]][*posxy[1]+1] == 3||tab[*posxy[0]][*posxy[1]+1] == 62||tab[*posxy[0]][*posxy[1]+1] == 72||tab[*posxy[0]][*posxy[1]+1] == 15||tab[*posxy[0]][*posxy[1]+1] == 63||tab[*posxy[0]][*posxy[1]+1] == 73||tab[*posxy[0]][*posxy[1]+1] == 1||tab[*posxy[0]][*posxy[1]+1] == 2||tab[*posxy[0]][*posxy[1]+1] == 6||tab[*posxy[0]][*posxy[1]+1] == 50||tab[*posxy[0]][*posxy[1]+1] == 7||tab[*posxy[0]][*posxy[1]+1] == 10||tab[*posxy[0]][*posxy[1]+1] == 11||tab[*posxy[0]][*posxy[1]+1] == 51||tab[*posxy[0]][*posxy[1]+1] == 9||tab[*posxy[0]][*posxy[1]+1] == 13||tab[*posxy[0]][*posxy[1]+1] == 14||tab[*posxy[0]][*posxy[1]+1] == 52||tab[*posxy[0]][*posxy[1]+1] == 81))
                {*posxy[1]=+1;}
            case 4:
                if (*posxy[0]<7 && (tab[*posxy[0]+1][*posxy[1]]==12||tab[*posxy[0]+1][*posxy[1]]==60||tab[*posxy[0]+1][*posxy[1]]==70||tab[*posxy[0]+1][*posxy[1]]==15||tab[*posxy[0]+1][*posxy[1]]==63||tab[*posxy[0]+1][*posxy[1]]==73||tab[*posxy[0]+1][*posxy[1]]==7||tab[*posxy[0]+1][*posxy[1]]==10||tab[*posxy[0]+1][*posxy[1]]==11||tab[*posxy[0]+1][*posxy[1]]==51||tab[*posxy[0]+1][*posxy[1]]==9||tab[*posxy[0]+1][*posxy[1]]==13||tab[*posxy[0]+1][*posxy[1]]==14||tab[*posxy[0]+1][*posxy[1]]==52||tab[*posxy[0]+1][*posxy[1]]==4||tab[*posxy[0]+1][*posxy[1]]==5||tab[*posxy[0]+1][*posxy[1]]==8||tab[*posxy[0]+1][*posxy[1]]==53||tab[*posxy[0]+1][*posxy[1]]==80))
                {*posxy[0]=+1;}
            case 0:
                exit = 1;
                printf("Fin de tour du Joueur %d...",numjoueur);
        }
    }
}

// Affiche le terrain de jeu sur la console
/*void afficherTerrain4(int tab[LARGEUR][LARGEUR]) {
    // Déclare les tableaux pour chaque forme
    int caseT1[3][3] = {0,0,0, 1,1,1, 0,1,0};
    int caseT2[3][3] = {0,1,0, 1,1,0, 0,1,0};
    int caseT3[3][3] = {0,1,0, 1,1,1, 0,0,0};
    int caseT4[3][3] = {0,1,0, 0,1,1, 0,1,0};
    int caseL1[3][3] = {0,1,0, 0,1,1, 0,0,0};
    int caseL2[3][3] = {0,0,0, 0,1,1, 0,1,0};
    int caseL3[3][3] = {0,0,0, 1,1,0, 0,1,0};
    int caseL4[3][3] = {0,1,0, 1,1,0, 0,0,0};
    int caseI1[3][3] = {0,1,0, 0,1,0, 0,1,0};
    int caseI2[3][3] = {0,0,0, 1,1,1, 0,0,0};

    // Change la couleur de fond de la console en noir
    bg_color(BLACK);

    // Imprime l'en-tête de la grille
    printf("\n\n    |");
    bg_color(CYAN); // Change la couleur de fond en cyan
    for(int i = 0; i < LARGEUR; i++) {
        printf(" %1c  ", i+'A'); // Imprime les étiquettes de colonne
        printf("            "); // Imprime les étiquettes de colonne
    }
    bg_color(BLACK); // Change la couleur de fond en noir

// Affiche une ligne de tirets en haut de la grille
    printf("\n---------------");
    for(int i=0; i<LARGEUR; i++) {
        printf("---------------");
    }

// Affiche un saut de ligne
    printf("\n");

// Itère sur chaque ligne de la grille
    for(int i=0; i<LARGEUR; i++) {
        // Change la couleur de fond en cyan et affiche l'index de la ligne
        bg_color(CYAN);
        printf(" %1d ", i);

        // Change la couleur de fond en noir et affiche un "pipe"
        bg_color(BLACK);
        printf("|");

        // Itère sur chaque colonne de la grille
        for(int j=0; j<LARGEUR; j++) {
            // Récupère la valeur de la case à la ligne i et la colonne j
            int value = tab[i][j];
            if(value == 1 || value == 2 || value == 6 || value == 50) {
                // T1 shape
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        // Si la valeur de caseT1 est 0, change la couleur de fond en orange et affiche un espace
                        if (caseT1[k][l] == 0) {
                            bg_color(ORANGE);
                            printf(" %1c  ", ' ');
                        }
                        // Si la valeur de caseT1 est 1, change la couleur de fond en jaune et affiche un espace
                        if (caseT1[k][l] == 1) {
                            bg_color(YELLOW);
                            printf(" %1c  ", ' ');
                        }
                    }
                }
            }
            else if(value == 7 || value == 10 || value == 11 || value == 51) {
                // T2 shape
                for (int k = 0; k < 3;k++) {
                    for (int l = 0; l < 3; l++) {
                        // Si la valeur de caseT3 est 0, change la couleur de fond en orange et affiche un espace
                        if (caseT2[k][l] == 0) {
                            bg_color(ORANGE);
                            printf(" %1c  ", ' ');
                        }
                        // Si la valeur de caseT3 est 1, change la couleur de fond en jaune et affiche un espace
                        if (caseT2[k][l] == 1) {
                            bg_color(YELLOW);
                            printf(" %1c  ", ' ');
                        }
                    }
                }
            }

            else if(value == 9 || value == 13 || value == 14 || value == 52) {
                // T3 shape
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (caseT3[k][l] == 0) {
                            bg_color(ORANGE);
                            printf(" %1c  ", ' ');
                        }
                        if (caseT3[k][l] == 1) {
                            bg_color(YELLOW);
                            printf(" %1c  ", ' ');
                        }
                    }
                }
            }
            else if(value == 4 || value == 5 || value == 8 || value == 53) {
                // T4 shape
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (caseT4[k][l] == 0) {
                            bg_color(ORANGE);
                            printf(" %1c  ", ' ');
                        }
                        if (caseT4[k][l] == 1) {
                            bg_color(YELLOW);
                            printf(" %1c  ", ' ');
                        }
                    }
                }
            }
            else if(value == 12 || value == 60 || value == 70) {
                // L1 shape
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (caseL1[k][l] == 0) {
                            bg_color(ORANGE);
                            printf(" %1c  ", ' ');
                        }
                        if (caseL1[k][l] == 1) {
                            bg_color(YELLOW);
                            printf(" %1c  ", ' ');
                        }
                    }
                }
            }
            else if(value == 0 || value == 61 || value == 71) {
                // L2 shape
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (caseL2[k][l] == 0) {
                            bg_color(ORANGE);
                            printf(" %1c  ", ' ');
                        }
                        if (caseL2[k][l] == 1) {
                            bg_color(YELLOW);
                            printf(" %1c  ", ' ');
                        }
                    }
                }
            }
            else if(value == 3 || value == 62 || value == 72) {
                // L3 shape
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (caseL3[k][l] == 0) {
                            bg_color(ORANGE);
                            printf(" %1c  ", ' ');
                        }
                        if (caseL3[k][l] == 1) {
                            bg_color(YELLOW);
                            printf(" %1c  ", ' ');
                        }
                    }
                }
            }
            else if(value == 15 || value == 63 || value == 73) {
                // L4 shape
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (caseL4[k][l] == 0) {
                            bg_color(ORANGE);
                            printf(" %1c  ", ' ');
                        }
                        if (caseL4[k][l] == 1) {
                            bg_color(YELLOW);
                            printf(" %1c  ", ' ');
                        }
                    }
                }
            }
            else if(value == 80) {
                // I1 shape
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (caseI1[k][l] == 0) {
                            bg_color(ORANGE);
                            printf(" %1c  ", ' ');
                        }
                        if (caseI1[k][l] == 1) {
                            bg_color(YELLOW);
                            printf(" %1c  ", ' ');
                        }
                    }
                }
            }
            else if(value == 81){
                // I2 shape
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (caseI2[k][l] == 0) {
                            bg_color(ORANGE);
                            printf(" %1c  ", ' ');
                        }
                        if (caseI2[k][l] == 1) {
                            bg_color(YELLOW);
                            printf(" %1c  ", ' ');
                        }
                    }
                }
        }
        else {
            // Empty space
            bg_color(BLACK);
            printf(" %1c  ", ' ');
        }
        bg_color(BLACK);
    }
    printf("\n");
}
}
*/
/*void afficherTerrain4(int tab[LARGEUR][LARGEUR]) {
    _setmode(_fileno(stdout), _O_U16TEXT);
    // Déclare les tableaux pour chaque forme
    int caseT1[3][3] = {0,0,0, 1,1,1, 0,1,0};
    int caseT2[3][3] = {0,1,0, 1,1,0, 0,1,0};
    int caseT3[3][3] = {0,1,0, 1,1,1, 0,0,0};
    int caseT4[3][3] = {0,1,0, 0,1,1, 0,1,0};
    int caseL1[3][3] = {0,1,0, 0,1,1, 0,0,0};
    int caseL2[3][3] = {0,0,0, 0,1,1, 0,1,0};
    int caseL3[3][3] = {0,0,0, 1,1,0, 0,1,0};
    int caseL4[3][3] = {0,1,0, 1,1,0, 0,0,0};
    int caseI1[3][3] = {0,1,0, 0,1,0, 0,1,0};
    int caseI2[3][3] = {0,0,0, 1,1,1, 0,0,0};

    // Change la couleur de fond de la console en noir
    bg_color(BLACK);

    // Imprime l'en-tête de la grille
    printf("\n\n    |");
    bg_color(CYAN); // Change la couleur de fond en cyan
    for(int i = 0; i < LARGEUR; i++) {
        printf(" %1c  ", i+'A'); // Imprime les étiquettes de colonne
        printf("            "); // Imprime les étiquettes de colonne
    }
    bg_color(BLACK); // Change la couleur de fond en noir

// Affiche une ligne de tirets en haut de la grille
    printf("\n---------------");
    for(int i=0; i<LARGEUR; i++) {
        printf("---------------");
    }

// Affiche un saut de ligne
    printf("\n");

// Itère sur chaque ligne de la grille
    for(int i=0; i<LARGEUR; i++) {
        // Change la couleur de fond en cyan et affiche l'index de la ligne
        bg_color(CYAN);
        printf(" %1d ", i);

        // Change la couleur de fond en noir et affiche un "pipe"
        bg_color(BLACK);
        printf("|");

        // Itère sur chaque colonne de la grille
        for(int j=0; j<LARGEUR; j++) {
            // Récupère la valeur de la case à la ligne i et la colonne j
            int value = tab[i][j];
            if(value == 1 || value == 2 || value == 6 || value == 50) {
                // T1 shape
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        // Si la valeur de caseT1 est 0, change la couleur de fond en orange et affiche un espace
                        if (caseT1[k][l] == 0) {
                            wprintf(L"\x2588\x2588");
                        }
                        // Si la valeur de caseT1 est 1, change la couleur de fond en jaune et affiche un espace
                        if (caseT1[k][l] == 1) {
                            printf(" %2c  ", ' ');
                        }
                    }
                }
            }
            else if(value == 7 || value == 10 || value == 11 || value == 51) {
                // T2 shape
                for (int k = 0; k < 3;k++) {
                    for (int l = 0; l < 3; l++) {
                        // Si la valeur de caseT3 est 0, change la couleur de fond en orange et affiche un espace
                        if (caseT2[k][l] == 0) {
                            wprintf(L"\x2588\x2588");
                        }
                        // Si la valeur de caseT3 est 1, change la couleur de fond en jaune et affiche un espace
                        if (caseT2[k][l] == 1) {
                            printf(" %1c  ", ' ');
                        }
                    }
                }
            }

            else if(value == 9 || value == 13 || value == 14 || value == 52) {
                // T3 shape
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (caseT3[k][l] == 0) {
                            wprintf(L"\x2588\x2588");
                        }
                        if (caseT3[k][l] == 1) {

                            printf(" %1c  ", ' ');
                        }
                    }
                }
            }
            else if(value == 4 || value == 5 || value == 8 || value == 53) {
                // T4 shape
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (caseT4[k][l] == 0) {
                            wprintf(L"\x2588\x2588");
                        }
                        if (caseT4[k][l] == 1) {

                            printf(" %1c  ", ' ');
                        }
                    }
                }
            }
            else if(value == 12 || value == 60 || value == 70) {
                // L1 shape
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (caseL1[k][l] == 0) {
                            wprintf(L"\x2588\x2588");
                        }
                        if (caseL1[k][l] == 1) {

                            printf(" %1c  ", ' ');
                        }
                    }
                }
            }
            else if(value == 0 || value == 61 || value == 71) {
                // L2 shape
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (caseL2[k][l] == 0) {
                            wprintf(L"\x2588\x2588");
                        }
                        if (caseL2[k][l] == 1) {

                            printf(" %1c  ", ' ');
                        }
                    }
                }
            }
            else if(value == 3 || value == 62 || value == 72) {
                // L3 shape
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (caseL3[k][l] == 0) {
                            wprintf(L"\x2588\x2588");
                        }
                        if (caseL3[k][l] == 1) {

                            printf(" %1c  ", ' ');
                        }
                    }
                }
            }
            else if(value == 15 || value == 63 || value == 73) {
                // L4 shape
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (caseL4[k][l] == 0) {
                            wprintf(L"\x2588\x2588");
                        }
                        if (caseL4[k][l] == 1) {

                            printf(" %1c  ", ' ');
                        }
                    }
                }
            }
            else if(value == 80) {
                // I1 shape
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (caseI1[k][l] == 0) {
                            wprintf(L"\x2588\x2588");
                        }
                        if (caseI1[k][l] == 1) {

                            printf(" %1c  ", ' ');
                        }
                    }
                }
            }
            else if(value == 81){
                // I2 shape
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (caseI2[k][l] == 0) {
                            wprintf(L"\x2588\x2588");
                        }
                        if (caseI2[k][l] == 1) {

                            printf(" %1c  ", ' ');
                        }
                    }
                }
            }
            else {
                // Empty space
                bg_color(BLACK);
                printf(" %1c  ", ' ');
            }
            bg_color(BLACK);
        }
        printf("\n");
    }
}*/