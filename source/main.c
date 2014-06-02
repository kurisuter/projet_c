#include <stdio.h>
#include <stdlib.h>
#include "gestion_fichier.h"
#include "package-merge.h"




int main()
{
    int * tab1;
    int t[256];
    int i;
    tab1 = parcours_fichier("test1.txt");
    for(i=0;i<256;i++)
    {
        t[i]=tab1[i];
    }
    printf("\n ICI OK \n");
    test_PM(t);
    return 0;
}
