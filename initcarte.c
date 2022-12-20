//
// Created by bapti on 20/12/2022.
//
#include "sprog.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
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
void affichageTableau(int tab[7][7]) {                   //sous programme pour les afficher le tableau
    //int tab[10][10];
    for (int i = 0; i < (7); i++) {
        for (int j = 0; j < (7); j++) {
            printf("%d ", tab[i][j]); //affichage des valeur
        }
        printf("\n");
    }

}
void convertab(int tab[7][7], char tableau[21][21]){
    int T;
    for (int i = 0; i < (7); i++) {
        for (int j = 0; j < (7); j++) {
            if (tab[i][j]>16 && tab[i][j]<23){
                tab[i][j]=50;   //case en T avec tresor 50
            }
            if (tab[i][j]>22 && tab[i][j]<28){
                tab[i][j]=51;   //case en L avec tresor 51
            }
            if (tab[i][j]>27 && tab[i][j]<38){
                tab[i][j]=52;   //case en L classique 52
            }
            if (tab[i][j]>37 && tab[i][j]<50){
                tab[i][j]=53;   //case en I classique 53
            }
            // de 0 a 15 case fixe
        }
    }
}


