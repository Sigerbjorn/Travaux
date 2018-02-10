#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../ioap123.h"
#include <time.h>

#define RAND_MAX = pow(c, 2)

int** allouer2D(int l,int c)
 {
    int** m;
    int i;
    m = malloc(l*sizeof(int*));
    for(i=0; i<l; i=i+1)
      {
        m[i] = malloc(c*sizeof(int));
      }
   return  m;
 }

void entrerVal(int ** m, int c){
    int i,j;
    for (i=0; i<c; i=i+1){
        for (j=0; j<c; j=j+1){
            m[i][j] = read_int();
        }
    }
}

void afficherValMat(int ** m, int c){
    int i, j, k;
    for (i=0; i<c; i=i+1){
        for (j=0; j<c; j=j+1){
            print_int(m[i][j]);
            print_text("|");
        }
        print_newLine();
        for (k=0; k<c; k=k+1){
            print_text("--");
        }
        print_newLine();
    }
}

bool verifDublons(int ** m, int c){
    int i, j, cc = pow(c, 2), a, cpta = 0;

    for (a=0; a<cc; a=a+1){
        for (i=0; i<c; i=i+1){
            for (j=0; j<c; j=j+1){
                if (m[i][j] == a && cpta == 0){
                    cpta = cpta+1;
                }
                else if (cpta != 0 && m[i][j] == a){
                    return false;
                }

            }
        }
    }
    return true;
}

int somLigne(int ** m, int c, int l){
    int i, cpt=0;

        for (i=0; i<c; i=i+1){
            cpt = cpt+m[i][l];
        }
        return cpt;
}

bool verifSomLigne(int ** m, int c){
    int j;
    for (j=1; j<c-1; j=j+1){
        if (somLigne(m, c, j) == somLigne(m, c, j-1)){
            return true;
        }
    }
    return false;
}

int somColonnes(int ** m, int c, int j){
    int i, cpt=0;
    for (i=0; i<c; i=i+1){
        cpt = cpt+m[j][i];
    }
    return cpt;
}

bool verifSomColonnes(int ** m, int c){
    int i;
    for (i=1; i<c-1; i=i+1){
        if (somColonnes(m, c, i) == somColonnes(m, c, i-1)){
            return true;
        }
    }
    return false;
}

int somDiago(int ** m, int c){
    int j, cpt=0;
        for (j=0; j<c-1; j=j+1){
            cpt = cpt+m[j][j];
        }
    return cpt;
}

bool verifSomDiagos(int** m, int c){
    int j;
}

void remplirAlea(int ** m, int c){
    int i, j;
    int cc = pow(c, 2);

    for(i=0; i<c; i=i+1){
        for(j=0; j<c; j=j+1){
            m[i][j] = rand()%cc;
        }
    }


}

int main()
{
    char rep;
    int m = allouer2D(3, 3);
    /* print_text("Remplir aléatorement, ou choisir des valeurs? (A/V) \n");
    rep = read_char();
    if (rep == 'A' || rep == 'a'){
        print_text("Remplissage... \n");
        remplirAlea(m, 3);
    }
    else if (rep == 'V'|| rep== 'v'){
        print_text("Entrez des valeurs:");
        entrerVal(m, 3);
    } */

    entrerVal(m, 3);
    afficherValMat(m, 3);

    if (verifDublons(m, 3) == false){
        print_text("Il y a des doublons. \n");
    }else print_text("Aucun doublons. \n");

    if (verifSomColonnes(m, 3) == false){
        print_text("Les sommes des colonnes ne sont pas égales. \n");
    }else print_text("Les sommes des colonnes  sont  égales. \n");

    if (verifSomLigne(m, 3) == false){
        print_text("Les sommes des lignes ne sont pas égales. \n");
    }else print_text("Les sommes des lignes  sont  égales. \n");

    return 0;
}
