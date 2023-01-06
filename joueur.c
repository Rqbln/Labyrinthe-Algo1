// joueur.c
// Created by bapti on 27/12/2022.
//
#include "sprog.h"

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



    *nbCartesJoueurs = CARTES / *nbJoueurs;
}
void CreationNomJoueurs(int *nbJoueurs,char nomJoueurs[4][LONGUEUR_NOM]){

    // Demande le nom de chaque joueur
    for (int i = 0; i < *nbJoueurs; i++) {
        printf("Entrez le nom du joueur %d :", i+1);
        scanf("%s", nomJoueurs[i]);
    }
}
void distributionPions(int *nbJoueurs,char nomJoueurs[4][LONGUEUR_NOM],int pionsJoueurs[4]){
    int pions[4] = {0, 0, 0, 0};
    printf("Les pions disponibles sont :\n");
    if (*nbJoueurs == 2){

        _setmode(_fileno(stdout), _O_U16TEXT);
        color(1,0);
        wprintf(L"\x0031\x002e\x0020\x2660\n");
        color(2,0);
        wprintf(L"\x0032\x002e\x0020\x2663\n");
        color(15,0);

    }
    if (*nbJoueurs == 3){
        _setmode(_fileno(stdout), _O_U16TEXT);
        color(1,0);
        wprintf(L"\x0031\x002e\x0020\x2660\n");
        color(2,0);
        wprintf(L"\x0032\x002e\x0020\x2663\n");
        color(4,0);
        wprintf(L"\x0033\x002e\x0020\x2665\n");
        color(15,0);

    }
    if (*nbJoueurs == 4){
        _setmode(_fileno(stdout), _O_U16TEXT);
        color(1,0);
        wprintf(L"\x0031\x002e\x0020\x2660\n");
        color(2,0);
        wprintf(L"\x0032\x002e\x0020\x2663\n");
        color(4,0);
        wprintf(L"\x0033\x002e\x0020\x2665\n");
        color(5,0);
        wprintf(L"\x0034\x002e\x0020\x2666\n");
        color(15,0);
    }
    _setmode(_fileno(stdout), _O_TEXT);
    char input[BUFFER_SIZE];
    for (int i = 0; i < *nbJoueurs; ++i) {
        pionsJoueurs[i]=0;
        while (pionsJoueurs[i]<1 || pionsJoueurs[i]>*nbJoueurs || pions[0]==pionsJoueurs[i] || pions[1]==pionsJoueurs[i] || pions[2]==pionsJoueurs[i] ||pions[3]==pionsJoueurs[i]){
            printf("%s, choisissez votre pion :",nomJoueurs[i]);
            fflush(stdin);
            fgets(input,BUFFER_SIZE,stdin);
            pionsJoueurs[i]= atoi(input);
        }
        pions[i]= atoi(input);
    }
    system("cls");
    afficherTitre();
    ligne();
    printf("Choix des pions :\n");
    for (int i = 0; i < *nbJoueurs; ++i) {
        printf("- %s a choisi le pion %d\n",nomJoueurs[i],pionsJoueurs[i]);
    }
    printf("\n");
}

void debutPartie (int *nbJoueurs, int *tourJoueur, char nomJoueurs[4][LONGUEUR_NOM], int pionsJoueurs[4], int* nbTours){
    srand(time(NULL));
    *tourJoueur=rand()%*nbJoueurs;
    char demarrage;
    printf("La partie peut commencer.\n%s, appuyez sur 'Entree' pour lancer la partie !\n",nomJoueurs[*tourJoueur]);
    do {
        demarrage=getchar();
    }while (demarrage!='\n');
    system("cls");
    afficherTitre();
    ligne();
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

void afficheCarteJoueur(int *tourJoueur,int *nbCartesJoueurs, char nomJoueurs[4][LONGUEUR_NOM],int cartesJoueurs[CARTES][CARTES], int cartejoueurtab[4]){
    int cartejoueur;
    int caracteres;
    cartejoueur=cartejoueurtab[*tourJoueur];

    printf("%s, Voici tes cartes tresor :\n", nomJoueurs[*tourJoueur]);
    _setmode(_fileno(stdout), _O_U16TEXT);
    for (int i = 0; i < cartejoueur+1; ++i) {
        wprintf(L"\x250C\x2500\x2500\x2510");
    }
    wprintf(L"\n");
    for (int i = 0; i < cartejoueur+1; ++i) {
        wprintf(L"\x2502");
        _setmode(_fileno(stdout), _O_TEXT);
        caracteres=cartesJoueurs[*tourJoueur][i];
        caractere(&caracteres);
        _setmode(_fileno(stdout), _O_U16TEXT);
        wprintf(L"\x2502");
    }
    wprintf(L"\n");
    for (int i = 0; i < cartejoueur+1; ++i) {
        wprintf(L"\x2514\x2500\x2500\x2518");
    }
    wprintf(L"\n");
    _setmode(_fileno(stdout), _O_TEXT);

    //cartejoueurtab[*tourJoueur]+=1;

}