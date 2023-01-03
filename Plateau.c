// plateau.c
#include "sprog.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <io.h>


void initialisationTableau(int tab[LARGEUR][LARGEUR]) {//sous programme pour les valeur du tableau
    int tmp;
    int fixe=0;
    int verifieur[33];
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
                    tmp = ((LARGEUR/2)+1)*((LARGEUR/2)+1) + rand() % 33;   //creation d une variable aleatoire
                    for (int l = 0; l < 33; l++) {

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
void init_case_en_plus(int tab[LARGEUR][LARGEUR],int *carterestante, int *test_tresor){
    int tmp;

    tmp=rand() % 7;
    srand(time(NULL));
    *carterestante=tab[3][tmp];
    tab[3][tmp]=49;
    if (*carterestante>15 && *carterestante<22){
        *carterestante=(50 + rand() % 4)*10+5;   //case en T avec tresor 50  X6
        *test_tresor+=1;
    }
    if (*carterestante>21 && *carterestante<28){
        *carterestante=(60 + rand() % 4)*10+5;   //case en L avec tresor 60  X6
        *test_tresor+=1;
    }
    if (*carterestante>27 && *carterestante<38){
        *carterestante=70 + rand() % 4;   //case en L classique 70 X10

    }
    if (*carterestante>37 && *carterestante<50){
        *carterestante=80 + rand() % 2;   //case en I classique 80  X12

    }
}
void convertab(int tab[LARGEUR][LARGEUR], int *test_tresor){
    int cinquante=0;
    int soixante=0;
    for (int i = 0; i < (LARGEUR); i++) {
        for (int j = 0; j < (LARGEUR); j++) {
            if (tab[i][j]>15 && tab[i][j]<22){
                tab[i][j]=(50 + rand() % 4)*10+cinquante;   //case en T avec tresor 50
                cinquante+=1;
                *test_tresor+=1;
            }
            if (tab[i][j]>21 && tab[i][j]<28){
                tab[i][j]=(60 + rand() % 4)*10+soixante;   //case en L avec tresor 60
                soixante+=1;
                *test_tresor+=1;
            }
            if (tab[i][j]>27 && tab[i][j]<38){
                tab[i][j]=70 + rand() % 4;   //case en L classique 70

            }
            if (tab[i][j]>37 && tab[i][j]<50){
                tab[i][j]=80 + rand() % 2;   //case en I classique 80

            }
            // de 0 a 15 cases fixes
        }
    }
}
void coordonne(int tabfinal[LARGEUR_FINALE][LARGEUR_FINALE], int *x, int *y, int tab[LARGEUR][LARGEUR]){
    //on definit toutes les cases differente
    int caseT1[3][3] = {0,0,0, 1,8,1, 0,1,0}; //https://i.imgur.com/aXB8t7o.png
    int caseT2[3][3] = {0,1,0, 1,8,0, 0,1,0};
    int caseT3[3][3] = {0,1,0, 1,8,1, 0,0,0};
    int caseT4[3][3] = {0,1,0, 0,8,1, 0,1,0};
    int caseL1[3][3] = {0,1,0, 0,1,1, 0,0,0}; //https://i.imgur.com/Vn94Xo6.png
    int caseL2[3][3] = {0,0,0, 0,1,1, 0,1,0};
    int caseL3[3][3] = {0,0,0, 1,1,0, 0,1,0};
    int caseL4[3][3] = {0,1,0, 1,1,0, 0,0,0};
    int caseLT1[3][3] = {0,1,0, 0,8,1, 0,0,0}; //https://i.imgur.com/u5g71NJ.png
    int caseLT2[3][3] = {0,0,0, 0,8,1, 0,1,0};
    int caseLT3[3][3] = {0,0,0, 1,8,0, 0,1,0};
    int caseLT4[3][3] = {0,1,0, 1,8,0, 0,0,0};
    int caseI1[3][3] = {0,1,0, 0,1,0, 0,1,0};
    int caseI2[3][3] = {0,0,0, 1,1,1, 0,0,0};
    for (int i = 0; i < LARGEUR_FINALE; ++i) {
        for (int j = 0; j < LARGEUR_FINALE; ++j) {
            tabfinal[i][j]=9;
        }
    }

    for (int i = 0; i < LARGEUR; ++i) {
        for (int j = 0; j < LARGEUR; ++j) {
            //*x = i;
            //*y = j ;
            int value = tab[i][j];
            switch (value) {
                case 0:
                    caseLT2[1][1] = 40;   //coin
                    affect(tabfinal, &i, &j, caseLT2);
                    break;
                case 1:
                    caseT1[1][1] = 10;
                    affect(tabfinal, &i, &j, caseT1);
                    break;
                case 2:
                    caseT1[1][1] = 11;
                    affect(tabfinal, &i, &j, caseT1);
                    break;
                case 3:
                    caseLT3[1][1] = 41;   //coin
                    affect(tabfinal, &i, &j, caseLT3);
                    break;
                case 4:
                    caseT4[1][1] = 12;
                    affect(tabfinal, &i, &j, caseT4);
                    break;
                case 5:
                    caseT4[1][1] = 13;
                    affect(tabfinal, &i, &j, caseT4);
                    break;
                case 6:
                    caseT1[1][1] = 14;
                    affect(tabfinal, &i, &j, caseT1);
                    break;
                case 7:
                    caseT2[1][1] = 15;
                    affect(tabfinal, &i, &j, caseT2);
                    break;
                case 8:
                    caseT4[1][1] = 16;
                    affect(tabfinal, &i, &j, caseT4);
                    break;
                case 9:
                    caseT3[1][1] = 17;
                    affect(tabfinal, &i, &j, caseT3);
                    break;
                case 10:
                    caseT2[1][1] = 18;
                    affect(tabfinal, &i, &j, caseT2);
                    break;
                case 11:
                    caseT2[1][1] = 19;
                    affect(tabfinal, &i, &j, caseT2);
                    break;
                case 12:
                    caseLT1[1][1] = 42;   //coin
                    affect(tabfinal, &i, &j, caseLT1);
                    break;
                case 13:
                    caseT3[1][1] = 20;
                    affect(tabfinal, &i, &j, caseT3);
                    break;
                case 14:
                    caseT3[1][1] = 21;
                    affect(tabfinal, &i, &j, caseT3);
                    break;
                case 15:
                    caseLT4[1][1] = 43;   //coin
                    affect(tabfinal, &i, &j, caseLT4);
                    break;
                case 70:
                    affect(tabfinal, &i, &j, caseL1);
                    break;
                case 71:
                    affect(tabfinal, &i, &j, caseL2);
                    break;
                case 72:
                    affect(tabfinal, &i, &j, caseL3);
                    break;
                case 73:
                    affect(tabfinal, &i, &j, caseL4);
                    break;
                case 80:
                    affect(tabfinal, &i, &j, caseI1);
                    break;
                case 81:
                    affect(tabfinal, &i, &j, caseI2);
                    break;
            }
            switch (value/10) {
                case 50:
                    caseT1[1][1] = 22+(value%50);
                    affect(tabfinal, &i, &j, caseT1);
                    break;
                case 51:
                    caseT2[1][1] = 22+(value%51);
                    affect(tabfinal, &i, &j, caseT2);
                    break;
                case 52:
                    caseT3[1][1] = 22+(value%52);
                    affect(tabfinal, &i, &j, caseT3);
                    break;
                case 53:
                    caseT4[1][1] = 22+(value%53);
                    affect(tabfinal, &i, &j, caseT4);
                    break;
                case 60:
                    caseLT1[1][1] = 28+(value%60);
                    affect(tabfinal, &i, &j, caseLT1);
                    break;
                case 61:
                    caseLT2[1][1] = 28+(value%61);
                    affect(tabfinal, &i, &j, caseLT2);
                    break;
                case 62:
                    caseLT3[1][1] = 28+(value%62);
                    affect(tabfinal, &i, &j, caseLT3);
                    break;
                case 63:
                    caseLT4[1][1] = 28+(value%63);
                    affect(tabfinal, &i, &j, caseLT4);
                    break;

            }
        }
    }
}
void affect(int tabfinal[LARGEUR_FINALE][LARGEUR_FINALE], int *x, int *y, int cases[3][3]){  //tabfinal est le tableau qui rassemblera toutes les donnees
    tabfinal[(*x*3)+1][(*y*3)+1]=cases[0][0];
    tabfinal[(*x*3)+1][(*y*3)+1+1]=cases[0][1];
    tabfinal[(*x*3)+1][(*y*3)+1+2]=cases[0][2];
    tabfinal[(*x*3)+1+1][(*y*3)+1]=cases[1][0];
    tabfinal[(*x*3)+1+1][(*y*3)+1+1]=cases[1][1];
    tabfinal[(*x*3)+1+1][(*y*3)+1+2]=cases[1][2];
    tabfinal[(*x*3)+1+2][(*y*3)+1]=cases[2][0];
    tabfinal[(*x*3)+1+2][(*y*3)+1+1]=cases[2][1];
    tabfinal[(*x*3)+1+2][(*y*3)+1+2]=cases[2][2];
}
void afficheplateauprog(int tab[LARGEUR][LARGEUR], int tabfinal[LARGEUR_FINALE][LARGEUR_FINALE]) {                   //sous programme pour les afficher le tableau
    //int tab[10][10];
    for (int i = 0; i < (LARGEUR); i++) {
        for (int j = 0; j < (LARGEUR); j++) {
            printf("%d ", tab[i][j]); //affichage des valeurs
        }
        printf("\n");

    }
    printf("\n");
    printf("\n");

}
void afficheplateaubinaire(int tab[LARGEUR][LARGEUR], int tabfinal[LARGEUR_FINALE][LARGEUR_FINALE]) {                   //sous programme pour les afficher le tableau

    for (int i = 0; i < (LARGEUR_FINALE); i++) {
        for (int j = 0; j < (LARGEUR_FINALE); j++) {
            printf("%d ", tabfinal[i][j]); //affichage des valeurs
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");

}
void afficheplateaufinal(int tab[LARGEUR][LARGEUR], int tabfinal[LARGEUR_FINALE][LARGEUR_FINALE]) {                   //sous programme pour les afficher le tableau
    int caracteres;
    for (int i = 0; i < (LARGEUR_FINALE); i++) {
        for (int j = 0; j < (LARGEUR_FINALE); j++) {
            caracteres=tabfinal[i][j];
            caractere(&caracteres);
            /*
            if (tabfinal[i][j]==0) {
                _setmode(_fileno(stdout), _O_U16TEXT);
                wprintf(L"\x2588\x2588"); //affichage des valeurs
            }
            if (tabfinal[i][j]==1) {
                _setmode(_fileno(stdout), _O_U16TEXT);
                wprintf(L"\x00A0\x00A0"); //affichage des valeurs
            }
            if (tabfinal[i][j]==8) {
                _setmode(_fileno(stdout), _O_U16TEXT);
                wprintf(L"\x0054\x0052"); //affichage des valeurs
            }*/
        }
        _setmode(_fileno(stdout), _O_U16TEXT);
        wprintf(L"\n");
    }

    _setmode(_fileno(stdout), _O_TEXT);
}

void affiche_case_en_plus(int *carterestante) {
    int caracteres;
    //scanf("%d",&*carterestante);
    printf("Tuile supplementaire :\n");
    int caseT1[3][3] = {0, 0, 0, 1, 8, 1, 0, 1, 0}; //https://i.imgur.com/aXB8t7o.png
    int caseT2[3][3] = {0, 1, 0, 1, 8, 0, 0, 1, 0};
    int caseT3[3][3] = {0, 1, 0, 1, 8, 1, 0, 0, 0};
    int caseT4[3][3] = {0, 1, 0, 0, 8, 1, 0, 1, 0};
    int caseL1[3][3] = {0, 1, 0, 0, 1, 1, 0, 0, 0}; //https://i.imgur.com/Vn94Xo6.png
    int caseL2[3][3] = {0, 0, 0, 0, 1, 1, 0, 1, 0};
    int caseL3[3][3] = {0, 0, 0, 1, 1, 0, 0, 1, 0};
    int caseL4[3][3] = {0, 1, 0, 1, 1, 0, 0, 0, 0};
    int caseLT1[3][3] = {0, 1, 0, 0, 8, 1, 0, 0, 0}; //https://i.imgur.com/u5g71NJ.png
    int caseLT2[3][3] = {0, 0, 0, 0, 8, 1, 0, 1, 0};
    int caseLT3[3][3] = {0, 0, 0, 1, 8, 0, 0, 1, 0};
    int caseLT4[3][3] = {0, 1, 0, 1, 8, 0, 0, 0, 0};
    int caseI1[3][3] = {0, 1, 0, 0, 1, 0, 0, 1, 0};
    int caseI2[3][3] = {0, 0, 0, 1, 1, 1, 0, 0, 0};
    int casefinal[3][3];
    switch (*carterestante/10) {
        case 50:
            caseT1[1][1] = 22+(*carterestante%50);
            break;
        case 51:
            caseT2[1][1] = 22+(*carterestante%51);
            break;
        case 52:
            caseT3[1][1] = 22+(*carterestante%52);
            break;
        case 53:
            caseT4[1][1] = 22+(*carterestante%53);
            break;
        case 60:
            caseLT1[1][1] = 28+(*carterestante%60);
            break;
        case 61:
            caseLT2[1][1] = 28+(*carterestante%61);
            break;
        case 62:
            caseLT3[1][1] = 28+(*carterestante%62);
            break;
        case 63:
            caseLT4[1][1] = 28+(*carterestante%63);
            break;

    }
    switch (*carterestante / 100) {
        case 5:
            switch ((*carterestante / 10) % 10) {
                case 0:
                    for (int i = 0; i < 3; ++i) {
                        for (int j = 0; j < 3; ++j) {
                            casefinal[i][j] = caseT1[i][j];
                        }
                    }
                    break;
                case 1:
                    for (int i = 0; i < 3; ++i) {
                        for (int j = 0; j < 3; ++j) {
                            casefinal[i][j] = caseT2[i][j];
                        }
                    }
                    break;
                case 2:
                    for (int i = 0; i < 3; ++i) {
                        for (int j = 0; j < 3; ++j) {
                            casefinal[i][j] = caseT3[i][j];
                        }
                    }
                    break;
                case 3:
                    for (int i = 0; i < 3; ++i) {
                        for (int j = 0; j < 3; ++j) {
                            casefinal[i][j] = caseT4[i][j];
                        }
                    }
                    break;
            }

            break;
        case 6:
            switch ((*carterestante / 10) % 10) {
                case 0:
                    for (int i = 0; i < 3; ++i) {
                        for (int j = 0; j < 3; ++j) {
                            casefinal[i][j] = caseLT1[i][j];
                        }
                    }
                    break;
                case 1:
                    for (int i = 0; i < 3; ++i) {
                        for (int j = 0; j < 3; ++j) {
                            casefinal[i][j] = caseLT2[i][j];
                        }
                    }
                    break;
                case 2:
                    for (int i = 0; i < 3; ++i) {
                        for (int j = 0; j < 3; ++j) {
                            casefinal[i][j] = caseLT3[i][j];
                        }
                    }
                    break;
                case 3:
                    for (int i = 0; i < 3; ++i) {
                        for (int j = 0; j < 3; ++j) {
                            casefinal[i][j] = caseLT4[i][j];
                        }
                    }
                    break;
            }
            break;
    }
    switch (*carterestante/10) {
        case 7:
            switch (*carterestante % 10) {
                case 0:
                    for (int i = 0; i < 3; ++i) {
                        for (int j = 0; j < 3; ++j) {
                            casefinal[i][j] = caseL1[i][j];
                        }
                    }
                    break;
                case 1:
                    for (int i = 0; i < 3; ++i) {
                        for (int j = 0; j < 3; ++j) {
                            casefinal[i][j] = caseL2[i][j];
                        }
                    }
                    break;
                case 2:
                    for (int i = 0; i < 3; ++i) {
                        for (int j = 0; j < 3; ++j) {
                            casefinal[i][j] = caseL3[i][j];
                        }
                    }
                    break;
                case 3:
                    for (int i = 0; i < 3; ++i) {
                        for (int j = 0; j < 3; ++j) {
                            casefinal[i][j] = caseL4[i][j];
                        }
                    }
                    break;
            }
            break;
        case 8:
            switch (*carterestante % 10) {
                case 0:
                    for (int i = 0; i < 3; ++i) {
                        for (int j = 0; j < 3; ++j) {
                            casefinal[i][j] = caseI1[i][j];
                        }
                    }
                    break;
                case 1:
                    for (int i = 0; i < 3; ++i) {
                        for (int j = 0; j < 3; ++j) {
                            casefinal[i][j] = caseI2[i][j];
                        }
                    }
                    break;
            }
            break;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            caracteres=casefinal[i][j];
            caractere(&caracteres);

        }
        _setmode(_fileno(stdout), _O_U16TEXT);
        wprintf(L"\n");
        _setmode(_fileno(stdout), _O_TEXT);

    }
}

