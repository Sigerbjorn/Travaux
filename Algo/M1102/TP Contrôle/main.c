#include <stdio.h>
#include <stdlib.h>
#include "../ioap123.h"

void entrerValMat(int** mat, int l, int c){
    int i,j;
    for (i=0; i<l; i=i+1){
        for (j=0; i<c; j=j+1){
            mat[j][i] = read_int();
        }
    }

}

void afficherValMat(int** mat, int l, int c){
    int i,j;
    for (i=0; i<l; i=i+1){
        for (j=0; i<c; j=j+1){
            print_int()
        }
    }
}


int main()
{
    int mat[3][3];
    print_text("Hello");
    //entrerValMat(mat, 6, 6);
    return 0;
}
