#include "package-merge.h"



cell * creer_cell(int p, listInt v)
{
    cell * c ;
    c =(cell *) malloc(sizeof(cell));
    c->poid=p;
    c->val=v;
    c->suivant=NULL;
    return c;
}

void inserer_par_poid(int p, listInt v, llist l)
{
    llist lt=l;
    while(lt!= NULL && lt->suivant!=NULL && lt->suivant->poid<p)
    {
        lt=lt->suivant;
    }
    cell* c=creer_cell(p,v);
    if(lt==NULL)
    {
        lt=c;
    }
    else
    {
        c->suivant=lt->suivant;
        lt->suivant=c;
    }
    
}


void free_list(llist l)
{
    if(l->suivant!=NULL)
    {
        free_list(l->suivant);
    }
    free_list_int(l->val);
    free(l);
}


int creer_list_from_tab(int tab_rep[], llist l)
{
    int n=0;
    int i;
    for(i=0;i<(int)sizeof(tab_rep);i++)
    {
        if(tab_rep[i]==0)
        {
            inserer_par_poid(tab_rep[i],creer_list_int(i),l);
            ajouter_longueur(0, i);
        }
        ajouter_longueur(1, i);
        n++;
    }
    return n;
}
int package(llist elems, llist groupement)
{
    int p=0;
    llist le=elems;
    free_list(groupement);
    groupement=NULL;
    llist lg=groupement;
    while(le!=NULL && le->suivant!=NULL && le->suivant->suivant!=NULL)
    {
        if(lg==NULL)
        {
            lg=creer_cell(((le->poid) +(le->suivant->poid)),fusion_deux_listes(le->val,le->suivant->val));
            p++;
            groupement=lg;
        }
        else
        {
            lg->suivant=creer_cell(((le->poid) +(le->suivant->poid)),fusion_deux_listes(le->val,le->suivant->val));
            p++;
            lg=lg->suivant;
        }
        le=le->suivant->suivant;
    }
    return p;
}


void merge(llist elem, llist groupement)
{
    llist lg=groupement;
    while(lg->suivant!=NULL)
    {
        inserer_par_poid(lg->poid,lg->val,elem);
        lg=lg->suivant;
    }
}
void incrementer_table_longueur(listInt lval)
{
    listInt lv=lval;
    while(lv!= NULL)
    {
        incrementer_longueur(lv->val);
        lv=lv->nxt;
    }
}



Arbre *creer_arbrePM(int tab_rep[])
{
    llist elems=NULL;
    llist le;
    int n=creer_list_from_tab(tab_rep, elems);
    llist groupement=NULL;
    int p= package(elems, groupement);
    while(p<(n-2))
    {
        merge(elems, groupement);
        p=package(elems, groupement);
    }
    le=elems;
    
    while (le->suivant!=NULL)
    {
        incrementer_table_longueur(le->val);
    }
    return(creerArbreCanonique());
    
    
    
}

void test_PM(int tab_rep[])
{
    Arbre * a;
    a =creer_arbrePM(tab_rep);
    printf("ICI OK");
    affiche_feuille_arbre(a);
}