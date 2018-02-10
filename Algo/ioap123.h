#ifndef IOAP123_H_INCLUDED
#define IOAP123_H_INCLUDED

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Le type text permet de stocker une cha�ne de caract�res
il s'agit en fait du type pointeurs de caract�re(s)
*/
typedef char *text;

/*
 Affiche le texte txt sur la sortie standard
*/
void print_text(text txt);

/*
renvoie le texte saisie sur l'entr�e standard, texte termin� par
un changement de ligne. La taille maximale du texte est de 256 caract�res.
Le changement de ligne n'est pas pr�sent dans le texte renvoy�.
*/
text read_line();


/*
permet de passer � la ligne, affiche un changement de ligne sur la sortie
standard
*/
void print_newLine();


/*
 * retourne le caractere lu au clavier
 *
 */

char read_char();


/*
retourne une valeur entiere saisie au clavier, suivie du retour � la ligne
*/
int read_int();

/*
retourne une valeur en virgule flottante saisie au clavier, suivie du retour
� la ligne. On utilise double pour des raisons idiomatiques de C.
*/
double read_double();

/*
Les fonctions d'affichages sur la sortie standard, sans passage � la ligne
 */
void print_int(int entier);

void print_double(double v);

void print_char(char c);

//Pour afficher l'adresse d'une variable
void print_addr(void * p);
#endif // IOAP123_H_INCLUDED
