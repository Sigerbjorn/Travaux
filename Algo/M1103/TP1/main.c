#include <stdio.h>
#include <math.h>
#include <stdbool.h>

struct sTdegre_sexa {
    double degre;
    double minute;
    double seconde;
};
typedef struct sTdegre_sexa degre_sexa;

double sexa_vers_dec(degre_sexa d){

    return d.degre+d.minute/60+d.seconde/3600;
}

degre_sexa dec_vers_sexa(double deg){
    degre_sexa retour;
    double x,y;
    retour.degre = floor(deg);
    y = (deg - retour.degre) *60;
    retour.minute = floor(y);
    retour.seconde = (y - retour.minute) *60;
    return retour;
}

degre_sexa secApre(degre_sexa init){
    degre_sexa final;

    final = init;
    final.seconde = init.seconde +1;

    return final;
}

bool verif(degre_sexa entree){
    if (entree.degre <= 360 && entree.degre >= 0 && entree.minute <= 60 && entree.minute >= 0 && entree.seconde <= 60 && entree.seconde >=0){
        return true;
    }
    else{return false;}
}
int main(){
    double deg, min, sec;
    degre_sexa a,u,x;
    bool k = false;

        while  (k==false) {
            printf("Entrez une lattitude: \n");
            printf("Degres: ");
            scanf("%lf", &deg);
            printf("Minutes: ");
            scanf("%lf", &min);
            printf("Secondes: ");
            scanf("%lf", &sec);

            u.degre = deg;
            u.minute = min;
            u.seconde = sec;

            if (verif(u) == true){
                k = true;
            }
            else{
                printf("Mauvaise entree! \n");
            }
        }


        printf("Sexadecimal vers decimal: %lf \n\n", sexa_vers_dec(u));

        a = dec_vers_sexa(sexa_vers_dec(u));
        printf("Decimal vers Sexadecimal: \n\n");
        printf("%lf, %lf, %lf \n", a.degre, a.minute, a.seconde);

        printf("Latitude suivante: \n\n");
        x = secApre(u);

        printf("Degres: %lf, Minutes: %lf, Secondes: %lf \n\n", x.degre, x.minute, x.seconde);

        printf("Decimal de la lattitude suivante: \n %lf \n\n", sexa_vers_dec(x));

    return 0;

}
