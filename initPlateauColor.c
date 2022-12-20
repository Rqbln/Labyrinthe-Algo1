#include "sprog.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

static int __BACKGROUND = BLACK;
static int __FOREGROUND = WHITE;
void text_color(int color)
{
    __FOREGROUND=color;
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,__FOREGROUND+(__BACKGROUND << 4));
}
//change la couleur de fond
void bg_color(int color){
    __BACKGROUND=color;
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,__FOREGROUND+(__BACKGROUND << 4));
}
//change la couleur du texte et du fond

void afficherTerrain4(int tab[LARGEUR][LARGEUR], int taille){
    int i,j;
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
        for(j=0;j<taille;j++){
            if(tab[i][j] == 0){
                bg_color(RED);
                printf(" %2c  ",' ');
                bg_color(WHITE);
            }
            if(tab[i][j] == 1){
                bg_color(GREEN);
                printf(" %2c  ",' ');
                bg_color(WHITE);
            }
            if(tab[i][j] == 2){
                bg_color(BLUE);
                printf(" %2c  ",' ');
                bg_color(WHITE);
            }
            if(tab[i][j] == 3){
                bg_color(LIGHTBLUE);
                printf(" %2c  ",' ');
                bg_color(WHITE);
            }
            if(tab[i][j] == 4){
                bg_color(LIGHTBLUE);
                printf(" %2c  ",' ');
                bg_color(WHITE);
            }
            if(tab[i][j] == 5){
                bg_color(LIGHTBLUE);
                printf(" %2c  ",' ');
                bg_color(WHITE);
            }
            if(tab[i][j] == 6){
                bg_color(LIGHTBLUE);
                printf(" %2c  ",' ');
                bg_color(WHITE);
            }
            if(tab[i][j] == 7){
                bg_color(LIGHTBLUE);
                printf(" %2c  ",' ');
                bg_color(WHITE);
            }
            if(tab[i][j] == 8){
                bg_color(LIGHTBLUE);
                printf(" %2c  ",' ');
                bg_color(WHITE);
            }
            if(tab[i][j] == 9){
                bg_color(LIGHTBLUE);
                printf(" %2c  ",' ');
                bg_color(WHITE);
            }
            if(tab[i][j] == 10){
                bg_color(LIGHTBLUE);
                printf(" %2c  ",' ');
                bg_color(WHITE);
            }
            if(tab[i][j] == 11){
                bg_color(LIGHTBLUE);
                printf(" %2c  ",' ');
                bg_color(WHITE);
            }
            if(tab[i][j] == 12){
                bg_color(LIGHTBLUE);
                printf(" %2c  ",' ');
                bg_color(WHITE);
            }
            if(tab[i][j] == 13){
                bg_color(LIGHTBLUE);
                printf(" %2c  ",' ');
                bg_color(WHITE);
            }
            text_color(WHITE);
        }
        bg_color(BLACK);
        printf("\n");
    }
}
