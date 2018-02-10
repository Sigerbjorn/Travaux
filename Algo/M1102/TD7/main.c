#include <stdio.h>
#include "../ioap123.h"

void lireFichier(char*nom ,int**  grille)
    {
    FILE *ptf;
    ptf = fopen(nom ,"r");
    if(ptf==NULL)
        {
         print_text("erreur d'ouverture de fichier\n");
        }
    int i,j;
    for (i = 0; i<9; i=i+1)
       {
         for(j=0; j<9; j=j+1)
         {
         fscanf(ptf ,"%d",&grille[i][j]);
         }
       }
      }


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

void afficherGrille(int** g)
 {
  int i,j;
  for(i=0;i<9; i=i+1)
    {
     for(j=0;j<9;j=j+1)
      {
       print_int(g[i][j]);
       print_text(" | ");
       }

  print_newLine ();
    for (j=0; j<9; j=j+1){
        print_text("----");

    }
    print_newLine();
    }
  }



bool verifLiCol(int** grille){
int i, j, k, k1, k2, l1, l2;

    for (i=0; i<8; i=i+1){ //VERIFIE LES LIGNES ET LES COLONNES
        for(j=0; j<8; j=j+1){
            for (k=0; k<8; k=k+1){
                if (k!=j && grille[i][j] == grille[i][k]){
                print_int(i); print_text("|"); print_int(j);
                    print_text(" <- Erreur à cette Ligne | Colonne.");
                    return false;
                }

                if (k!=j && grille[j][i] == grille[k][i]){
                print_int(j); print_text("|"); print_int(i);
                print_text(" <- Erreur à cette Ligne | Colonne.");
                    return false;
                }
            }
        }

    }

  /*  for (i = 0; i < 2; i = i +1){ // VERIFIE LES BLOCS MAIS NE MARCHE PAS.
         for (j = 0; j < 2; j = j +1){
            for (k1 = 0; k1 < 2; k1= k1+1){
                 for (l1 = 0; l1 < 2; l1 = l1 +1){
                for (k2 = 0; k2< 2; k2= k2+1){
                 for (l2 = 0; l2 < 2; l2= l2 +1){
                    if ((k1, l1) != (k2, l2) && grille[i+k1][j+k2] == grille[i+k2][j+k2]){
                        print_int(i);print_text("|");print_int(j);print_text("|");print_int(k1);print_text("|");print_int(k2);print_text("|");print_int(l1);print_text("|");print_int(l2);
                        return false;


                            }
                        }
                    }
                }
            }
        }
    } */

    return true;
}
int main(void)
{

int** laGrille;
laGrille = allouer2D (9,9);
lireFichier("Grilles/grilleNOK.txt",laGrille);
afficherGrille(laGrille);
if (verifLiCol(laGrille)){
    print_text("Ok.");
}else{

}
return 0;
}


