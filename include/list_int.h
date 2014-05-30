/* 
 * File:   list_symbole.h
 * Author: adele
 *
 * Created on 30 mai 2014, 11:22
 */

#ifndef LIST_INT_H
#define	LIST_INT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_List cell_int;
typedef cell_int* listInt;
struct s_List
{
    listInt nxt;
    int val;
};


listInt creer_list_int1();
listInt creer_list_int(int i);
void inserer_en_tete(int v, listInt li);
void inserer_queue(int v, listInt li);
listInt fusion_deux_listes(listInt l1, listInt l2);
void free_list_int(listInt li);

#endif	/* LIST_SYMBOLE_H */

