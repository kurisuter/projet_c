#include "tab_longueur.h"

/***************************** 
 * initialisation du tableau *
 *****************************/
void creer_tab()
{
    int i,j;
    for(i=0;i<256;i++)
    {
        tab[i].longueur=0;
        for(j=0;j<3;j++)
        {
            tab[i].codage[j]=0;
        }
        
    }
}

//ajout d'un codage dans le tableau
void ajouter_codage_tab( unsigned long long int codage[], int indice)
{
    int i;
    for(i=0;i<3;i++)
    {
        tab[indice].codage[i]=codage[i];
    }
    
}
/*ajout de la longueur*/
void ajouter_longueur(int l, int indice)
{
    tab[indice].longueur=l;
}

void incrementer_longueur(int indice)
{
    tab[indice].longueur=((tab[indice].longueur) +1);
}



listInt getSymbole(int lg)
{
    int i;
    listInt ls=creer_list_int1();
    for(i=0;i<256;i++)
    {
        if(tab[i].longueur==lg)
        {
            inserer_queue(i,ls);
        }
    }
    return ls;
}

int get_lg_Max()
{
    int n=0;
    int i;
    for(i=0;i<256;i++)
    {
        if(n<tab[i].longueur)
        {
            n=tab[i].longueur;
        }
    }
    return n;
}

unsigned long long int getCode(int i)
{
    return tab[i].codage;
}