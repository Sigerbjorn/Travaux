#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double*allouerTab(int nbElt){
return malloc(nbElt * sizeof(double));
}

double alea(double max){ //Genere un reel aleatoire entre 0 et max.
    return (double)rand()*max / (double)RAND_MAX;
}

void remplirAlea(double* tab, int n){ //Remplit le tableau t avec des chiffres aleatoires entre 0 et 100.
    int i;
    for (i=0; i<n; i=i+1){
        tab[i] = alea(100);
    }
}

void afficherTab(double* tab, int n){ // affiche le tableau tab de n elts.
    int i;
    printf(" | ");
    for (i=0; i<n; i=i+1){
        printf("%f | ",tab[i]);

     }
}

void insertion (double* t, int n){ // Tri par insertion, bien prit en note pendant le cours.
    int i,j,p;
    double tmp;
    for (i=0; i<n; i=i+1){
        p=0;

        while (p<i && t[i]>t[p]){
            p=p+1;
        }
        if (p!=i){
            tmp=t[i];
            for(j=i; j>p; j=j-1){
                t[j] = t[j-1];
            }
        t[p] = tmp;

        }
    }
}

void selection (double* t, int n){
    int i, j, imin;
    double tmp;

    for (i=0; i<n; i=i+1){
        imin = i;
        for (j=0; j<n; j=j+1){
            if (t[j]> t[imin]){
                imin = j;
            }
        if (imin != i){
            tmp = t[i];
            t[i] = t[imin];
            t[imin] = tmp;
        }
        }
    }
}

void Swap(double* t, int i, int j){

    double tmp;
    tmp = t[i];
    t[i] = t[j];
    t[j] = tmp;

    }
int Partition(double* tab,int gauche,int droite){
    int g, d;
    double p;
    p = tab[gauche];
    g = gauche-1;
    d = droite+1;
        while(1) {do d--;
        while ( tab[d] > p );
        do g++;
        while( tab[g] < p );
            if( g < d)Swap( tab, g, d );
        else return d;} }


void Quicksort(double*tab,int gauche,int droite) {
    int pivot;
if( droite > gauche ){
pivot = Partition( tab, gauche, droite);
Quicksort( tab, gauche, pivot);
Quicksort( tab, pivot+1, droite);}
}

void memCopy(double* destination,int* source,int n){
    int i;
    for(i=0;i<n;i=i+1){
        destination[i]=source[i];
    }
}


void fusion(double* tableau,int deb1,int fin1,int fin2)
        {
        double* table1;
        int deb2=fin1+1;
        int compt1=deb1;
        int compt2=deb2;
        int i;

        table1=malloc((fin1-deb1+1)*sizeof(double));

        for(i=deb1;i<=fin1;i++)
            {
            table1[i-deb1]=tableau[i];
            }

        for(i=deb1;i<=fin2;i++)
            {
            if (compt1==deb2)
                {
                break;
                }
            else if (compt2==(fin2+1))
                {
                tableau[i]=table1[compt1-deb1];
                compt1++;
                }
            else if (table1[compt1-deb1]<tableau[compt2])
                {
                tableau[i]=table1[compt1-deb1];
                compt1++;
                }
            else
                {
                tableau[i]=tableau[compt2];
                compt2++;
                }
            }
        free(table1);
        }


void fusion2(double* tableau,int deb,int fin)
        {
        if (deb!=fin)
            {
            int milieu=(fin+deb)/2;
            fusion2(tableau,deb,milieu);
            fusion2(tableau,milieu+1,fin);
            fusion(tableau,deb,milieu,fin);
            }
        }

void tri_fusion(double* tableau,int longueur)
     {
     if (longueur>0)
            {
            fusion2(tableau,0,longueur-1);
            }
     }

int main()
{
    int nbElt;
    int* t;
    double tps;


    clock_t debut, fin;
    printf("Donner le nombre de valeurs du tableau a creer: \n");
    scanf("%i", &nbElt);
    t = allouerTab(nbElt);


    printf("\n----------------------------------------------\n");
    remplirAlea(t, nbElt);
    printf("Tableau pas trié: \n");
    afficherTab(t, nbElt);


    insertion(t, nbElt);
    printf("\n----------------------------------------------\n");
    printf("Tableau trié par Insertion: \n");
    afficherTab(t, nbElt);

    selection(t, nbElt);
    printf("\n----------------------------------------------\n");
    printf("Tableau trié par Selection: \n");
    afficherTab(t, nbElt);


    printf("\n----------------------------------------------\n");

    double* tab;
    tab=allouerTab(nbElt);
    remplirAlea(tab,nbElt);
    printf("Tableau pas trié: \n");
    afficherTab(tab,nbElt);
    printf("\n----------------------------------------------\n");

    Quicksort(tab,0,nbElt-1);
    printf("Tableau trié par Quicksort: \n");
    afficherTab(tab,nbElt);
    printf("\n----------------------------------------------\n");


    tri_fusion(t,nbElt);
    printf("Tableau trié par Fusion: \n");
    afficherTab(t, nbElt);
     printf("\n----------------------------------------------\n");

    //Mesure du temps pour le tri par sélection

    double* t1;
    double* t2;

    srand(time(0));
    t1=allouerTab(1000);
    remplirAlea(t1,1000);
    debut=clock();
    selection(t1, 1000);
    fin = clock();

    tps=(double)(fin-debut)/CLOCKS_PER_SEC;
    printf("\n \n Temps ecoule (en secondes) pour le tri par Selection: %f s\n", tps);

    //Mesure du temps pour le tri par insertion

    srand(time(0));
    t2=allouerTab(1000);
    remplirAlea(t2, 1000);
    debut=clock();
    insertion(t2, 1000);
    fin = clock();

    tps=(double)(fin-debut)/CLOCKS_PER_SEC;
    printf("\n \n Temps ecoule (en secondes) pour le tri par Insertion: %f s\n", tps);

    //Mesure du temps pour le tri par QuickSort

    double* t3;
    srand(time(0));
    t3=allouerTab(1000);
    remplirAlea(t3, 1000);
    debut=clock();
    Quicksort(t3, 0, 1000);
    fin = clock();

    tps=(double)(fin-debut)/CLOCKS_PER_SEC;
    printf("\n \n Temps ecoule (en secondes) pour le tri par QuickSort: %f s\n", tps);

     double* t4;
    srand(time(0));
    t4=allouerTab(1000);
    remplirAlea(t4,1000);
    debut=clock();
    tri_fusion(t4,1000);
    fin = clock();

    tps=(double)(fin-debut)/CLOCKS_PER_SEC;
    printf("\n \n Temps ecoule (en secondes) pour le tri par Fusion: %f s\n", tps);
    return 0;
}
