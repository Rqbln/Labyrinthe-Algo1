#include "sprog.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Déclare les variables globales pour la couleur de fond et de texte
static int __BACKGROUND = BLACK;
static int __FOREGROUND = WHITE;

// Change la couleur du texte de la console
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

// Affiche le terrain de jeu sur la console
void afficherTerrain4(int tab[LARGEUR][LARGEUR], int taille) {
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
    for(int i = 0; i < taille; i++) {
        printf(" %2c  ", i+'A'); // Imprime les étiquettes de colonne
    }
    bg_color(BLACK); // Change la couleur de fond en noir

// Affiche une ligne de tirets en haut de la grille
    printf("\n-----");
    for(int i=0; i<taille; i++) {
        printf("-----");
    }

// Affiche un saut de ligne
    printf("\n");

// Itère sur chaque ligne de la grille
    for(int i=0; i<taille; i++) {
        // Change la couleur de fond en cyan et affiche l'index de la ligne
        bg_color(CYAN);
        printf(" %2d ", i);

        // Change la couleur de fond en noir et affiche un "pipe"
        bg_color(BLACK);
        printf("|");

        // Itère sur chaque colonne de la grille
        for(int j=0; j<taille; j++) {
            // Récupère la valeur de la case à la ligne i et la colonne j
            int value = tab[i][j];
            if(value == 1 || value == 2 || value == 6 || value == 50) {
                // T1 shape
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        // Si la valeur de caseT1 est 0, change la couleur de fond en orange et affiche un espace
                        if (caseT1[k][l] == 0) {
                            bg_color(ORANGE);
                            printf(" %2c  ", ' ');
                        }
                        // Si la valeur de caseT1 est 1, change la couleur de fond en jaune et affiche un espace
                        if (caseT1[k][l] == 1) {
                            bg_color(YELLOW);
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
                        if (caseT3[k][l] == 0) {
                            bg_color(ORANGE);
                            printf(" %2c  ", ' ');
                        }
                        // Si la valeur de caseT3 est 1, change la couleur de fond en jaune et affiche un espace
                        if (caseT3[k][l] == 1) {
                            bg_color(YELLOW);
                            printf(" %2c  ", ' ');
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
                            printf(" %2c  ", ' ');
                        }
                        if (caseT3[k][l] == 1) {
                            bg_color(YELLOW);
                            printf(" %2c  ", ' ');
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
                            printf(" %2c  ", ' ');
                        }
                        if (caseT4[k][l] == 1) {
                            bg_color(YELLOW);
                            printf(" %2c  ", ' ');
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
                            printf(" %2c  ", ' ');
                        }
                        if (caseL1[k][l] == 1) {
                            bg_color(YELLOW);
                            printf(" %2c  ", ' ');
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
                            printf(" %2c  ", ' ');
                        }
                        if (caseL2[k][l] == 1) {
                            bg_color(YELLOW);
                            printf(" %2c  ", ' ');
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
                            printf(" %2c  ", ' ');
                        }
                        if (caseL3[k][l] == 1) {
                            bg_color(YELLOW);
                            printf(" %2c  ", ' ');
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
                            printf(" %2c  ", ' ');
                        }
                        if (caseL4[k][l] == 1) {
                            bg_color(YELLOW);
                            printf(" %2c  ", ' ');
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
                            printf(" %2c  ", ' ');
                        }
                        if (caseI1[k][l] == 1) {
                            bg_color(YELLOW);
                            printf(" %2c  ", ' ');
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
                            printf(" %2c  ", ' ');
                        }
                        if (caseI2[k][l] == 1) {
                            bg_color(YELLOW);
                            printf(" %2c  ", ' ');
                        }
                    }
                }
        }
        else {
            // Empty space
            bg_color(BLACK);
            printf(" %2c  ", ' ');
        }
        bg_color(BLACK);
    }
    printf("\n");
}
}
/*void afficherTerrain4(int tab[LARGEUR][LARGEUR], int taille){
    int caseT1[3][3]={0,0,0,
                      1,1,1,
                      0,1,0,};

    int caseT2[3][3]={0,1,0,
                      1,1,0,
                      0,1,0,};

    int caseT3[3][3]={0,1,0,
                      1,1,1,
                      0,0,0,};

    int caseT4[3][3]={0,1,0,
                      0,1,1,
                      0,1,0,};

    int caseL1[3][3]={0,1,0,
                      0,1,1,
                      0,0,0};

    int caseL2[3][3]={0,0,0,
                      0,1,1,
                      0,1,0};

    int caseL3[3][3]={0,0,0,
                      1,1,0,
                      0,1,0};

    int caseL4[3][3]={0,1,0,
                      1,1,0,
                      0,0,0};

    int caseI1[3][3]={0,1,0,
                      0,1,0,
                      0,1,0};

    int caseI2[3][3]={0,0,0,
                      1,1,1,
                      0,0,0};

    int i;
    printf("\n\n    |");
    bg_color(CYAN);
    for(i=0;i<taille;i++){
        printf(" %2c  ",i+'A');
    }
    bg_color(BLACK);
    printf("\n-----");
    for(i=0;i<taille;i++){
        printf("-----");
    }
    printf("\n");
    for(i=0;i<taille;i++){
        bg_color(CYAN);
        printf(" %2d ",i);
        bg_color(BLACK);
        printf("|");
        bg_color(WHITE);
        for(int j=0;j<taille;j++){
            if(tab[i][j] == 1,2,6,50){ //T1
                for (int k = 0; k < (3); k++) {
                    for (int l = 0; l < (3); j++) {
                        if (caseT1[i][j] = 0) {
                            bg_color(ORANGE);
                            printf(" %2c  ", ' ');
                        }
                        if (caseT1[i][j] = 1) {
                            bg_color(YELLOW);
                            printf(" %2c  ", ' ');
                        }
                    }
                }
            }
            if(tab[i][j] == 7,10,11,51){   //T2
                for (int k = 0; k < (3); k++) {
                    for (int l = 0; l < (3); j++) {
                        if (caseT2[i][j] = 0) {
                            bg_color(ORANGE);
                            printf(" %2c  ", ' ');
                        }
                        if (caseT2[i][j] = 1) {
                            bg_color(YELLOW);
                            printf(" %2c  ", ' ');
                        }
                    }
                }
            }
            if(tab[i][j] == 9,13,14,52){   //T3
                for (int k = 0; k < (3); k++) {
                    for (int l = 0; l < (3); j++) {
                        if (caseT3[i][j] = 0) {
                            bg_color(ORANGE);
                            printf(" %2c  ", ' ');
                        }
                        if (caseT3[i][j] = 1) {
                            bg_color(YELLOW);
                            printf(" %2c  ", ' ');
                        }
                    }
                }
            }
            if(tab[i][j] == 4,5,8,53){   //T4
                for (int k = 0; k < (3); k++) {
                    for (int l = 0; l < (3); j++) {
                        if (caseT4[i][j] = 0) {
                            bg_color(ORANGE);
                            printf(" %2c  ", ' ');
                        }
                        if (caseT4[i][j] = 1) {
                            bg_color(YELLOW);
                            printf(" %2c  ", ' ');
                        }
                    }
                }

            }
            if(tab[i][j] == 12,60,70){   //L1
                for (int k = 0; k < (3); k++) {
                    for (int l = 0; l < (3); j++) {
                        if (caseL1[i][j] = 0) {
                            bg_color(ORANGE);
                            printf(" %2c  ", ' ');
                        }
                        if (caseL1[i][j] = 1) {
                            bg_color(YELLOW);
                            printf(" %2c  ", ' ');
                        }
                    }
                }

            }
            if(tab[i][j] == 0,61,71){   //L2
                for (int k = 0; k < (3); k++) {
                    for (int l = 0; l < (3); j++) {
                        if (caseL2[i][j] = 0) {
                            bg_color(ORANGE);
                            printf(" %2c  ", ' ');
                        }
                        if (caseL2[i][j] = 1) {
                            bg_color(YELLOW);
                            printf(" %2c  ", ' ');
                        }
                    }
                }

            }
            if(tab[i][j] == 3,62,72){   //L3
                for (int k = 0; k < (3); k++) {
                    for (int l = 0; l < (3); j++) {
                        if (caseL3[i][j] = 0) {
                            bg_color(ORANGE);
                            printf(" %2c  ", ' ');
                        }
                        if (caseL3[i][j] = 1) {
                            bg_color(YELLOW);
                            printf(" %2c  ", ' ');
                        }
                    }
                }

            }
            if(tab[i][j] == 15,63,73){   //L4
                for (int k = 0; k < (3); k++) {
                    for (int l = 0; l < (3); j++) {
                        if (caseL4[i][j] = 0) {
                            bg_color(ORANGE);
                            printf(" %2c  ", ' ');
                        }
                        if (caseL4[i][j] = 1) {
                            bg_color(YELLOW);
                            printf(" %2c  ", ' ');
                        }
                    }
                }

            }
            if(tab[i][j] == 80){   //I1
                for (int k = 0; k < (3); k++) {
                    for (int l = 0; l < (3); j++) {
                        if (caseI1[i][j] = 0) {
                            bg_color(ORANGE);
                            printf(" %2c  ", ' ');
                        }
                        if (caseI1[i][j] = 1) {
                            bg_color(YELLOW);
                            printf(" %2c  ", ' ');
                        }
                    }
                }

            }
            if(tab[i][j] == 81){   //I2
                for (int k = 0; k < (3); k++) {
                    for (int l = 0; l < (3); j++) {
                        if (caseI2[i][j] = 0) {
                            bg_color(ORANGE);
                            printf(" %2c  ", ' ');
                        }
                        if (caseI2[i][j] = 1) {
                            bg_color(YELLOW);
                            printf(" %2c  ", ' ');
                        }
                    }
                }

            }
            text_color(WHITE);
        }
        bg_color(BLACK);
        printf("\n");
    }
}
*/