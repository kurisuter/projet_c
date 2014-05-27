#include "package-merge.h"


cell * creer_cell(int p, int v)
{
    cell * c ;
    c =(cell *) malloc(sizeof(cell));
    c->poid=p;
    c->val=creer_cell(v);
    c->suivant=NULL;
    return c;
}

cell * creer_cell(int p, listVal v)
{
    cell * c ;
    c =(cell *) malloc(sizeof(cell));
    c->poid=p;
    c->val=v;
    c->suivant=NULL;
    return c;
}

void inserer_en_tete_val(int v, listVal lv)
{
    listVal lt=lv;
    lv=creer_cell_val(v);
    if(lt!=NULL)
    {
        lv->nxt=lt;
    }
}



listVal fusion_deux_listes(listVal l1, listVal l2)
{
    listVal l3=NULL;
    listVal l=l1;
    while(l->nxt!=NULL)
    {
        inserer_en_tete_val(l->val, l3);
    }
    l=l2;
     while(l->nxt!=NULL)
    {
        inserer_en_tete_val(l->val, l3);
    }
    
}




void inserer_par_poid(int p, listVal v, llist l)
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
void free_list_val(listVal lv)
{
    if(lv->nxt!=NULL)
    {
       free_list(lv->nxt);
    }
    free(lv);
}


void free_list(llist l)
{
    if(l->suivant!=NULL)
    {
        free_list(l->suivant);
    }
    free_list_val(l->val);
    free(l);
}


int creer_list_from_tab(int tab_rep[], llist l)
{
    int n=0;
    for(int i=0;i<(int)sizeof(tab_rep);i++)
    {
        if(tab_rep[i]==0)
        {
            inserer_par_poid(tab_rep[i],i,l);
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
void incrementer_table_longueur(listVal lval)
{
    listVal lv=lval;
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
    int n=creer_list_from_tab(tab_rep[], elems);
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
    return(creerArbreCannonique());
    
    
    
}