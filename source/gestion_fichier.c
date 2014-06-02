#include <stdio.h>
#include "gestion_fichier.h"
 #include "arbre.h"
 #include "huffman.h"

/***************************** 
 * initialisation *
 *****************************/

//rempli le tableau avec la probabilité d'apparition de chaque caractère

void parcours_fichier(char * nom, int Tfreq[])

{   
    FILE * nf;
    nf =fopen(nom, "r");
    int c;
    initialisation(Tfreq);
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
    
}   


/*Initilsation a 0 du tableau de frequence*/
void initialisation(int t[])
{
	int i; 
	for (i = 0; i < Nmax; i ++)
	{
		t[i] = 0;
	}
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

void ecrire_code(char * nom,char * nom1)
{
    FILE * f;
    FILE * f1;
    f =fopen(nom, "r");
    f1 =fopen(nom1, "a+");
    int x,c;
    unsigned long long code[4]={0};
    int j=0;
    int l;
    if (f != NULL)
    {
        while ((c=getc(f)) !=EOF) {
            c&=255;
            getCode(code,c);
            l = tab[c].longueur;
            x=256-l;
            while(x>64){
                x=x-6;
                j++;
            }
            x=64-x;
            while(j != 4){
                while (x != 0){
                    putc((code[j]>>(x-1)) & 255 ,f1);
                    x--;
           
                }
                x=64;
                j++;
                        
            }
        }
        fclose(f);
    }
    else{
         printf("Impossible d'ouvrir le fichier ");
        
    }

    
}

void getCode(unsigned long long code[],int indice)
{
    int i;
    for(i=0;i<4;i++)
    {
        code[i] = tab[indice].codage[i];
    }
}

void compression_huffman()
{
}

void compression_package_merge()
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
     int tab1[Nmax];
    int i,j;
    Arbre * a;
    
    //test du parcours de fichier 
    parcours_fichier("test1.txt",tab1);
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
    a = creer_arbre_huffman(tab1);
    affiche_feuille_arbre(a);
    remplir_tab_longueur(a);
    //affiche_longueur();
    ecrire_en_tete("fichier_compress.txt");
    ecrire_code("test1.txt","fichier_compress.txt");
    
}




