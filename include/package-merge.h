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

typedef struct cell_val cell_val;
struct cell_val
{
    int val;
    struct cell_val *nxt;
};
typedef cell_val* listVal;

typedef struct cell cell;
struct cell
{
    int poid;
    cell_val *val;
    struct cell *suivant;
};
 
typedef cell* llist;
cell_val * creer_cell_val(listVal v);
cell * creer_cell(int p, int v);
void inserer_en_tete_val(int v, listVal lv);
void inserer_par_poid(int p, int v, llist l);
listVal fusion_deux_listes(listVal l1, listVal l2);
void free_list_val(listVal lv);
void free_list(llist l);

llist creer_list_from_tab(int tab_rep[]);
int package(llist elem, llist groupement);
void merge(llist elem, llist groupement);
Arbre * creer_arbrePM(int tab_repetition[]);


#endif	/* PACKAGE_MERGE_H */

