//
// Created by bapti on 30/11/2022.
//
#include "sprog.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>



void essaieJoueur(int *ligne, int *colonne, int *point, int tab[7][7]){
    //for (int i = 0; i < (7); i++) {
    //    for (int j = 0; j < (7); j++) {
    //        printf("%d ", tab[i][j]); //affichage des valeur
    //    }
    //    printf("\n");
    //}
    *point=0;
    printf("entrer la ligne :");
    scanf("%d",&*ligne);
    printf("entrer la colonne :");
    scanf("%d", &*colonne);
    *point = tab[*ligne-1][*colonne-1];
    printf("La case comporte le nombre : %d\n",*point);
    tab[(*ligne-1)][(*colonne-1)]=0;
    //printf("ton nombre de point est : %d\n",*point);
    //printf("La case comporte le nombre : %d\n",tab[(*ligne-1)][(*colonne-1)]);
}
void finJeu(int *ligne, int *colonne, int tab[7][7], int* n){
    int sommecases;
    for(int i=0; i<(*ligne);i++){
        for (int j = 0; j <(*colonne); ++j) {
            sommecases+=tab[i][j];
            if (sommecases==0) {
                *n = 1;

            }
        }
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