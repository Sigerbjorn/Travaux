#include <stdio.h>
#include <stdlib.h>
#include "../ioap123.h"

typedef struct {
    char nom[26];
    char pion;
} Joueur;


void initGrille(char** grille, int dim){
    int i,j;

    for (i=0; i<dim; i++){
        for (j=0; j<dim; j++){
            grille[i][j] = '_';
        }
    }
}


void affiche_grille(char** grille, int dim){
    int i,j;

    for (i=0; i<dim; i++){
        for (j=0; j<dim; j++){
            printf("%c", grille[i][j]);
        }
        printf("\n");
    }
}


bool testLigneXO(char** grille, int dim, char c){
    int i,j, cpt=0;
    for (i=0; i<dim; i++){
        for (j=0; j<dim; j++){

            if (grille[i][j] == c){
                cpt = cpt+1;}

            if (cpt == dim){
                return true;
            }
        }
    }
   return false;
}


bool testLigne(char** grille, int dim){

    if (testLigneXO(grille, dim, 'X') || testLigneXO(grille, dim, 'O')){
        return true;
    }
    return false;
}


bool testColonnesXO(char** grille, int dim, char c){
    int i,j, cpt=0;

    for (i=0; i<dim; i++){

        for (j=0; j<dim; j++){

            if (grille[j][i]==c){
                cpt=cpt+1;
            }

            if (cpt==dim){
                return true;
            }

        }
    }
    return false;
}


bool testColonnes(char** grille, int dim){
    return (testColonnesXO(grille, dim, 'C') || testColonnesXO(grille, dim, 'X'));

}

bool verifFilled(char** grille, int dim){
    int i, j;
    for (i=0; i<dim; i++){
        for (j=0; j<dim; j++){
            if (grille[i][j]=='_'){
            return false;}
        }
    }
    return true;
}

bool seek(char** grille, int dim){
    int i,j;

    for (i=0; i<dim; i++){
        for (j=0; j<dim; j++){
            if (grille[i][j]=='_'){
                return true;;
            }
        }
    }
    return false;
}

bool test_Fin(char** grille, int dim){
    if (testColonnes(grille, dim) || testLigne(grille, dim) || verifFilled(grille, dim)){
    return true;
    }
}



Joueur renseigne(char p){
    Joueur j;
    int i=0;
    char n=' ';
    printf("Nom du joueur pour le pion %c?\n (taper ! pour arrêter la saisie) \n", p);

    while (n != '!'){
        j.nom[i]=scanf("%c", &n);
        i=i+1;
    }
    j.pion=p;
    return j;
}

void placePion(Joueur j, char** grille, int dim){
    int i,k;

    printf("Ou placer?\n");
    scanf("%i", &i);
    scanf("%i", &k);

    grille[i][k]=j.pion;
}

char** makeGrille(int dim){
    char** grille;
    int i;
    grille = malloc(dim*sizeof(char*));
    for (i=0; i<dim; i++){
        grille[i]=malloc(dim*sizeof(char));
        }
    return grille;
}

int main()
{
    Joueur j1, j2;
    char** grille;
    int taille;
    printf("Quelle est la taille de la grille? \n");
    scanf("%i", &taille);
    grille = makeGrille(taille);
    initGrille(grille, taille);
    affiche_grille(grille, taille);
    j1=renseigne('X');
    j2=renseigne('O');
    bool endGame=false;


    while (endGame == false){

    printf("Au joueur 1: \n");
    placePion(j1, grille, taille);
    affiche_grille(grille, taille);

        if (test_Fin(grille, taille)==true){
            printf("Partie Terminée: BRAVO");
            endGame = true;
            break;
        }

    printf("Au joueur 2: \n");
    placePion(j2, grille, taille);
    affiche_grille(grille, taille);

        if (test_Fin(grille, taille)==true){
            printf("Partie Terminée: BRAVO");
            endGame = true;
        }

        if (seek(grille, taille)==false){
            printf("Perdu! EGALITE");
            endGame = true;
            break;
        }

    }

    return 0;
}
