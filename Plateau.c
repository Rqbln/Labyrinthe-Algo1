#include "sprog.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <fcntl.h>
#include <io.h>


void initialisationTableau(int tab[LARGEUR][LARGEUR]) {//sous programme pour les valeur du tableau
    int tmp;
    int fixe=0;
    int verifieur[34];
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
                    tmp = ((LARGEUR/2)+1)*((LARGEUR/2)+1) + rand() % 35;   //creation d une variable aleatoire
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
        }
    }
}
void init_case_en_plus(int tab[LARGEUR][LARGEUR],int *carterestante){

    int tmp;

    tmp=rand() % 7;
    srand(time(NULL));
    *carterestante=tab[3][tmp];
    tab[3][tmp]=49;
    if (*carterestante>15 && *carterestante<22){
        *carterestante=50 + rand() % 4;   //case en T avec tresor 50  X6

    }
    if (*carterestante>21 && *carterestante<28){
        *carterestante=60 + rand() % 4;   //case en L avec tresor 60  X6

    }
    if (*carterestante>27 && *carterestante<38){
        *carterestante=70 + rand() % 4;   //case en L classique 70 X10

    }
    if (*carterestante>37 && *carterestante<50){
        *carterestante=80 + rand() % 2;   //case en I classique 80  X12

    }
}
void convertab(int tab[LARGEUR][LARGEUR]){
    for (int i = 0; i < (LARGEUR); i++) {
        for (int j = 0; j < (LARGEUR); j++) {
            if (tab[i][j]>15 && tab[i][j]<23){
                tab[i][j]=50 + rand() % 4;   //case en T avec tresor 50

            }
            if (tab[i][j]>22 && tab[i][j]<28){
                tab[i][j]=60 + rand() % 4;   //case en L avec tresor 60

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
void coordonne(int tabfinal[21][21], int *x, int *y, int tab[LARGEUR][LARGEUR]){
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


    for (int i = 0; i < LARGEUR; ++i) {
        for (int j = 0; j < LARGEUR; ++j) {
            *x = i;
            *y = j ;
            int value = tab[i][j];
            if (value == 1 || value == 2 || value == 6 || value == 50){
                switch (value) {
                    case 1:
                        caseT1[1][1]=10;
                        break;
                    case 2:
                        caseT1[1][1]=11;
                        break;
                    case 6:
                        caseT1[1][1]=12;
                        break;
                    case 50:
                        caseT1[1][1]=13;
                        break;
                }
                affect(tabfinal, &i, &j, caseT1);
            }
            if (value == 7 || value == 10 || value == 11 || value == 51){
                switch (value) {
                    case 7:
                        caseT2[1][1]=14;
                        break;
                    case 10:
                        caseT2[1][1]=15;
                        break;
                    case 11:
                        caseT2[1][1]=16;
                        break;
                    case 51:
                        caseT2[1][1]=17;
                        break;
                }
                affect(tabfinal, &i ,&j, caseT2);
            }
            if (value == 9 || value == 13 || value == 14 || value == 52){
                switch (value) {
                    case 9:
                        caseT3[1][1]=18;
                        break;
                    case 13:
                        caseT3[1][1]=19;
                        break;
                    case 14:
                        caseT3[1][1]=20;
                        break;
                    case 52:
                        caseT3[1][1]=21;
                        break;
                }
                affect(tabfinal, &i, &j, caseT3);
            }
            if (value == 4 || value == 5 || value == 8 || value == 53){
                switch (value) {
                    case 4:
                        caseT4[1][1]=22;
                        break;
                    case 5:
                        caseT4[1][1]=23;
                        break;
                    case 8:
                        caseT4[1][1]=24;
                        break;
                    case 53:
                        caseT4[1][1]=25;
                        break;
                }
                affect(tabfinal, &i, &j, caseT4);
            }//tabfinal prend les cases T

            if (value == 70){
                affect(tabfinal, &i, &j, caseL1);
            }
            if (value == 71){
                affect(tabfinal, &i, &j, caseL2);
            }
            if (value == 72){
                affect(tabfinal, &i, &j, caseL3);
            }
            if (value == 73){
                affect(tabfinal, &i, &j, caseL4);
            }//tabfinal prend les cases L

            if (value == 12 || value == 60){
                switch (value) {
                    case 12:
                        caseLT1[1][1]=42;
                        break;
                    case 60:
                        caseLT1[1][1]=26;
                        break;
                }
                affect(tabfinal, &i, &j, caseLT1);
            }
            if (value == 0 || value == 61){
                switch (value) {
                    case 0:
                        caseLT2[1][1]=40;
                        break;
                    case 61:
                        caseLT2[1][1]=27;
                        break;
                }
                affect(tabfinal, &i, &j, caseLT2);
            }
            if (value == 3 || value == 62){
                switch (value) {
                    case 3:
                        caseLT3[1][1]=41;
                        break;
                    case 62:
                        caseLT3[1][1]=28;
                        break;
                }
                affect(tabfinal, &i, &j, caseLT3);
            }
            if (value == 15 || value == 63){
                switch (value) {
                    case 15:
                        caseLT4[1][1]=43;
                        break;
                    case 63:
                        caseLT4[1][1]=29;
                        break;
                }
                affect(tabfinal, &i, &j, caseLT4);
            }//tabfinal prend les cases L Tresor

            if (value == 80){
                affect(tabfinal, &i, &j, caseI1);
            }
            if (value == 81){
                affect(tabfinal, &i, &j, caseI2);
            }//tabfinal prend les cases I

        }
    }
}
void affect(int tabfinal[21][21], int *x, int *y, int cases[3][3]){  //tabfinal est le tableau qui rassemblera toutes les donnees
    tabfinal[*x*3][*y*3]=cases[0][0];
    tabfinal[*x*3][*y*3+1]=cases[0][1];
    tabfinal[*x*3][*y*3+2]=cases[0][2];
    tabfinal[*x*3+1][*y*3]=cases[1][0];
    tabfinal[*x*3+1][*y*3+1]=cases[1][1];
    tabfinal[*x*3+1][*y*3+2]=cases[1][2];
    tabfinal[*x*3+2][*y*3]=cases[2][0];
    tabfinal[*x*3+2][*y*3+1]=cases[2][1];
    tabfinal[*x*3+2][*y*3+2]=cases[2][2];
}
void afficheplateauprog(int tab[LARGEUR][LARGEUR], int tabfinal[21][21]) {                   //sous programme pour les afficher le tableau
    //int tab[10][10];
    for (int i = 0; i < (LARGEUR); i++) {
        for (int j = 0; j < (LARGEUR); j++) {
            printf("%d ", tab[i][j]); //affichage des valeur
        }
        printf("\n");

    }
    printf("\n");
    printf("\n");

}
void afficheplateaubinaire(int tab[LARGEUR][LARGEUR], int tabfinal[21][21]) {                   //sous programme pour les afficher le tableau

    for (int i = 0; i < (21); i++) {
        for (int j = 0; j < (21); j++) {
            printf("%d ", tabfinal[i][j]); //affichage des valeur
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");

}
void afficheplateaufinal(int tab[LARGEUR][LARGEUR], int tabfinal[21][21]) {                   //sous programme pour les afficher le tableau

    for (int i = 0; i < (21); i++) {
        for (int j = 0; j < (21); j++) {
            switch (tabfinal[i][j]) {
                case 0:
                    _setmode(_fileno(stdout), _O_U16TEXT);
                    wprintf(L"\x2588\x2588"); //affichage des valeur
                    break;
                case 1:
                    _setmode(_fileno(stdout), _O_U16TEXT);
                    wprintf(L"\x00A0\x00A0"); //affichage des valeur
                    break;
                case 10:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x0041"); //affichage des valeur
                    break;
                case 11:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x0042"); //affichage des valeur
                    break;
                case 12:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x0043"); //affichage des valeur
                    break;
                case 13:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x0044"); //affichage des valeur
                    break;
                case 14:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x0045"); //affichage des valeur
                    break;
                case 15:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x0046"); //affichage des valeur
                    break;
                case 16:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x0047"); //affichage des valeur
                    break;
                case 17:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x0048"); //affichage des valeur
                    break;
                case 18:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x0049"); //affichage des valeur
                    break;
                case 19:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x004A"); //affichage des valeur
                    break;
                case 20:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x004B"); //affichage des valeur
                    break;
                case 21:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x004C"); //affichage des valeur
                    break;
                case 22:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x004D"); //affichage des valeur
                    break;
                case 23:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x004E"); //affichage des valeur
                    break;
                case 24:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x004F"); //affichage des valeur
                    break;
                case 25:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x0050"); //affichage des valeur
                    break;
                case 26:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x0051"); //affichage des valeur
                    break;
                case 27:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x0052"); //affichage des valeur
                    break;
                case 28:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x0053"); //affichage des valeur
                    break;
                case 29:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x0054"); //affichage des valeur
                    break;
                case 40:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x2592\x2592"); //affichage des valeur
                    break;
                case 41:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x2592\x2592"); //affichage des valeur
                    break;
                case 42:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x2592\x2592"); //affichage des valeur
                    break;
                case 43:

                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x2592\x2592"); //affichage des valeur
                    break;

            }
            /*
            if (tabfinal[i][j]==0) {
                _setmode(_fileno(stdout), _O_U16TEXT);
                wprintf(L"\x2588\x2588"); //affichage des valeur
            }
            if (tabfinal[i][j]==1) {
                _setmode(_fileno(stdout), _O_U16TEXT);
                wprintf(L"\x00A0\x00A0"); //affichage des valeur
            }
            if (tabfinal[i][j]==8) {
                _setmode(_fileno(stdout), _O_U16TEXT);
                wprintf(L"\x0054\x0052"); //affichage des valeur
            }*/
        }
        _setmode(_fileno(stdout), _O_U16TEXT);
        wprintf(L"\n");
    }

    _setmode(_fileno(stdout), _O_TEXT);
}

void affiche_case_en_plus(int *carterestante) {
    //scanf("%d",&*carterestante);
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
    switch (*carterestante) {
        case 50:
            caseT1[1][1] = 13;
            break;
        case 51:
            caseT2[1][1] = 17;
            break;
        case 52:
            caseT3[1][1] = 21;
            break;
        case 53:
            caseT4[1][1] = 25;
            break;
        case 60:
            caseL1[1][1] = 27;
            break;
        case 61:
            caseLT2[1][1] = 29;
            break;
        case 62:
            caseLT3[1][1] = 31;
            break;
        case 63:
            caseLT4[1][1] = 33;
            break;
    }
    switch (*carterestante / 10) {
        case 5:
            switch (*carterestante % 10) {
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
            switch (*carterestante % 10) {
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
            switch (casefinal[i][j]) {
                case 0:
                    _setmode(_fileno(stdout), _O_U16TEXT);
                    wprintf(L"\x2588\x2588"); //affichage des valeur
                    break;
                case 1:
                    _setmode(_fileno(stdout), _O_U16TEXT);
                    wprintf(L"\x00A0\x00A0"); //affichage des valeur
                    break;

                case 13:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x0044"); //affichage des valeur
                    break;

                case 17:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x0048"); //affichage des valeur
                    break;

                case 21:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x004C"); //affichage des valeur
                    break;

                case 25:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x0050"); //affichage des valeur
                    break;

                case 27:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x0052"); //affichage des valeur
                    break;

                case 29:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x0054"); //affichage des valeur
                    break;

                case 31:
                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x0056"); //affichage des valeur
                    break;

                case 33:

                    _setmode(_fileno(stdout), _O_U16TEXT);

                    wprintf(L"\x0054\x0058"); //affichage des valeur
                    break;

            }

        }
        _setmode(_fileno(stdout), _O_U16TEXT);
        wprintf(L"\n");
        _setmode(_fileno(stdout), _O_TEXT);

    }
}