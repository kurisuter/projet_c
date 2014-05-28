/* 
 * File:   huffman.h
 * Author: kurisuter
 *
 * Created on 27 mai 2014, 11:17
 */

#ifndef HUFFMAN_H
#define	HUFFMAN_H
#include "arbre.h"

typedef struct _listch liste_chainee;
typedef struct _listch
{
	Arbre * arbre;
	struct _listch *suivant;
	
}liste_chainee;

/******************************************
 * opérations sur le tableau de répétition*
 * ****************************************/
//renvoie l'indice du "symbole" répété le moins souvent
int indice_minimum(int tab_repetition[]);
//renvoie la somme des éléments du tableau
int somme_element(int tab_repetition[]);

liste_chainee * ajouterElement(liste_chainee *liste, Arbre * a);
liste_chainee * supprimerElement(liste_chainee * liste, Arbre * arbre);
liste_chainee * tab_to_list(int tab_repetition[]);
//copie tab2 dans tab1
void copier_tab(int tab1[],int tab2[]);
//créé l'arbre de huffman à partir du tableau de répétition
Arbre * creer_arbre_huffman(int tab_repetition[]);

void afficher(liste_chainee * liste);
//test du module huffman
void test_huffman();
#endif	/* HUFFMAN_H */

