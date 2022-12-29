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
    color(13,0);
    wprintf(L"\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\n");
    color(15,0);
    _setmode(_fileno(stdout), _O_TEXT);
}
void afficherRegles(){
    color(15,0);
    printf("Regles du jeu de societe Labyrinthe:\n\n");
    printf("Le but du jeu est d'etre le premier a trouver la sortie du labyrinthe avec son pion.\n");
    printf("Pour se deplacer, les joueurs tirent un de et avancent leur pion du nombre de cases correspondant.\n");
    printf("Si un joueur tombe sur une case avec un objet, il peut le prendre et le garder jusqu'a ce qu'il en ait besoin ou decider de le donner a un autre joueur.\n");
    printf("Les objets peuvent etre utilises pour ouvrir des portes ou des passages secrets, ou pour deplacer des obstacles dans le labyrinthe.\n");
    printf("Le premier joueur a sortir du labyrinthe est declare vainqueur.\n");
}
void caractere(int *caracteres){
    switch (*caracteres) {
        case 0:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(2,2);
            wprintf(L"\x2588\x2588"); //affichage des valeurs
            color(15,0);
            break;
        case 1:
            _setmode(_fileno(stdout), _O_U16TEXT);
            wprintf(L"\x00A0\x00A0"); //affichage des valeurs
            break;
        case 3:
            _setmode(_fileno(stdout), _O_U16TEXT);
            wprintf(L"\x00AE\x00A0"); //affichage des valeurs
            break;
        case 10:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(6,0);
            wprintf(L"\x0054\x0041"); //affichage des valeurs   A
            color(15,0);
            break;
        case 11:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(6,0);

            wprintf(L"\x0054\x0042"); //affichage des valeurs   B
            color (15,0);
            break;
        case 12:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(6,0);

            wprintf(L"\x0054\x0043"); //affichage des valeurs   C
            color (15,0);
            break;
        case 13:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(6,0);

            wprintf(L"\x0054\x0044"); //affichage des valeurs   D
            color (15,0);
            break;
        case 14:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(6,0);

            wprintf(L"\x0054\x0045"); //affichage des valeurs   E
            color (15,0);
            break;
        case 15:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(6,0);

            wprintf(L"\x0054\x0046"); //affichage des valeurs   F
            color (15,0);
            break;
        case 16:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(6,0);

            wprintf(L"\x0054\x0047"); //affichage des valeurs   G
            color (15,0);
            break;
        case 17:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(6,0);

            wprintf(L"\x0054\x0048"); //affichage des valeurs   H
            color (15,0);
            break;
        case 18:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(6,0);

            wprintf(L"\x0054\x0049"); //affichage des valeurs   I
            color (15,0);
            break;
        case 19:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(6,0);

            wprintf(L"\x0054\x004A"); //affichage des valeurs   J
            color (15,0);
            break;
        case 20:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(6,0);

            wprintf(L"\x0054\x004B"); //affichage des valeurs   K
            color (15,0);
            break;
        case 21:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(6,0);

            wprintf(L"\x0054\x004C"); //affichage des valeurs   L
            color (15,0);
            break;
        case 22:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(6,0);

            wprintf(L"\x0054\x004D"); //affichage des valeurs   M
            color (15,0);
            break;
        case 23:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(6,0);

            wprintf(L"\x0054\x004E"); //affichage des valeurs   N
            color (15,0);
            break;
        case 24:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(6,0);

            wprintf(L"\x0054\x004F"); //affichage des valeurs   O
            color (15,0);
            break;
        case 25:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(6,0);

            wprintf(L"\x0054\x0050"); //affichage des valeurs   P
            color (15,0);
            break;
        case 26:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(6,0);

            wprintf(L"\x0054\x0051"); //affichage des valeurs   Q
            color (15,0);
            break;
        case 27:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(6,0);

            wprintf(L"\x0054\x0052"); //affichage des valeurs   R
            color (15,0);
            break;
        case 28:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(6,0);

            wprintf(L"\x0054\x0053"); //affichage des valeurs   S
            color (15,0);
            break;
        case 29:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(6,0);

            wprintf(L"\x0054\x0054"); //affichage des valeurs   T
            color (15,0);
            break;
        case 30:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(6,0);

            wprintf(L"\x0054\x0055"); //affichage des valeurs   U
            color (15,0);
            break;
        case 31:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(6,0);

            wprintf(L"\x0054\x0056"); //affichage des valeurs   V
            color (15,0);
            break;
        case 32:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(6,0);

            wprintf(L"\x0054\x0057"); //affichage des valeurs   W
            color (15,0);
            break;
        case 33:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(6,0);

            wprintf(L"\x0054\x0058"); //affichage des valeurs   X
            color (15,0);
            break;
        case 40:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(9,0);
            wprintf(L"\x2592\x2592"); //affichage des valeurs   COIN HG
            color (15,0);
            break;
        case 41:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color (12,0);
            wprintf(L"\x2592\x2592"); //affichage des valeurs   COIN HD
            color (15,0);
            break;
        case 42:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(10,0);
            wprintf(L"\x2592\x2592"); //affichage des valeurs   COIN BG
            color (15,0);
            break;
        case 43:

            _setmode(_fileno(stdout), _O_U16TEXT);
            color(5,0);
            wprintf(L"\x2592\x2592"); //affichage des valeurs   COIN BD
            color (15,0);
            break;
}}