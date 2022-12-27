//
// Created by bapti on 27/12/2022.
//
#include "sprog.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <io.h>

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
}
void afficheCarteJoueur(int *nbJoueurs,int *nbCartesJoueurs, char nomJoueurs[4][LONGUEUR_NOM],int cartesJoueurs[CARTES][CARTES]){
    // Affichage des cartes de chaque joueur
    for (int joueur = 0; joueur < *nbJoueurs; joueur++) {
        printf("%s : ", nomJoueurs[joueur]);
        for (int i = 0; i < *nbCartesJoueurs; i++) {
            printf("%d ", cartesJoueurs[joueur][i]);
        }
        printf("\n");
    }
}