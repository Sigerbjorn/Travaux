#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    char nom[26];
    char prenom[26];
    int anneeNais;
    double moy;
    int promo;
}Etudiant;

typedef struct{
    Etudiant* etu;
    int nbetu;
    int cEtu;
}ListeEtu;

Etudiant creerEtu(int annee, double moy, int p){
    Etudiant e;
    scanf("%s", e.nom);
    scanf("%s",e.prenom);
    e.anneeNais=annee;
    e.moy=moy;
    e.promo=p;

    return e;
}

ListeEtu creerListe(int max){
    ListeEtu l;
    l.etu = malloc(max*sizeof(Etudiant));
    l.nbetu=0;
    l.cEtu=max;
    return l;
}

void affEtu(ListeEtu* e){
    int i;
    for (i=0; i<e->nbetu; i++){
        printf("%s %s est ne(e) en %d,\n A une moyenne de %lf,\n Et est dans la promo %d\n\n", e->etu[i].nom, e->etu[i].prenom, e->etu[i].anneeNais, e->etu[i].moy, e->etu[i].promo);
    }
}

void ajoutfinTabEtu(ListeEtu* l, Etudiant e){
    if(l->nbetu != l->cEtu){
        l->etu[l->nbetu]=e;
        l->nbetu=l->nbetu+1;

    }
    else{
        printf("Hey");

    }
}

int seekEtu(ListeEtu* l, char* nom){
    int i;

    for (i=0; i<l->nbetu; i++){
        if (l->etu[i].nom==nom){
            return i;
        }
    }
    return -1;
}

ListeEtu suppEtu(ListeEtu l, Etudiant e){
    int a, i;
    if (seekEtu(&l, e.nom) != -1){
        a=seekEtu(&l, e.nom);
        for (i=a+1; i<l.nbetu; i++){
            l.etu[i-1]=l.etu[i];
        }
        l.nbetu=l.nbetu-1;
    }
    return l;
}

void triEtu(ListeEtu l){
    int i, j, imin;
    Etudiant tmp;

    for (i=0; i<l.nbetu; i++){
        imin = i;
        for (j=0; j<l.nbetu; j++){
            if (l.etu[j].moy> l.etu[imin].moy){
                imin = j;
            }
        if (imin != i){
            tmp = l.etu[i];
            l.etu[i] = l.etu[imin];
            l.etu[imin] = tmp;
        }
        }
    }
}

Etudiant majorEtu(ListeEtu l, int p){
    int i, etu;
    double max;

    for (i=0; i<l.nbetu; i++){
        if(l.etu[i].moy > max && l.etu[i].promo == p){
            max = l.etu[i].moy;
            etu = i;
        }
    }
    return l.etu[etu];
}

void affEtuSolo(Etudiant e){
    printf("Nom: %s\n Prenom: %s\n Annee de naissance: %d\n Moyenne: %lf\n Promo: %d\n", e.nom, e.prenom, e.anneeNais, e.moy, e.promo);
}

void save(ListeEtu* l, char* loc){
    int i;
    FILE* save;
    save=fopen(loc, "w");
    for (i=0; i<l->nbetu; i++){
    fprintf(save, "%s %s %d %lf %d \n", l->etu[i].nom, l->etu[i].prenom, l->etu[i].anneeNais, l->etu[i].moy, l->etu[i].promo);
    }
    }

void importer(ListeEtu* l, char* emplacement){
	FILE * fp;
	int i=0;
	fp = fopen(emplacement, "r");
	if(fp){
    		while (!feof(fp)) {
			fscanf(fp, "%s %s %d %lf %d\n", l->etu[i].nom, l->etu[i].prenom, &l->etu[i].anneeNais, &l->etu[i].moy, &l->etu[i].promo);
			i++;
		}
		l->nbetu = i;
		printf("Fichier importe !\n");
	}else{
		printf("Erreur ouverture fichier %s\n", emplacement);
	}
	fclose(fp);
}




int main(){
    ListeEtu liste = creerListe(12);
    Etudiant E1, E2, E3, E4;
    printf("Etudiant 1:\n");
    E1=creerEtu(1999, 12.45, 1);
    printf("Etudiant 2:\n");
    E2=creerEtu(1998, 09.22, 2);
    printf("Etudiant 3:\n");
    E3=creerEtu(1997, 17.98, 1);
    printf("Etudiant 4:\n");
    E4=creerEtu(2009, 19.23, 2);

    ajoutfinTabEtu(&liste, E1);
    ajoutfinTabEtu(&liste, E2);
    ajoutfinTabEtu(&liste, E3);
    ajoutfinTabEtu(&liste, E4);
    affEtu(&liste);
    printf("\n (-----------------------------------------------------) \n\n");
    liste=suppEtu(liste, E2);
    affEtu(&liste);
    printf("Major de la promo 2: \n");
    affEtuSolo(majorEtu(liste, 2));

    printf("\nMajor de la promo 1: \n");
    affEtuSolo(majorEtu(liste, 1));

    save(&liste, "save");
    printf("\n (-----------------------------------------------------) \n\n");

    ListeEtu liste2=creerListe(12);
    importer(&liste2, "save");
    affEtu(&liste2);


    return 0;
}
