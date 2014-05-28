#include "tab_longueur.h"

/***************************** 
 * initialisation du tableau *
 *****************************/
void creer_tab()
{
    for(int i=0;i<256;i++)
      {
	tab[i]={NULL,0};
      }
    return tab;
}

//ajout d'un codage dans le tableau
void ajouter_codage_tab( int codage[], int indice)
{
    tab[indice]->codage=codage;
}
/*ajout de la longueur*/
void ajouter_longueur(int l, int indice)
{
    tab[indice]->longueur=l;
}

void incrementer_longueur(int indice)
{
    tab[indice]->longueur=((tab[indice]->longueur) +1);
}

