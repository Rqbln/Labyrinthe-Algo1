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

void initialisationTableau(int tab[LARGEUR][LARGEUR]) {//sous programme pour les valeur du tableau
    int tmp;
    int fixe=0;
    int verifieur[34];
    int p=0;
    srand(time(NULL));            //creation de du module aleatoire en fonction du temps
    //int tab[7][7];                       //creation de la variable/tableau
    //int tmp;
    //int result[26];
    //for(int i = 0; i < 26; i++) {
    //   result[i] = 0;
    //}
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
            //for (int y = 0; y < 26; y++) {
            //    if (tmp == (y + 97)) {
            //        result[y] += 1;         //affichage des valeur
            //    }
            //}
        }

    }
    //for(int i = 0; i < 26; i++){
    //    printf("%d\n",result[i]);
    //}
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
    }}

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
