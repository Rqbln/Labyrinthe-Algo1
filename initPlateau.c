#include "sprog.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void initialisationTableau(int tab[7][7]) {//sous programme pour les valeur du tableau
    int tmp;
    int fixe=1;
    int verifieur[34];
    srand(time(NULL));            //creation de du module aleatoire en fonction du temps
    //int tab[7][7];                       //creation de la variable/tableau
    //int tmp;
    //int result[26];
    //for(int i = 0; i < 26; i++) {
    //   result[i] = 0;
    //}
    for (int i = 0; i<(7);i++){              //lignes
        for (int j = 0; j<(7);j++){          //colones
            //printf("entrez valeur:");       //demande a l'utilisateur d entrer une valeur//scanf("%f",&tab[i][j]);  //entrée utilisateur
            if(i%2==0 && j%2==0){
                tab[i][j]=fixe;
                fixe+=1;
            }
            else{
                int p=0;
                int verif=1;
                for(int v; v<34;v++){
                    verif = 0;
                    tmp = 20 + rand() % 53;   //creation d une variable aleatoire
                    do {
                        verifieur[v] = tmp;
                        for (int l = 0; l < (p); l++) {

                            if (verifieur[l] == tmp) {
                                verif = 1;
                            }
                        }
                        p+=1;
                    }
                    while(verif==1);
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
