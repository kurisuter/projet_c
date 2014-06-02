#ifndef GESTION_FICHIER_H
#define GESTION_FICHIER_H
#include <stdio.h>
#include <stdlib.h>
#include "../include/tab_longueur.h"
#define Nmax 256





void compression(  );
void decompression(  );


/* parcours du fichier en remplissant la table de frequence (table d'entier)*/
void parcours_fichier(char *nom, int t[]);

/*Initilsation a 0 du tableau de frequence*/
void initialisation(int t[]);

/*Affichage du tableau */
void affiche(int* tab);

void ecrire_en_tete(char* nom_avec);



/**********************
 * fonctions diverses *
 **********************/

void getCode(unsigned long long code[],int indice);

/*fonction de test du module */
void test_gestion_fichier();

#endif
