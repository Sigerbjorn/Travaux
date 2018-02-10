#include <stdio.h>
#include <stdlib.h>

typedef struct{
    double abs;
    double ordo;
} Point;

typedef struct{
    Point tab[20];
    int n;
} Polygone;

Point initPoint(){
    Point p;

    printf("Donner l'abscisse: ");
    scanf("%lf", &p.abs);

    printf("donner l'ordonnée: ");
    scanf("%lf", &p.ordo);

    return p;
}

double distance(Point a, Point b){
    return sqrt(pow(a.abs-b.abs, 2)+pow(a.ordo-b.ordo, 2));
}

Polygone creerPoly(){
    Polygone pol;
    int i;
    printf("\nCombien de points? ");
    scanf("%d", &pol.n);

    for (i=0; i<pol.n; i++){
        pol.tab[i]=initPoint();
    }

    return pol;
}

double perimetre(Polygone pol){
    int i=1, imin=0;
    double res=0;

    while (imin<pol.n){

        while (i<pol.n){
            res=res+distance(pol.tab[imin], pol.tab[imin+i]);
            i=i+1;
        }
        imin=imin+1;
    }
    return res;
}

void AfficherPoly(Polygone pol){
    int i;

    printf("---------------------------------\n");
    printf("Abscisse\tOrdonnees\n");
    for (i=0; i<pol.n; i++){
        printf("%lf\t%lf\n", pol.tab[i].abs, pol.tab[i].ordo);
    }

    printf("---------------------------------\n");
}

int compare(Polygone a,Polygone b){
    if (perimetre(a)>perimetre(b)){
        return -1;
    }else if (perimetre(b)>perimetre(a)){
        return 1;
    }else{
        return 0;}
}

int main()
{
    //Creations des points
    Point C,D;
    printf("\nCreer deux points: \n\n");
    C=initPoint();
    D=initPoint();

    printf("\nDistance entre ces deu points: %lf\n", distance(C,D));


    //Creation des polygones:
    printf("\n\nCreer Deux Polygones: \n");

    Polygone A, B;
    A = creerPoly();
    B = creerPoly();

    //Affichage des points
    printf("\nPolygone A: \n");
    AfficherPoly(A);
    printf("\nPolygone B: \n");
    AfficherPoly(B);

    //Afichage des perimetres
    printf("\n Perimetre de A: %lf \n", perimetre(A));
    printf("\n Perimetre de B: %lf \n", perimetre(B));

    //Comparaison entre les deux polygones
    if (compare(A,B)==1){
        printf("\nLe second polygone est le plus grand, au sens du perimetre.");
    }else if (compare(A,B)==-1){
         printf("\nLe premier polygone est le plus grand, au sens du perimetre.");
    } else{
    printf("\nLes deux polygones sont egaux au sens du perimetre.");
    }

    return 0;
}
