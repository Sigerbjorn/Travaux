#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool estBissextile(int annee){
    if (annee % 4 == 0 && annee % 100 != 0 || annee % 400 == 0){
        return true;
    }
    else{
        return false;
    }

}

bool moisValide(int mois){
    if (mois >= 1 && mois <= 12){
        return true;
    }
    else {
        return false;
    }
}

int nbjours(int mois, int annee){
  if (moisValide(mois)){
    if (mois == 2 && estBissextile(annee)){
            return 29;
    }
    else if (mois%2 == 0 && mois > 2){
        return 30;
    }
    else if (mois == 2){
        return 28;
    }
    else {
        return 31;
    }
}
}

bool dateValide(int jour, int mois, int annee){
    if (jour > 0 && jour <= nbjours(mois, annee)){
        return true;
    }
    return false;

}

int jEcoules(int jour1, int mois1, int annee1, int jour2, int mois2, int annee2){

        if (dateValide(jour1, mois1, annee1) && dateValide(jour2, mois2, annee2)){
            if(annee1 == annee2){
                if (mois1 == mois2){
                    return jour1 - jour2;
                }

                else{
                    int a = nbjours(mois2, annee2) - jour1;
                    int b = nbjours(mois1, annee1) - jour2;
                    return b+a;
            }
        }else{
        int difAn = (annee2 - annee1) * 365;
        int a = nbjours(mois2, annee2) - jour1;
        int b = nbjours(mois1, annee1) - jour2;
        return difAn + a + b;


    }
    }




    else{
        printf("il n\' y a pas ce nombre de jours dans ce mois.");
    }
}

int main()
{
    //Variables
    int annee,mois,jour;
    bool bonneDate = false;
    printf("Est-elle bissextile?\n\n");

    while (bonneDate == false){
    printf("Donnez une annee: ");
    scanf("%d", &annee);
    printf("Donnez un mois: ");
    scanf("%d", &mois);
    printf("Donnez un jour: ");
    scanf("%d",&jour);

    if (moisValide(mois) && dateValide(jour, mois, annee)){
    bonneDate = true;}
     else{ printf("Date invalide, recommencez. \n");}
}

    // Bissextile
    if (estBissextile(annee)){
        printf("\n Annee bissextile.\n");
    }else{
        printf("\n Annee pas Bissextile \n");
    }

    //Mois Valide
    if (moisValide(mois)){
        printf(" Mois valide\n");
    }
    else{
        printf(" Mois pas valide\n");
    }

    // Nombre de jours
    printf("\n Il y a ");
   printf("%d",nbjours(mois, annee));
   printf(" Jours dans ce mois.\n");

    //Date valide
   if(dateValide(jour, mois, annee)){
        printf(" Date valide \n");
   }

   else{printf(" Date pas valide \n");}

   // ALLER PLUS LOIN

   printf("-----------------------------------------");

   int annee2, jour2, jour3, mois2, mois3, annee3;
    printf("\n\n");
    printf("Premiere date: \n");


    printf("Donnez un jour: ");
     scanf("%d", &jour2);
     printf("Donnez un mois: ");
     scanf("%d",&mois2);
    printf("Donnez une annee: ");
     scanf("%d",&annee2);

    printf("Seconde annee: \n");


    printf("Donnez un jour: ");
     scanf("%d", &jour3);
      printf("Donnez un mois: ");
     scanf("%d", &mois3);
     printf("Donnez une annee: ");
     scanf("%d", &annee3);


   printf("Il s'est écoulé ");
   printf("%d",jEcoules(jour2, mois2, annee2, jour3, mois3, annee3));

   printf(" jours entre les deux jours donnés.");

 return 0;
 }

