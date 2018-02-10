#include <stdio.h>
#include <stdlib.h>
#include "../ioap123.h"

void saisie(double* tab, int n){
    int i;
    for (i=0; i<n; i=i+1){
        tab[i] = read_int();
    }
}

void histogramme (double *notes, int nbn, int *histo){
    int i,j;

    for (i=0; i<nbn; i=i+1){
        histo[i] =0;

        for (j=0; j<nbn; j=j+1){

            if (notes[i]==notes[j]){
                histo[i]=histo[i]+1;
            }
        }
    }

}

void affHisto(int *histo){
    int i;
    for (i=0; i<21; i=i+1){
        print_text("Note: ");
        print_int(i+1);
        print_newLine();
        print_int(histo[i]);
        print_newLine();
    }
}


int main()
{
    double tab[20];
    saisie(tab, 20);
    print_text("------------------------------------- \n");
    int histo[21];
    histogramme(tab, 20, histo);
    print_text("-------------------------------------- \n");
    affHisto(histo);
    return 0;
}
