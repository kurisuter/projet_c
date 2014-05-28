#ifndef GESTION_FICHIER_H
#define GESTION_FICHIER_H
#include <stdio.h>
#include <stdlib.h>
#define Nmax 256





void compression(  );
void decompression(  );


/* parcours du fichier en remplissant la table de frequence (table d'entier)*/
int * parcours_fichier();

/*Initilsation a 0 du tableau de frequence*/
int *initialisation();

/*Affichage du tableau */
void affiche(int* tab);
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
void test();

#endif