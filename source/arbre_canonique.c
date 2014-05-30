#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "arbre-canonique.h"

listSymbole creer_list_symbole(int s)
{
    listSymbole ls =(listSymbole) malloc(sizeof(cell_symbole));
    ls->symbole=s;
    ls->nxt=NULL;
    return ls;
}
void inserer_queue(int s, listSymbole ls)
{
    listSymbole lst=ls;
    if(ls==NULL)
    {
        ls=creer_list_symbole(s);
    }
    else
    {
        while (lst->nxt!=NULL)
        {
            lst=lst->nxt;
        }
        lst->nxt=creer_list_symbole(s);
    }
    
    
}
void ajouter_symbole(Arbre *a, int t, int num, int s)
{
    if(a==NULL)
    {
        a=creer_arbre();
    }
    if(t==0)
    {
        a->symbole=s;
    }
    else if(num>t)
    {
        ajouter_symbole(a->fils_gauche, (t/2), num, s);
    }
    else
    {
        ajouter_symbole(a->fils_droit, (t/2), num, s);
    }
}

Arbre creerArbreCannonique()
{
    int h=0;
    int numElem=1;
    int Hmax=get_lg_Max();
    Arbre ac=creer_arbre();
    while(h<Hmax)
    {
        listSymbole elems=getSymbole(h);
        while(elems!=NULL)
        {
            ajouter_symbole(ac,(pow(2,(h-1))),numElem,elems->symbole)
        }
    }
}
