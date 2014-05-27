#include "../include/gestion_fichier.h"
#include <stdio.h>

/***************************** 
 * initialisation *
 *****************************/

//rempli le tableau avec la probabilité d'apparition de chaque caractère

int * parcours_fichier()

{   
    int c;
    int *Tfreq;
    Tfreq=initialisation();
       
        while ((c = getchar()) != EOF){
            
            Tfreq[c]=Tfreq[c]+1;
            
        }
    

    return Tfreq;}   


/*Initilsation a 0 du tableau de frequence*/
int *initialisation()
{	int *tabl;
	int i; 
	tabl = (int *)malloc(Nmax* sizeof(int));// allocation memoire pour le tableau
	if (tabl==NULL){exit(EXIT_FAILURE);}
	for (i = 0; i < Nmax; i ++)
	{
		
		tabl[i] = 0;
	}
        return tabl;
}

