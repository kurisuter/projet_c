#ifndef TAB_LONGUEUR_H
#define TAB_LONGUEUR_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Struct_code struct_code;
typedef struct Struct_code
{
	int codage[4];
	int longueur;
}struct_code;

/*tableau statique*/
typedef struct_code tab_longueur[256];

tab_longueur tab;

/***************************** 
 * initialisation du tableau *
 *****************************/
void creer_tab();

//ajout d'un codage dans le tableau
void ajouter_codage_tab( int codage[], int longueur, int indice);

/*ajout de la longueur*/
void ajouter_longueur(int l, int indice);

void incrementer_longueur(int indice);


#endif