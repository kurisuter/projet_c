#include "list_int.h"

listInt creer_list_int1()
{
    listInt li =(listInt) malloc(sizeof(cell_int));
    li->val=0;
    li->nxt=NULL;
    return li;
}
listInt creer_list_int(int i)
{
    listInt li =creer_list_int1();
    li->val=i;
    return li;
}

void inserer_en_tete(int v, listInt li)
{
    listInt lt=li;
    li=creer_list_int(v);
    if(lt!=NULL)
    {
        li->nxt=lt;
    }
}

void inserer_queue(int i, listInt li)
{
    listInt lit=li;
    if(li==NULL)
    {
        li=creer_list_int(i);
    }
    else
    {
        while (lit->nxt!=NULL)
        {
            lit=lit->nxt;
        }
        lit->nxt=creer_list_int(i);
    }
}

listInt fusion_deux_listes(listInt l1, listInt l2)
{
    listInt l3=NULL;
    listInt l=l1;
    while(l->nxt!=NULL)
    {
        inserer_en_tete(l->val, l3);
    }
    l=l2;
     while(l->nxt!=NULL)
    {
        inserer_en_tete(l->val, l3);
    }
    return l3;
    
}
void free_list_int(listInt li)
{
    if(li->nxt!=NULL)
    {
       free_list_int(li->nxt);
    }
    free(li);
}
