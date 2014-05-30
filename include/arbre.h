#ifndef ARBRE_H
#define ARBRE_H
#include <stdio.h>
#include <stdlib.h>
#include "tab_longueur.h"
#include "list_int.h"

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
/*permet de creer un arbre avec deux fils null et le symbole et la proba à 0*/
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


/*fonction qui remplis le champs "longeur" de la structure de tab_longeur à partir d'un arbre et de la hauteur du noeud (0 au commencement, utile que pour le recursif)*/
void longueur(Arbre * a, int h);

/*ajoute le bit b à droite dans la derniere case du tableau code et décale les bits dans les autres cases*/
void ajoute_bit_code(unsigned long long c[], int b);

/*fonction recursive utiliser dans recupererCode*/
void code(Arbre * a, unsigned long long c[], int h);

/*fonction qui parcours un arbre et inscrit le code correspondant à chaque symbole dans la table de longueur*/
void recupererCode(Arbre *ac);

/*fonction de test du module arbre*/
void test_arbre();

/**********************
 * Arbre Canonique *
 **********************/

void ajouter_symbole(Arbre *a, int t, int num, int s);

/*permet de creer un arbre Canonique en utilisant la table de longueur*/
Arbre * creerArbreCanonique();














#endif
