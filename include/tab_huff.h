#ifndef TAB_HUFF_H
#define TAB_HUFF_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Struct_code struct_code;
typedef struct Struct_code
{
	int symbole;// le prof a dit qu'on compresse une liste d'octets quel que soit le fichier ... c'est à dire 
	float proba;
	int * codage;
	int longueur;
}struct_code;

/*tableau dynamique*/
typedef struct_code * tab_huff;

/***************************** 
 * initialisation du tableau *
 *****************************/
tab_huff * creer_tab();
void initialiser_tab(tab_huff * tab);

//ajout d'un symbole dans le tableau
void ajouter_symbole_tab(tab_huff * tab);

//supression d'un symbole dans le tableau
void retirer_symbole_tab(tab_huff * tab);


#endif

