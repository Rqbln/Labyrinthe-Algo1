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
void distributionPions(int *nbJoueurs,char nomJoueurs[4][LONGUEUR_NOM],int pionsJoueurs[4]){
    printf("Les pions disponibles sont :\n");
    if (*nbJoueurs == 2){

        _setmode(_fileno(stdout), _O_U16TEXT);
        color(1,0);
        wprintf(L"\x0031\x002e\x0020\x2660\n");
        color(5,0);
        wprintf(L"\x0032\x002e\x0020\x2663\n");
        color(15,0);

    }
    if (*nbJoueurs == 3){
        _setmode(_fileno(stdout), _O_U16TEXT);
        color(1,0);
        wprintf(L"\x0031\x002e\x0020\x2660\n");
        color(5,0);
        wprintf(L"\x0032\x002e\x0020\x2663\n");
        color(4,0);
        wprintf(L"\x0033\x002e\x0020\x2665\n");
        color(15,0);

    }
    if (*nbJoueurs == 4){
        _setmode(_fileno(stdout), _O_U16TEXT);
        color(1,0);
        wprintf(L"\x0031\x002e\x0020\x2660\n");
        color(5,0);
        wprintf(L"\x0032\x002e\x0020\x2663\n");
        color(4,0);
        wprintf(L"\x0033\x002e\x0020\x2665\n");
        color(2,0);
        wprintf(L"\x0034\x002e\x0020\x2666\n");
        color(15,0);
    }
    _setmode(_fileno(stdout), _O_TEXT);
    char input[BUFFER_SIZE];
    for (int i = 0; i < *nbJoueurs; ++i) {
        pionsJoueurs[i]=0;
        while (pionsJoueurs[i]<1 ||pionsJoueurs[i]>4){
            printf("%s, choisissez votre pion :",nomJoueurs[i]);
            fflush(stdin);
            fgets(input,BUFFER_SIZE,stdin);
            pionsJoueurs[i]= atoi(input);
        }
    }
    for (int i = 0; i < *nbJoueurs; ++i) {
        printf("%s a choisi le pion %d\n",nomJoueurs[i],pionsJoueurs[i]);
    }
    printf("\n");


}

void debutPartie (int *nbJoueurs, int *tourJoueur, char nomJoueurs[4][LONGUEUR_NOM], int pionsJoueurs[4], int* nbTours){
    srand(time(NULL));
    *tourJoueur=rand()%*nbJoueurs;
    printf("Tour %d :\n",*nbTours);
    printf("C'est a %s de commencer !\n",nomJoueurs[*tourJoueur]);
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
    int caracteres;
    for (int joueur = 0; joueur < *nbJoueurs; joueur++) {
        printf("%s : \n", nomJoueurs[joueur]);
        for (int j = 0; j < *nbCartesJoueurs; ++j) {
            _setmode(_fileno(stdout), _O_U16TEXT);
            wprintf(L"\x250C\x2500\x2500\x2510");
        }
        wprintf(L"\n");
        for (int i = 0; i < *nbCartesJoueurs; i++) {
            _setmode(_fileno(stdout), _O_U16TEXT);
            wprintf(L"\x2502");
            _setmode(_fileno(stdout), _O_TEXT);
            //printf("%d ", cartesJoueurs[joueur][i]);
            caracteres=cartesJoueurs[joueur][i];
            caractere(&caracteres);
            _setmode(_fileno(stdout), _O_U16TEXT);
            wprintf(L"\x2502");
            _setmode(_fileno(stdout), _O_TEXT);
        }
        printf("\n");
        for (int j = 0; j < *nbCartesJoueurs; ++j) {
            _setmode(_fileno(stdout), _O_U16TEXT);
            wprintf(L"\x2514\x2500\x2500\x2518");
        }
        wprintf(L"\n");
        _setmode(_fileno(stdout), _O_TEXT);
    }
}
void afficheCarteJoueur1(int *tourJoueur,int *nbCartesJoueurs, char nomJoueurs[4][LONGUEUR_NOM],int cartesJoueurs[CARTES][CARTES], int *cartejoueur1,int *cartejoueur2,int *cartejoueur3,int *cartejoueur4){
    int cartejoueur;
    int caracteres;
    switch (*tourJoueur) {
        case 0:
            cartejoueur=*cartejoueur1;
            break;
        case 1:
            cartejoueur=*cartejoueur2;
            break;
        case 2:
            cartejoueur=*cartejoueur3;
            break;
        case 3:
            cartejoueur=*cartejoueur4;
            break;
    }
    printf("%s, Voici tes cartes tresor a trouver : \n", nomJoueurs[*tourJoueur]);
    _setmode(_fileno(stdout), _O_U16TEXT);
    wprintf(L"\x250C\x2500\x2500\x2510");
    wprintf(L"\n");
    wprintf(L"\x2502");
    _setmode(_fileno(stdout), _O_TEXT);
    caracteres=cartesJoueurs[*tourJoueur][cartejoueur];
    caractere(&caracteres);
    _setmode(_fileno(stdout), _O_U16TEXT);
    wprintf(L"\x2502");
    wprintf(L"\n");
    wprintf(L"\x2514\x2500\x2500\x2518");
    wprintf(L"\n");
    _setmode(_fileno(stdout), _O_TEXT);
    switch (*tourJoueur) {
        case 0:
            *cartejoueur1+=1;
            break;
        case 1:
            *cartejoueur2+=1;
            break;
        case 2:
            *cartejoueur3+=1;
            break;
        case 3:
            *cartejoueur4+=1;
            break;
    }
}