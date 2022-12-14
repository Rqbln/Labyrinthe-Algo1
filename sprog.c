//
// Created by bapti on 30/11/2022.
//
#include "sprog.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>



void essaieJoueur(int *ligne, int *colonne, int *point, int tab[10][10]){
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
