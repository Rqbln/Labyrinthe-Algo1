// sprog.c
// Created by bapti on 30/11/2022.
//
#include "sprog.h"


void afficherTitre (){
    _setmode(_fileno(stdout), _O_U16TEXT);
    color(13,0);
    wprintf(L"\x2660\x0020\x2663\x0020\x2665\x0020\x2666\x0020\x2660\x0020\x2663\x0020\x2665\x0020\x2666\x0020\x2660\x0020\x2663\x0020\x2665\x0020\x2666\x0020\x2660\x0020\x2663\x0020\x2665\x0020\x2666\x0020\x2660\x0020\x2663\x0020\x2665\x0020\x2666\x0020\x2660\x0020\x2663\x0020\x2665\x0020\x2666\x0020\x2660\x0020\x2663\x0020\x2665\x0020\x2666\x0020\x2660\x0020\x2663\x0020\x2665\x0020\x2666\x0020\x2660\x0020\x2663\x0020\x2665\x0020\x2666\x0020\x2660\x0020\x2663\x0020\x2665\x0020\x2666\x0020\x2660\x0020\x2663\n");
    color(5,0);
    wprintf(L"\x2660\x0020\x2588\x2588\x2557\x0020\x0020\x0020\x0020\x0020\x0020\x2588\x2588\x2588\x2588\x2588\x2557\x0020\x2588\x2588\x2588\x2588\x2588\x2588\x2557\x0020\x2588\x2588\x2557\x0020\x0020\x0020\x2588\x2588\x2557\x2588\x2588\x2588\x2588\x2588\x2588\x2557\x0020\x2588\x2588\x2557\x2588\x2588\x2588\x2557\x0020\x0020\x0020\x2588\x2588\x2557\x2588\x2588\x2588\x2588\x2588\x2588\x2588\x2588\x2557\x2588\x2588\x2557\x0020\x0020\x2588\x2588\x2557\x2588\x2588\x2588\x2588\x2588\x2588\x2588\x2557\x0020\x2660\n");
    color(13,0);
    wprintf(L"\x2663\x0020\x2588\x2588\x2551\x0020\x0020\x0020\x0020\x0020\x2588\x2588\x2554\x2550\x2550\x2588\x2588\x2557\x2588\x2588\x2554\x2550\x2550\x2588\x2588\x2557\x255a\x2588\x2588\x2557\x0020\x2588\x2588\x2554\x255d\x2588\x2588\x2554\x2550\x2550\x2588\x2588\x2557\x2588\x2588\x2551\x2588\x2588\x2588\x2588\x2557\x0020\x0020\x2588\x2588\x2551\x255a\x2550\x2550\x2588\x2588\x2554\x2550\x2550\x255d\x2588\x2588\x2551\x0020\x0020\x2588\x2588\x2551\x2588\x2588\x2554\x2550\x2550\x2550\x2550\x255d\x0020\x2663\n");
    color(5,0);
    wprintf(L"\x2665\x0020\x2588\x2588\x2551\x0020\x0020\x0020\x0020\x0020\x2588\x2588\x2588\x2588\x2588\x2588\x2588\x2551\x2588\x2588\x2588\x2588\x2588\x2588\x2554\x255d\x0020\x255a\x2588\x2588\x2588\x2588\x2554\x255d\x0020\x2588\x2588\x2588\x2588\x2588\x2588\x2554\x255d\x2588\x2588\x2551\x2588\x2588\x2554\x2588\x2588\x2557\x0020\x2588\x2588\x2551\x0020\x0020\x0020\x2588\x2588\x2551\x0020\x0020\x0020\x2588\x2588\x2588\x2588\x2588\x2588\x2588\x2551\x2588\x2588\x2588\x2588\x2588\x2557\x0020\x0020\x0020\x2665\n");
    color(13,0);
    wprintf(L"\x2666\x0020\x2588\x2588\x2551\x0020\x0020\x0020\x0020\x0020\x2588\x2588\x2554\x2550\x2550\x2588\x2588\x2551\x2588\x2588\x2554\x2550\x2550\x2588\x2588\x2557\x0020\x0020\x255a\x2588\x2588\x2554\x255d\x0020\x0020\x2588\x2588\x2554\x2550\x2550\x2588\x2588\x2557\x2588\x2588\x2551\x2588\x2588\x2551\x255a\x2588\x2588\x2557\x2588\x2588\x2551\x0020\x0020\x0020\x2588\x2588\x2551\x0020\x0020\x0020\x2588\x2588\x2554\x2550\x2550\x2588\x2588\x2551\x2588\x2588\x2554\x2550\x2550\x255d\x0020\x0020\x0020\x2666\n");
    color(5,0);
    wprintf(L"\x2660\x0020\x2588\x2588\x2588\x2588\x2588\x2588\x2588\x2557\x2588\x2588\x2551\x0020\x0020\x2588\x2588\x2551\x2588\x2588\x2588\x2588\x2588\x2588\x2554\x255d\x0020\x0020\x0020\x2588\x2588\x2551\x0020\x0020\x0020\x2588\x2588\x2551\x0020\x0020\x2588\x2588\x2551\x2588\x2588\x2551\x2588\x2588\x2551\x0020\x255a\x2588\x2588\x2588\x2588\x2551\x0020\x0020\x0020\x2588\x2588\x2551\x0020\x0020\x0020\x2588\x2588\x2551\x0020\x0020\x2588\x2588\x2551\x2588\x2588\x2588\x2588\x2588\x2588\x2588\x2557\x0020\x2660\n");
    color(13,0);
    wprintf(L"\x2663\x0020\x255a\x2550\x2550\x2550\x2550\x2550\x2550\x255d\x255a\x2550\x255d\x0020\x0020\x255a\x2550\x255d\x255a\x2550\x2550\x2550\x2550\x2550\x255d\x0020\x0020\x0020\x0020\x255a\x2550\x255d\x0020\x0020\x0020\x255a\x2550\x255d\x0020\x0020\x255a\x2550\x255d\x255a\x2550\x255d\x255a\x2550\x255d\x0020\x0020\x255a\x2550\x2550\x2550\x255d\x0020\x0020\x0020\x255a\x2550\x255d\x0020\x0020\x0020\x255a\x2550\x255d\x0020\x0020\x255a\x2550\x255d\x255a\x2550\x2550\x2550\x2550\x2550\x2550\x255d\x0020\x2663\n");
    color(5,0);
    wprintf(L"\x2660\x0020\x2663\x0020\x2665\x0020\x2666\x0020\x2660\x0020\x2663\x0020\x2665\x0020\x2666\x0020\x2660\x0020\x2663\x0020\x2665\x0020\x2666\x0020\x2660\x0020\x2663\x0020\x2665\x0020\x2666\x0020\x2660\x0020\x2663\x0020\x2665\x0020\x2666\x0020\x2660\x0020\x2663\x0020\x2665\x0020\x2666\x0020\x2660\x0020\x2663\x0020\x2665\x0020\x2666\x0020\x2660\x0020\x2663\x0020\x2665\x0020\x2666\x0020\x2660\x0020\x2663\x0020\x2665\x0020\x2666\x0020\x2660\x0020\x2663\x0020\x2665\x0020\x2666\x0020\x2660\x0020\x2663\n");
    _setmode(_fileno(stdout), _O_TEXT);
    printf("Theme Alice au Pays des Merveilles\n");
    color(15,0);
}

void nouvellePartie(int tab[LARGEUR][LARGEUR], char buffer[BUFFER_SIZE], int *x, int *y, int *nbJoueurs, int pionsJoueurs[4], char nomJoueurs[4][LONGUEUR_NOM], char choix[BUFFER_SIZE], int *choix0, int *nbCartesJoueurs, int cartesJoueurs[CARTES][CARTES], int tabfinal[LARGEUR_FINALE][LARGEUR_FINALE], int *partie, int sauvegarde1tab[LARGEUR][LARGEUR], int *sauvegardetourjoueur, int *numjoueur, int *echap, int *carterestante, int *test_tresor, int memoricase[4], int *fin, int cartejoueurtab[4], int *tourJoueur, int *nbTours, int *verifTours, int *ligne_ou_colonne, int *numero_ligne_colonne, int *direction, int *cartejoueur1, int *cartejoueur2, int *cartejoueur3, int *cartejoueur4,int posxy[4][2]) {
//Remise à zéro de toutes les valeurs
    *x = 0;
    *y = 0;
    *nbJoueurs = 0;
    *choix0 = 0;
    *nbCartesJoueurs = 0;
    *partie = 0;
    *sauvegardetourjoueur = 0;
    *numjoueur = 1;
    *echap = 0;
    *carterestante = 0;
    *test_tresor = 0;
    *fin = 0;
    *tourJoueur = 0;
    *nbTours = 1;
    *verifTours = 0;
    *ligne_ou_colonne = 0;
    *numero_ligne_colonne = 0;
    *direction = 0;
    *cartejoueur1 = 0;
    *cartejoueur2 = 0;
    *cartejoueur3 = 0;
    *cartejoueur4 = 0;
    memset(buffer, 0, BUFFER_SIZE);
    memset(choix, 0, BUFFER_SIZE);
    memset(tab, 0, LARGEUR * LARGEUR * sizeof(int));
    memset(tabfinal, 0, LARGEUR_FINALE * LARGEUR_FINALE * sizeof(int));
    memset(sauvegarde1tab, 0, LARGEUR * LARGEUR * sizeof(int));
    memset(pionsJoueurs, 0, 4 * sizeof(int));
    memset(nomJoueurs, 0, 4 * LONGUEUR_NOM * sizeof(char));
    memset(cartesJoueurs, 0, CARTES * CARTES * sizeof(int));
    memset(cartejoueurtab, 0, 4 * sizeof(int));
    memset(memoricase, 0, 4 * sizeof(int));
    for (int i = 0; i < 4; i++) {
        posxy[i][0] = (i % 2) * 6;
        posxy[i][1] = (i / 2) * 6;
    }
}

void ligne(){
    _setmode(_fileno(stdout), _O_U16TEXT);
    color(13,0);
    wprintf(L"\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\x2550\n");
    color(15,0);
    _setmode(_fileno(stdout), _O_TEXT);
}
void afficherRegles(){
    color(15,0);
    printf("Regles du jeu de societe Labyrinthe:\n\n");
    printf("Le jeu se joue avec un plateau de 7x7 tuiles, 16 tuiles 'couloir de labyrinthe' a position fixe, 34 tuiles 'couloir de labyrinthe' a positionner aleatoirement et 24 cartes 'tresor' a distribuer.\nLes joueurs utilisent egalement 4 pions pour se deplacer dans le labyrinthe. ");
    printf("Le but du jeu est d'etre le premier a trouver tous les tresors caches dans le labyrinthe\nen utilisant les couloirs qui glissent et evoluent a chaque tour. Les joueurs doivent naviguer dans le labyrinthe changeant pour atteindre les tresors caches.\n");
    printf("Le plus malin a deplacer les couloirs sera le gagnant !\n");
}
void afficherCredits(){
    color(15,0);
    printf("\n\nPremier projet realise en Algorithmique et Informatique a l'ECE.\n");
    printf("Auteurs : Robin Queriaux, Baptiste Chesnot, Laouig Eleouet, Lucas Girault\n");
}

void color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void save_game(Sauvegarde *state) {
    char filename[BUFFER_SIZE];
    Sauvegarde save;

    // Demander à l'utilisateur de saisir le nom de la sauvegarde
    printf("Entrez le nom de la sauvegarde: ");
    fflush(NULL);
    fgets(filename, sizeof(filename), stdin);

    // Supprimer le retour à la ligne à la fin de la chaîne de caractères
    filename[strcspn(filename, "\n")] = 0;

    // Créer le dossier de sauvegardes s'il n'existe pas
    if (mkdir("Sauvegardes") == -1) {
        // Vérifier si le dossier existe déjà ou s'il y a eu une erreur
        if (errno != EEXIST) {
            // Erreur

            return;
        }
    }
    printf("Dossier cree avec succes.\n");



    char full_filename[BUFFER_SIZE];
    // Ajouter l'extension de fichier et le chemin du dossier de sauvegardes
    snprintf(full_filename, sizeof(full_filename), "Sauvegardes/%s.cfg", filename);




    // Ouvrir le fichier de configuration en écriture
    FILE *fp = fopen(full_filename, "w");
    if (fp == NULL) {
        // Erreur
        return;
    }

    printf("Fichier ouvert avec succes.\n");


    // Copier l'état du jeu dans la structure de sauvegarde
    for (int i = 0; i < LARGEUR; i++) {
        for (int j = 0; j < LARGEUR; j++) {
            fprintf(fp, "%d\n", save.tab[i][j]);
        }
    }

    for (int i = 0; i < BUFFER_SIZE; i++) {
        fprintf(fp, "%c\n", save.buffer[i]);
    }
    fprintf(fp, "%d\n", save.x);
    fprintf(fp, "%d\n", save.y);
    fprintf(fp, "%d\n", save.nbJoueurs);
    for (int i = 0; i < 4; i++) {
        fprintf(fp, "%d\n", save.pionsJoueurs[i]);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < LONGUEUR_NOM; j++) {
            fprintf(fp, "%c\n", save.nomJoueurs[i][j]);
        }
    }
    for (int i = 0; i < BUFFER_SIZE; i++) {
        fprintf(fp, "%c\n", save.choix[i]);
    }
    fprintf(fp, "%d\n", save.choix0);
    fprintf(fp, "%d\n", save.nbCartesJoueurs);
    for (int i = 0; i < CARTES; i++) {
        for (int j = 0; j < CARTES; j++) {
            fprintf(fp, "%d\n", save.cartesJoueurs[i][j]);
        }
    }
    for (int i = 0; i < LARGEUR_FINALE; i++) {
        for (int j = 0; j < LARGEUR_FINALE; j++) {
            fprintf(fp, "%d\n", save.tabfinal[i][j]);
        }
    }
    fprintf(fp, "%d\n", save.partie);
    for (int i = 0; i < LARGEUR; i++) {
        for (int j = 0; j < LARGEUR; j++) {
            fprintf(fp, "%d\n", save.sauvegarde1tab[i][j]);
        }
    }
    fprintf(fp, "%d\n", save.sauvegardetourjoueur);
    fprintf(fp, "%d\n", save.numjoueur);
    fprintf(fp, "%d\n", save.echap);
    fprintf(fp, "%d\n", save.carterestante);
    fprintf(fp, "%d\n", save.test_tresor);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 1; j++) {
            fprintf(fp, "%d\n", save.memoricase[i]);
        }
    }
    for (int i = 0; i < 4; i++) {
        fprintf(fp, "%d\n", save.cartejoueurtab[i]);
    }
    fprintf(fp, "%d\n", save.tourJoueur);
    fprintf(fp, "%d\n", save.nbTours);
    fprintf(fp, "%d\n", save.ligne_ou_colonne);
    fprintf(fp, "%d\n", save.numero_ligne_colonne);
    fprintf(fp, "%d\n", save.direction);


// Écrire la structure de sauvegarde dans le fichier de configuration

// Fermer le fichier
    fclose(fp);

    printf("Partie sauvegardee a l'adresse :\n%s\n", full_filename);

}

void oui_non(int *menu){
    int entre=0;
    int oui=0;
    int fleche;
    int echap = getch();// Lit un caractère sans afficher à l'écran
    if (echap == 27 ) { //Code ASCII de la touche Échap est 27
        system("cls");
        while(entre==0){
            _setmode(_fileno(stdout), _O_U16TEXT);
            fleche=getch();
            system("cls");
            switch (fleche) {
                case 13:
                    if(oui==0) {
                        entre=1;
                    }
                    if(oui==1) {
                        entre=1;
                        *menu=1;
                    }
                    break;
                case 75:
                    oui=1;
                    color(5,0);
                    wprintf(L"\x250C\x2500\x2500\x2500\x2510");
                    color(15,0);
                    wprintf(L"\x202D\x250C\x2500\x2500\x2500\x2510");
                    color(5,0);
                    wprintf(L"\n");
                    wprintf(L"\x2502");
                    wprintf(L"\x004E\x006F\x006E");
                    wprintf(L"\x2502");
                    color(15,0);
                    wprintf(L"\x202D\x2502");
                    wprintf(L"\x004F\x0075\x0069");
                    wprintf(L"\x2502");
                    color(5,0);
                    wprintf(L"\n");
                    wprintf(L"\x2514\x2500\x2500\x2500\x2518");
                    color(15,0);
                    wprintf(L"\x202D\x2514\x2500\x2500\x2500\x2518");

                    break;
                case 77:
                    oui=0;
                    color(15,0);
                    wprintf(L"\x250C\x2500\x2500\x2500\x2510");
                    color(5,0);
                    wprintf(L"\x202D\x250C\x2500\x2500\x2500\x2510");
                    color(15,0);
                    wprintf(L"\n");
                    wprintf(L"\x2502");
                    wprintf(L"\x004E\x006F\x006E");
                    wprintf(L"\x2502");
                    color(5,0);
                    wprintf(L"\x202D\x2502");
                    wprintf(L"\x004F\x0075\x0069");
                    wprintf(L"\x2502");
                    color(15,0);
                    wprintf(L"\n");
                    wprintf(L"\x2514\x2500\x2500\x2500\x2518");
                    color(5,0);
                    wprintf(L"\x202D\x2514\x2500\x2500\x2500\x2518");
                    color(15,0);

                    break;

            }

            _setmode(_fileno(stdout), _O_TEXT);
        }

    }

}

void caractere(int *caracteres){
    switch (*caracteres) {
        case 0:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(2,2);
            wprintf(L"\x2588\x2588"); //Mur
            color(15,0);
            break;
        case 1:
            _setmode(_fileno(stdout), _O_U16TEXT);
            wprintf(L"\x00A0\x00A0"); //Couloir
            break;
        case 2:
            _setmode(_fileno(stdout), _O_U16TEXT);      //pion1
            color(1,0);
            wprintf(L"\x0020\x2660"); //affichage des valeurs
            color(15,0);
            break;
        case 3:
            _setmode(_fileno(stdout), _O_U16TEXT);      //pion2
            color(2,0);
            wprintf(L"\x0020\x2663"); //affichage des valeurs
            color(15,0);
            break;
        case 4:
            _setmode(_fileno(stdout), _O_U16TEXT);      //pion3
            color(4,0);
            wprintf(L"\x0020\x2665"); //affichage des valeurs
            color(15,0);
            break;
        case 5:
            _setmode(_fileno(stdout), _O_U16TEXT);      //pion4
            color(5,0);
            wprintf(L"\x0020\x2666"); //affichage des valeurs
            color(15,0);
            break;
        case 8:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(2,0);
            wprintf(L"\x2588\x2588"); //affichage des valeurs
            color(15,0);
            break;
        case 9:
            _setmode(_fileno(stdout), _O_U16TEXT);
            color(13,13);
            wprintf(L"\x2588\x2588"); //affichage des valeurs
            color(15,0);
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