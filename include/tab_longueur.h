#ifndef TAB_LONGUEUR_H
#define TAB_LONGUEUR_H
#include <stdio.h>
#include <stdlib.h>
#include "list_int.h"

typedef struct Struct_code struct_code;
typedef struct Struct_code
{
	unsigned long long int codage[4];
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
void ajouter_codage_tab( unsigned long long int codage[],int indice);

/*ajout de la longueur*/
void ajouter_longueur(int l, int indice);

void incrementer_longueur(int indice);

listInt getSymbole(int lg);

int get_lg_Max();

unsigned long long int getCode(int i);
#endif