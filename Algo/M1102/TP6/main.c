#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include "../ioap123.h"


int **  allouerTab2D(int nbL , int nbC){
    int**  lePointeur;
    int i; lePointeur = malloc(sizeof(int *)* nbL);

    for(i=0; i<nbL; i=i+1){
        lePointeur[i] = malloc(
        sizeof(int)*nbC);
    }

    return lePointeur;
}

int ** creerDamier(int** tab,int c,int l){
    int i,j;
    for (i=0; i<c; i=i+1){
        for (j=0; j<l; j=j+1){
            tab[i][j] = rand()%2;
        }
    }
    return tab;
}

void afficherDam(int** tab, int nbC, int nbL){
    int i,j,w;
    for (i=0; i< nbC; i=i+1){
        for (j=0; j < nbL; j = j+1){
            print_text("|");
            //print_int(tab[i][j]); // Afficher De 1 et des 0

            if (tab[i][j] == 1){    // AFICHER DES ETOILES OU DES ESPACES
                print_text("*");
            }
            else{
                print_text(" ");}

        }
        print_text("|");
        print_newLine();

        for (w=0; w<nbL; w=w+1 ){
        print_text("--");
    }

        print_newLine();
    }
}

/* int * nbVoisin(int ** tab, int c, int l){
    int cpt = 0;

    if (tab[c+1][l] == 1 ){
        cpt = cpt+1;
    }
    if (tab[c][l+1] == 1){
        cpt=cpt+1;
    }
    if (|| tab[c-1][l] ==1){
        cpt=cpt+1;
    }
    return cpt;


}*/

int nbVoi(int l, int c, int g[l][c], int x, int y){
    int cpt = 0;
    int i, j;
    for (i=x-1; i<=x+1; i=i+1){
        for (j = y-1; j<= y+1; j=j+1){
            if ((i != x && j!= y) && (i>= 0) && (i< l) && (j>0) && (j<c)){
                if (g[i][j] == 1);
                cpt = cpt+1;
            }
        }
    }
    return cpt;
}

int ** nouvelleG (int ** tab, int c, int l, int** dam2){
    int i, j;
    for (i=0; i< c; i=i+1){
        for (j=0; i<l; j=j+1){
            if (nbVoi(l, c, tab, j, i) == 2 || nbVoi(l, c, tab, j, i) == 3){
                dam2[i][j] = 1;
            }
            else if (nbVoi(l, c, tab, j, i) > 3){
                dam2[i][j] = 0;
            }
            else if (nbVoi(l, c, tab, j, i) < 2){
                dam2[i][j] = 0;
            }

        }
    }
    return dam2;
}

int main()
{
    int** dam, dam2;
    int nbL, nbC;
    print_text("Donnez le nombre de lignes\/ Colonnes: \n");
    print_text("Nb Colonnes: ");
    nbL = read_int();
    print_text("Nb Lignes: ");
    nbC = read_int();
    dam = allouerTab2D(nbC,nbL);
    print_newLine();

    creerDamier(dam, nbC,nbL);
    afficherDam(dam, nbC, nbL);
    print_text("Nombre de voisin(s): ");
    print_int(nbVoi(nbL, nbC, dam, 5, 5));

    print_newLine();

    dam2 = allouerTab2D(nbC, nbL);
    nouvelleG(dam, nbC, nbL, dam2);
    afficherDam(dam2, nbC, nbL);
    return 0;
}
