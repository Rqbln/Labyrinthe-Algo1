//
// Created by bapti on 30/11/2022.
//
#include "sprog.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <io.h>

void afficherTitre (){
    _setmode(_fileno(stdout), _O_U16TEXT);
    color(5,0);
    wprintf(L"\x2588\x2588\x2557\x0020\x0020\x0020\x0020\x0020\x0020\x2588\x2588\x2588\x2588\x2588\x2557\x0020\x2588\x2588\x2588\x2588\x2588\x2588\x2557\x0020\x2588\x2588\x2557\x0020\x0020\x0020\x2588\x2588\x2557\x2588\x2588\x2588\x2588\x2588\x2588\x2557\x0020\x2588\x2588\x2557\x2588\x2588\x2588\x2557\x0020\x0020\x0020\x2588\x2588\x2557\x2588\x2588\x2588\x2588\x2588\x2588\x2588\x2588\x2557\x2588\x2588\x2557\x0020\x0020\x2588\x2588\x2557\x2588\x2588\x2588\x2588\x2588\x2588\x2588\x2557\n");
    color(13,0);
    wprintf(L"\x2588\x2588\x2551\x0020\x0020\x0020\x0020\x0020\x2588\x2588\x2554\x2550\x2550\x2588\x2588\x2557\x2588\x2588\x2554\x2550\x2550\x2588\x2588\x2557\x255a\x2588\x2588\x2557\x0020\x2588\x2588\x2554\x255d\x2588\x2588\x2554\x2550\x2550\x2588\x2588\x2557\x2588\x2588\x2551\x2588\x2588\x2588\x2588\x2557\x0020\x0020\x2588\x2588\x2551\x255a\x2550\x2550\x2588\x2588\x2554\x2550\x2550\x255d\x2588\x2588\x2551\x0020\x0020\x2588\x2588\x2551\x2588\x2588\x2554\x2550\x2550\x2550\x2550\x255d\n");
    color(5,0);
    wprintf(L"\x2588\x2588\x2551\x0020\x0020\x0020\x0020\x0020\x2588\x2588\x2588\x2588\x2588\x2588\x2588\x2551\x2588\x2588\x2588\x2588\x2588\x2588\x2554\x255d\x0020\x255a\x2588\x2588\x2588\x2588\x2554\x255d\x0020\x2588\x2588\x2588\x2588\x2588\x2588\x2554\x255d\x2588\x2588\x2551\x2588\x2588\x2554\x2588\x2588\x2557\x0020\x2588\x2588\x2551\x0020\x0020\x0020\x2588\x2588\x2551\x0020\x0020\x0020\x2588\x2588\x2588\x2588\x2588\x2588\x2588\x2551\x2588\x2588\x2588\x2588\x2588\x2557\x0020\x0020\n");
    color(13,0);
    wprintf(L"\x2588\x2588\x2551\x0020\x0020\x0020\x0020\x0020\x2588\x2588\x2554\x2550\x2550\x2588\x2588\x2551\x2588\x2588\x2554\x2550\x2550\x2588\x2588\x2557\x0020\x0020\x255a\x2588\x2588\x2554\x255d\x0020\x0020\x2588\x2588\x2554\x2550\x2550\x2588\x2588\x2557\x2588\x2588\x2551\x2588\x2588\x2551\x255a\x2588\x2588\x2557\x2588\x2588\x2551\x0020\x0020\x0020\x2588\x2588\x2551\x0020\x0020\x0020\x2588\x2588\x2554\x2550\x2550\x2588\x2588\x2551\x2588\x2588\x2554\x2550\x2550\x255d\x0020\x0020\n");
    color(5,0);
    wprintf(L"\x2588\x2588\x2588\x2588\x2588\x2588\x2588\x2557\x2588\x2588\x2551\x0020\x0020\x2588\x2588\x2551\x2588\x2588\x2588\x2588\x2588\x2588\x2554\x255d\x0020\x0020\x0020\x2588\x2588\x2551\x0020\x0020\x0020\x2588\x2588\x2551\x0020\x0020\x2588\x2588\x2551\x2588\x2588\x2551\x2588\x2588\x2551\x0020\x255a\x2588\x2588\x2588\x2588\x2551\x0020\x0020\x0020\x2588\x2588\x2551\x0020\x0020\x0020\x2588\x2588\x2551\x0020\x0020\x2588\x2588\x2551\x2588\x2588\x2588\x2588\x2588\x2588\x2588\x2557\n");
    color(13,0);
    wprintf(L"\x255a\x2550\x2550\x2550\x2550\x2550\x2550\x255d\x255a\x2550\x255d\x0020\x0020\x255a\x2550\x255d\x255a\x2550\x2550\x2550\x2550\x2550\x255d\x0020\x0020\x0020\x0020\x255a\x2550\x255d\x0020\x0020\x0020\x255a\x2550\x255d\x0020\x0020\x255a\x2550\x255d\x255a\x2550\x255d\x255a\x2550\x255d\x0020\x0020\x255a\x2550\x2550\x2550\x255d\x0020\x0020\x0020\x255a\x2550\x255d\x0020\x0020\x0020\x255a\x2550\x255d\x0020\x0020\x255a\x2550\x255d\x255a\x2550\x2550\x2550\x2550\x2550\x2550\x255d\n");
    color(15,0);
    _setmode(_fileno(stdout), _O_TEXT);
}

void ligne(){
    _setmode(_fileno(stdout), _O_U16TEXT);
    wprintf(L"\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\n");
    color(15,0);
    _setmode(_fileno(stdout), _O_TEXT);
}

void nombreJoueurs(int *nbJoueurs, int *nbCartesJoueurs){
    char buffer[BUFFER_SIZE];
    // Saisie du nombre de joueurs
    printf("Entrez le nombre de joueurs (entre 2 et 4) :");
    fflush(stdin);
    fgets(buffer, BUFFER_SIZE, stdin);


// Conversion de la saisie en entier et vérification de la validité
    while (sscanf(buffer, "%d", nbJoueurs) != 1 || *nbJoueurs < 2 || *nbJoueurs > 4) {
        printf("Entrez le nombre de joueurs (entre 2 et 4) :");
        fflush(stdin);
        fgets(buffer, BUFFER_SIZE, stdin);
    }
    printf("%d joueurs seront dans cette partie.\n",*nbJoueurs);


    *nbCartesJoueurs = CARTES / *nbJoueurs;
}


void CreationNomJoueurs(int *nbJoueurs,char nomJoueurs[4][LONGUEUR_NOM]){

    // Demande le nom de chaque joueur
    for (int i = 0; i < *nbJoueurs; i++) {
        printf("Entrez le nom du joueur %d :", i+1);
        scanf("%s", nomJoueurs[i]);
    }

    // Affiche les noms des joueurs
    printf("Les noms des joueurs sont :\n");
    for (int i = 0; i < *nbJoueurs; i++) {
        printf("- %s\n", nomJoueurs[i]);
    }

}

void distributionPions(int *nbJoueurs,char nomJoueurs[4][LONGUEUR_NOM]){

}

void distributionCartes (int *nbJoueurs, int *nbCartesJoueurs, char nomJoueurs[4][LONGUEUR_NOM],int cartesJoueurs[CARTES][CARTES]){
    // Déclaration des variables locales
    int nbCartes[CARTES];
    int i;
    int joueur;
    char buffer[BUFFER_SIZE];

    // Initialisation de la fonction rand avec l'heure courante
    srand(time(NULL));

    // Remplissage du tableau nbCartes avec les numéros de 0 à CARTES-1
    for (i = 0; i < CARTES; i++) {
        nbCartes[i] = i;
    }

    // Mélange du tableau nbCartes avec l'algorithme de Fisher-Yates
    for (i = CARTES - 1; i > 0; i--) {
        size_t j = rand() % (i + 1);
        int temp = nbCartes[i];
        nbCartes[i] = nbCartes[j];
        nbCartes[j] = temp;
    }

    // Distribution des cartes mélangées aux joueurs
    for (i = 0; i < CARTES; i++) {
        joueur = i % *nbJoueurs;
        cartesJoueurs[joueur][i / *nbJoueurs] = nbCartes[i]+10;
    }

    // Affichage des cartes de chaque joueur
    for (joueur = 0; joueur < *nbJoueurs; joueur++) {
        printf("%s : ", nomJoueurs[joueur]);
        for (i = 0; i < *nbCartesJoueurs; i++) {
            printf("%d ", cartesJoueurs[joueur][i]);
        }
        printf("\n");
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