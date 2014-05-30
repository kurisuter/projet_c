/* 
 * File:   arbre-canonique.h
 * Author: adele
 *
 * Created on 28 mai 2014, 17:00
 */

#ifndef ARBRE_CANONIQUE_H
#define	ARBRE_CANONIQUE_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arbre.h"


typedef struct s_List cell_symbole;
typedef cell_symbole* listSymbole;
struct s_List
{
    listSymbole nxt;
    int symbole;
};


listSymbole creer_list_symbole();
void inserer_queue(int s, listSymbole ls);
/*fonction qui permet de creer un arbre canonique à partir d'une table de longueur*/
Arbre creerArbreCannonique();

#endif	/* ARBRE_CANONIQUE_H */

