#include <stdio.h>
#include "gestion_fichier.h"
 #include "arbre.h"

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
       while ((c=fgetc(nf)) != EOF)
       {
           affiche_bin_octet(c);
           printf("    %c   ||  ",c);
           c&= 255;
           affiche_bin_octet(c);
             printf("    %c   ",c);
            Tfreq[c]+=1;
            printf(" freq  = %d\n",Tfreq[c]);
            
        }
       fclose(nf);
    }
    else
    { 
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
    int i,n;
    int code[4]={0};
    int a;
    n=0;
    if (f != NULL)
    {
        int j=3;
        for (i=0; i<Nmax; i++) {
            //code=getCode(i) ; // GETCODE A FAIRE
            while(n!=0)
            {
                a=code[j]; 
                j--;
                while((n>=8) || (code[j]<8)){
                    code[j]= a & 255;
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

void test_gestion_fichier(){
     int * tab1;
    int i,j;
    
    //test du parcours de fichier 
    tab1 = parcours_fichier("test1.txt");
    printf("\n");
    //affichage des répétitions des caractères ascii
    for(i=0;i<256;i++)
    {
        printf("%c  ",i);
        if((i%40)==0)
        {
            printf(".\n");
            
        for(j=i-39;j<i;j++){
            printf("%d  ",tab1[j]);
            
        }
            printf("\n\n");
        }
        
    }
    
}


