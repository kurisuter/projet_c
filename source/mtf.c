#include <stdio.h>
#include <stdlib.h>
#include "mtf.h"

void initialisation_tab_mtf()
{
    unsigned int i;
    for(i=0;i<256;i++)
    {
        tab[i]=i;
    }
}
void affiche_tab()
{
    unsigned int i,j;
    printf("\n");
    for(i=0;i<256;i++)
    {
        printf("%c  ",i);
        if((i%40)==0)
        {
            printf(".\n");
            
        for(j=i-40;j<i;j++){
            printf("%c  ",tab[j]);
            
        }
            printf("\n\n");
        }
        
    }
    
    printf("\n SUIVANT \n");
}

FILE * mtf(FILE * f)
{
    FILE * nf;
    unsigned int c,symbole;
    initialisation_tab_mtf();
    nf =fopen("nouveau_fichier.txt", "w+");
    if (nf != NULL)
    {
        while ((c=fgetc(f)) != EOF)
        {
            symbole = c &255;
            c = rechercher_indice(symbole);
            fputc(c,nf);
            avancer_i(c);
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
    unsigned int c,symbole;
    initialisation_tab_mtf(tab);
    nf =fopen("mtf_decode.txt", "w+");
    if (nf != NULL)
    {
        while ((c=fgetc(f)) != EOF)
        {
            symbole = c &255;
            c = tab[symbole];
            fputc(c,nf);
            avancer_i(symbole);
        }
        fclose(nf);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier mtfdecode.txt");
    }
    return nf;
    
}
//interverti les donnée aux indices i et j
void intervertir(int i,int j)
{
    unsigned int temp;
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
unsigned int rechercher_elem(unsigned int e)
{
    return tab[e];
}

//recherche un entier dans le tableau et renvoie son indice
int rechercher_indice(unsigned int e)
{
    int i =0;
    while((i<256) && (tab[i]!=e))
    {
        i++;
    }
    return i;
}

void test_mtf(){
    FILE * f;
    f = fopen("test1.txt","r");
    
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




