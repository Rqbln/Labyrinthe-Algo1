//
// Created by bapti on 27/12/2022.
//
#include "sprog.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <io.h>
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