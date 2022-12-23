//
// Created by bapti on 20/12/2022.
//
#include "sprog.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void initialisationTableau(int tab[LARGEUR][LARGEUR]) {//sous programme pour les valeur du tableau
    int tmp;
    int fixe=0;
    int verifieur[34];
    int p=0;
    srand(time(NULL));            //creation de du module aleatoire en fonction du temps
    for (int i = 0; i<(LARGEUR);i++){              //lignes
        for (int j = 0; j<(LARGEUR);j++){          //colones
            //printf("entrez valeur:");       //demande a l'utilisateur d entrer une valeur//scanf("%f",&tab[i][j]);  //entrée utilisateur
            if(i%2==0 && j%2==0){
                tab[i][j]=fixe;
                fixe+=1;
            }
            else{
                int verif=1;
                while(verif==1) {
                    verif=0;
                    tmp = ((LARGEUR/2)+1)*((LARGEUR/2)+1) + rand() % 34;   //creation d une variable aleatoire
                    for (int l = 0; l < 34; l++) {

                        if (verifieur[l] == tmp) {
                            verif = 1;
                        }
                    }
                }
                verifieur[p]=tmp;
                p+=1;
                tab[i][j]= tmp;
            }
        }
    }
}
void affichageTableau(int tab[LARGEUR][LARGEUR], char tableau[LARGEUR][LARGEUR], int tabite[21][21]) {                   //sous programme pour les afficher le tableau
    //int tab[10][10];
    for (int i = 0; i < (LARGEUR); i++) {
        for (int j = 0; j < (LARGEUR); j++) {
            printf("%d ", tab[i][j]); //affichage des valeur
        }
        printf("\n");
    }
   /* for (int i = 0; i < (LARGEUR); i++) {
        for (int j = 0; j < (LARGEUR); j++) {
            printf("%c ", tableau[i][j]); //affichage des valeur
        }
        printf("\n");
    }*/
    for (int i = 0; i < (21); i++) {
        for (int j = 0; j < (21); j++) {
            printf("%d ", tabite[i][j]); //affichage des valeur
        }
        printf("\n");
    }

}
void convertab(int tab[LARGEUR][LARGEUR], char tableau[LARGEUR][LARGEUR]){
    int T;
    for (int i = 0; i < (LARGEUR); i++) {
        for (int j = 0; j < (LARGEUR); j++) {
            if (tab[i][j]>15 && tab[i][j]<23){
                tab[i][j]=50 + rand() % 4;   //case en T avec tresor 50

            }
            if (tab[i][j]>22 && tab[i][j]<28){
                tab[i][j]=60 + rand() % 4;   //case en L avec tresor 51

            }
            if (tab[i][j]>27 && tab[i][j]<38){
                tab[i][j]=70 + rand() % 4;   //case en L classique 52

            }
            if (tab[i][j]>37 && tab[i][j]<50){
                tab[i][j]=80 + rand() % 2;   //case en I classique 53

            }
            // de 0 a 15 case fixe
        }
    }
}
void affect(int tabite[21][21], int *x, int *y, int cases[3][3]){  //tabite est le tableau qui rassemblera toutes les donnees
    tabite[*x*3][*y*3]=cases[0][0];
    tabite[*x*3][*y*3+1]=cases[0][1];
    tabite[*x*3][*y*3+2]=cases[0][2];
    tabite[*x*3+1][*y*3]=cases[1][0];
    tabite[*x*3+1][*y*3+1]=cases[1][1];
    tabite[*x*3+1][*y*3+2]=cases[1][2];
    tabite[*x*3+2][*y*3]=cases[2][0];
    tabite[*x*3+2][*y*3+1]=cases[2][1];
    tabite[*x*3+2][*y*3+2]=cases[2][2];
}
void coordonne(int tabite[21][21], int *x, int *y, int cases[3][3], int tab[LARGEUR][LARGEUR]){
    //on definit toutes les cases differente
    int caseT1[3][3] = {0,0,0, 1,8,1, 0,1,0}; //https://i.imgur.com/aXB8t7o.png
    int caseT2[3][3] = {0,1,0, 1,8,0, 0,1,0};
    int caseT3[3][3] = {0,1,0, 1,8,1, 0,0,0};
    int caseT4[3][3] = {0,1,0, 0,8,1, 0,1,0};
    int caseL1[3][3] = {0,1,0, 0,1,1, 0,0,0}; //https://i.imgur.com/Vn94Xo6.png
    int caseL2[3][3] = {0,0,0, 0,1,1, 0,1,0};
    int caseL3[3][3] = {0,0,0, 1,1,0, 0,1,0};
    int caseL4[3][3] = {0,1,0, 1,1,0, 0,0,0};
    int caseLT1[3][3] = {0,1,0, 0,8,1, 0,0,0}; //https://i.imgur.com/u5g71NJ.png
    int caseLT2[3][3] = {0,0,0, 0,8,1, 0,1,0};
    int caseLT3[3][3] = {0,0,0, 1,8,0, 0,1,0};
    int caseLT4[3][3] = {0,1,0, 1,8,0, 0,0,0};
    int caseI1[3][3] = {0,1,0, 0,1,0, 0,1,0};
    int caseI2[3][3] = {0,0,0, 1,1,1, 0,0,0};
    for (int i = 0; i < LARGEUR; ++i) {
        for (int j = 0; j < LARGEUR; ++j) {
            int value = tab[i][j];
            if (value == 1 || value == 2 || value == 6 || value == 50){
                affect(tabite, &*x, &*y, caseT1[3][3]);
            }
            if (value == 7 || value == 10 || value == 11 || value == 51){
                affect(tabite, &*x, &*y, caseT2[3][3]);
            }
            if (value == 9 || value == 13 || value == 14 || value == 52){
                affect(tabite, &*x, &*y, caseT3[3][3]);
            }
            if (value == 4 || value == 5 || value == 8 || value == 53){
                affect(tabite, &*x, &*y, caseT4);
            }//tabite prend les cases T

            if (value == 70){
                affect(tabite, &*x, &*y, caseL1);
            }
            if (value == 71){
                affect(tabite, &*x, &*y, caseL2);
            }
            if (value == 72){
                affect(tabite, &*x, &*y, caseL3);
            }
            if (value == 73){
                affect(tabite, &*x, &*y, caseL4);
            }//tabite prend les cases L

            if (value == 12 || value == 60){
                affect(tabite, &*x, &*y, caseLT1);
            }
            if (value == 0 || value == 61){
                affect(tabite, &*x, &*y, caseLT2);
            }
            if (value == 3 || value == 62){
                affect(tabite, &*x, &*y, caseLT3);
            }
            if (value == 15 || value == 63){
                affect(tabite, &*x, &*y, caseLT4);
            }//tabite prend les cases L Tresor

            if (value == 80){
                affect(tabite, &*x, &*y, caseI1);
            }
            if (value == 81){
                affect(tabite, &*x, &*y, caseI2);
            }//tabite prend les cases I

        }
    }
}