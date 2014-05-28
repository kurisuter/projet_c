#include <stdio.h>
#include <stdlib.h>
#include "mtf.h"

void affiche_montab(int tab[])
{
    int i;
    for(i=0; i<256;i++){
        printf("%c %c",i ,tab[]);
    }
}

void initialisation_tab_mtf()
{
    int i;
    for(i=0;i<256;i++)
    {
        tab[i]=i;
    }
}

FILE * mtf(FILE * f)
{
    FILE * nf;
    int c,i,symbole;
    initialisation_tab_mtf();
    i=0;
    nf =fopen("nouveau_fichier.txt", "w+");
    if (nf != NULL)
    {
        while ((c=fgetc(f)) != EOF)
        {
            printf(" %c avant :%d ",c, c );
            symbole = c &255;
            printf("symbole : %d ",symbole);
            c = rechercher_indice(symbole);
            printf("%c apres : %d\n",c,c);
            fputc(c,nf);
            avancer_i(c);
            i++;
        }
        fclose(nf);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier nouveau_fichier.txt");
    }
    return nf;
    
}
FILE * mtf_r(FILE * f)
{
    FILE * nf;
    int c,i,symbole;
    initialisation_tab_mtf();
    i=0;
    nf =fopen("mtf_decode.txt", "w+");
    printf("\n DECODAGE \n");
    if (nf != NULL)
    {
        while ((c=fgetc(f)) != EOF)
        {
            
            printf(" %c avant :%d ",c,c );
            symbole = c &255;
            printf("symbole : %d ",symbole);
            c = rechercher_elem(symbole);
            printf(" %c après :%d \n",c,c );
            fputc(c,nf);
            avancer_i(c);
            i++;
        }
        fclose(nf);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier nouveau_fichier.txt");
    }
    return nf;
    
}
//interverti les donnée aux indices i et j
void intervertir(int i,int j)
{
    int temp;
    temp = tab[i];
    tab[i]=tab[j];
    tab[j]=temp;
}

//met l'entier à l'indice i en première place et décale les entiers d'indice 0 à i-1
void avancer_i(int i)
{
    int j;
    for(j=i;j>=1;j--)
    {
        intervertir(j,j-1);
    }
}

//recherche un entier dans le tableau et le renvoie
int rechercher_elem(int e)
{
    return tab[e];
}

//recherche un entier dans le tableau et renvoie son indice
int rechercher_indice(int e)
{
    int i =0;
    while((i<256) && (tab[i]!=e))
    {
        i++;
    }
    if(i==256)
    {
        i=-1;
    }
    return i;
}

void test_mtf(char* nom)
{
    FILE * f;
    f = fopen(nom,"r");
    
    if (f != NULL)
    {
        mtf(f);
        fclose(f);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier nouveau_fichier.txt");
    }
    
    f = fopen("nouveau_fichier.txt","r");
    if (f != NULL)
    {
        mtf_r(f);
        fclose(f);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier nouveau_fichier.txt");
    }
}




