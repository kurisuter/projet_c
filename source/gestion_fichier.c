    #include "../include/gestion_fichier.h"
#include <stdio.h>

/***************************** 
 * initialisation *
 *****************************/

//rempli le tableau avec la probabilité d'apparition de chaque caractère

int * parcours_fichier(char * nom)

{   
    FILE * nf;
    nf =fopen(nom, "r");
    int c;
    int *Tfreq;
    Tfreq=initialisation();
    if (nf != NULL)
    {
       while ((c=fgetc(nf)) != EOF){
            
            Tfreq[c]=Tfreq[c]+1;
            
        }
       fclose(nf);}
    else{ 
        printf("Impossible d'ouvrir le fichier");
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

// Pour en_tete du fichier (tableau de longueur)
void ecrire_en_tete(char* nom_avec)
{
	FILE * f;
	f =fopen(nom_avec, "w+");
	int i;
	if (f != NULL)
    {	
    	
    	for (i=0; i<Nmax;i++)
    	{
    			char lg_char = (char)(((int)'0')+tab[i].longueur);
    			fputc(lg_char,f);
    			fputc('\n',f);
    			
    		
    	}
    	
    	fclose(f);
    	
  
    	
    	}
    else
    {
        printf("Impossible d'ouvrir le fichier ");
    }
}

void ecrire_code(char * nom)
{
    FILE * f;
    f =fopen(nom, "a+");
    int i;
    int code[4];
    int a;
    if (f != NULL)
    {
        int j=3;
        for (i=0; i<Nmax; i++) {
            code=getCode(i) ; // GETCODE A FAIRE
            while(n!=0)
            {
                a=code[j]; 
                j--;
                while((n>=8) || (code<8)){
                    code= a & 255;
                    a=a>>8;
                }
             
            }
            
        }
    }
    else{
         printf("Impossible d'ouvrir le fichier ");
        
    }

    
}
void compression()
{
}
/*************
 * booléens  *
 *************/


/*************
 * affichage *
 *************/

void affiche(int*tab)
{
	int j;
	
	for (j=0;j<Nmax;j++){
			printf("%d",tab[j]);}
	printf("\n");

}




/**********************
 * fonctions diverses *
 **********************/




