#ifndef GESTION_FICHIER_H
#define GESTION_FICHIER_H
#include <stdio.h>
#include <stdlib.h>
#include "tab_huff.h"
#include "arbre.h"

typedef struct Fics Fichier;
typedef struct Fics
{
	int nb_caracteres;
	int tab_huff;
}Fichier;

/***************************** 
 * initialisation *
 *****************************/

//rempli le tableau avec la probabilité d'apparition de chaque caractère
Fichier * initialisation(char * nom_fichier);

/******************************************
 *    *
 ******************************************/
void compression(  );
void decompression(  );
/*************
 * booléens  *
 *************/


/*************
 * affichage *
 *************/

/**********************
 * fonctions diverses *
 **********************/

/*fonction de test du module */
void test_();

#endif
