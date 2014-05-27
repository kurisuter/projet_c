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
Fichier * creer_fichier();
Void initialisation(Fichier fichier);

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
