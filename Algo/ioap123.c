#include "ioap123.h"

text define_size( int taille) {
 return malloc(taille+1);
}

//une fonction  qui ne déborde pas et ne mémorise pas le '\n'
text read_line() {
  text txt;
  int lg;
  char phrase[256];
  fgets(phrase,256,stdin);
  lg=strlen(phrase);
  txt = define_size(lg);
  //éliminer le '\n' mémorisé par fgets si nécessaire
  if (phrase[lg-1]=='\n') phrase[lg-1]=0;
  strcpy(txt,phrase);
  return txt;
}

char read_char()
{
	char c;
	scanf("%c",&c);
	fflush(stdin);
	fflush(stdin);
	return c;
}

int read_int() {
  text input_tmp;
  int entier;
  input_tmp=read_line();
  entier=atoi(input_tmp);
  return entier;
}

double read_double() {
  text input_tmp;
  double v;
  input_tmp=read_line();
  v=atof(input_tmp);
  return v;
}

void print_int(int entier) {
 printf("%i", entier);
 fflush(stdout);
}

void print_double(double dec) {
 printf("%lf",dec);
 fflush(stdout);
}

void print_char(char c) {
 printf("%c",c);
 fflush(stdout);
}

void print_text(text txt) {
  printf("%s",txt);
 fflush(stdout);
}

void print_newLine() {
 printf("\n");
}

void print_addr(void * p){
  printf("%p",p);
}
