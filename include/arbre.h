#ifndef ARBRE_H
#define ARBRE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Arbres Arbre;
typedef struct Arbres
{
	Arbre * fils_gauche;
	Arbre * fils_droit;
	int symbole;
	float proba;
}Arbre;

/***************************** 
 * initialisation de l'arbre *
 *****************************/
Arbre * creer_arbre();
void initialiser_arbre(Arbre * un_arbre);


/************************ 
 * ajouts dans l'arbre  *
 ************************/

/*ajoute un parent commun aux deux premiers arbres en paramètre,
on crée le noeud parent à partir de la symbole et de la probabilité
*/
Arbre * ajouter_nouveau_parent(Arbre * fg,Arbre * fd, int symbole, float proba);
//ajout un parent (déja créé) commun aux deux premiers arbres en paramètre
void ajouter_parent(Arbre * fg,Arbre * fd, Arbre * p);

/******************************************
 *  récupération d'un élément de l'arbre  *
 ******************************************/
Arbre * get_fils_gauche(Arbre * a);
Arbre * get_fils_droit(Arbre * a);

/*************
 * booléens  *
 *************/

//l'arbre en paramètre est une feuille ? renvoie 1 si oui , si non renvoie -1
int est_feuille(Arbre * a);

/*************
 * affichage *
 *************/

//affichage infixe
void affiche_arbre(Arbre * a);

//affiche un octet de l'entier x en binaire
void affiche_bin_octet(int x);

/**********************
 * fonctions diverses *
 **********************/

/*fonction de test du module arbre*/
void test_arbre();

#endif