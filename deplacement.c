//
// Created by bapti on 27/12/2022.
//
#include "sprog.h"

#include <time.h>
#include <fcntl.h>
#include <io.h>
// Ce programme crée un tableau de caractères représentant un plateau de jeu
// et déplace un pion sur ce plateau en fonction des entrées de l'utilisateur.
// Les flèches du clavier permettent de déplacer le pion et la touche 'q' permet de quitter le programme.

#include <stdio.h> // Pour utiliser la fonction printf
#include <stdlib.h> // Pour utiliser la fonction getch
#include <conio.h> // Pour utiliser la fonction getch



void deplacementJoueur1(int tabfinal[21][21], int tab[LARGEUR][LARGEUR], char nomJoueurs[4][LONGUEUR_NOM], int pionsJoueurs[4], int *tourJoueur){
    // Déclaration du tableau et du pion
    // Le tableau est initialisé à '-' pour chaque case
    // Le pion est placé en position (0, 0) au début du programme
    int pion_row = 1, pion_col = 1;
    tabfinal[pion_row][pion_col] = 3;
    char demarrage;
    afficheplateaufinal(tab, tabfinal);
    printf("%s, appuyez sur 'Entree' pour deplacer votre pion\n",nomJoueurs[*tourJoueur]);
    do {
        demarrage=getchar();
    }while (demarrage!='\n');

    // Boucle principale de déplacement du pion
    // Le programme tourne en boucle jusqu'à ce que l'utilisateur appuie sur la touche 'q'
    while (1)
    {
        system("cls");
        afficherTitre();
        ligne();
        // Affichage du tableau et du pion
        afficheplateaufinal(tab, tabfinal);
        printf("\n");
        printf("Deplacez vous avec les touches 'z', 'q', 's', 'd' du clavier.\nAppuyez sur 'Entree' Pour arreter de deplacer le pion.");
        printf("\n");
        // Lecture de l'entrée utilisateur
        int c = getch();
        if (c == 'z' || c == 'q' || c == 's' || c == 'd' || c == 13) // Touches 'z', 'q', 's', 'd' et 'Entree'
        {
            if (c == 'z') // touche 'z'
            {
// Déplacement du pion vers le haut si possible
                if (pion_row > 0 + 3 && tabfinal[pion_row-1][pion_col] == 1 && tabfinal[pion_row-2][pion_col] == 1)
                {
                    tabfinal[pion_row][pion_col] = 1;
                    pion_row-=3;
                    tabfinal[pion_row][pion_col] = 3;
                }
            }
            else if (c == 's') // touche 's'
            {
// Déplacement du pion vers le bas si possible
                if (pion_row < 21 - 3 && tabfinal[pion_row+1][pion_col] == 1 && tabfinal[pion_row+2][pion_col] == 1)
                {
                    tabfinal[pion_row][pion_col] = 1;
                    pion_row+=3;
                    tabfinal[pion_row][pion_col] = 3;
                }
            }
            else if (c == 'q') // touche 'q'
            {
// Déplacement du pion vers la gauche si possible
                if (pion_col > 0 + 3 && tabfinal[pion_row][pion_col-1] == 1 && tabfinal[pion_row][pion_col-2] == 1)
                {
                    tabfinal[pion_row][pion_col] = 1;
                    pion_col-=3;
                    tabfinal[pion_row][pion_col] = 3;
                }
            }
            else if (c == 'd') // touche 'd'
            {
// Déplacement du pion vers la droite si possible
                if (pion_col < 21 - 3 && tabfinal[pion_row][pion_col+1] == 1 && tabfinal[pion_row][pion_col+2] == 1)
                {
                    tabfinal[pion_row][pion_col] = 1;
                    pion_col+=3;
                    tabfinal[pion_row][pion_col] = 3;
                }
            }
            else { // Touche entrée
                break;
            }
        }
    }
}
