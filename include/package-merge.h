/* 
 * File:   Package-merge.h
 * Author: adele
 *
 * Created on 28 mai 2014, 08:25
 */

#ifndef PACKAGE_MERGE_H
#define	PACKAGE_MERGE_H
#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

typedef struct cell cell;
struct cell
{
    int poid;
    listInt val;
    struct cell *suivant;
};
 
typedef cell* llist;
cell * creer_cell(int p, listInt v);
void inserer_par_poid(int p, listInt v, llist l);
void free_list(llist l);
int creer_list_from_tab(int tab_rep[], llist l);
int package(llist elem, llist groupement);
void merge(llist elem, llist groupement);
Arbre * creer_arbrePM(int tab_repetition[]);


#endif	/* PACKAGE_MERGE_H */

