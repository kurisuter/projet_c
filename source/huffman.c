#include "huffman.h"

//renvoie l'indice du "symbole" répété le moins souvent
int indice_minimum(int tab_repetition[])
{
    int i;
    int min=0;
    for(i=0;i<256;i++)
    {
        if((tab_repetition[i] < tab_repetition[min]) && (tab_repetition[i]!= 0))
        {
            min = i;
        }
    }
    return min; 
}

//renvoie la somme des éléments du tableau
int somme_element(int tab_repetition[])
{
    int i;
    int somme =0;
    for(i=0;i<256;i++)
    {
        somme+=tab_repetition[i];
    }
    return somme;
}

liste_chainee * ajouterElement(liste_chainee *liste, Arbre * a)
{
	liste_chainee * temp;
	temp = (liste_chainee *)malloc(sizeof(liste_chainee));
	temp->arbre = a;
	temp->suivant = liste;
	return temp;
}

liste_chainee * supprimerElement(liste_chainee * liste, Arbre * arbre)
{
	liste_chainee * temp;
	liste_chainee * elem_precedent;
	int trouve = 0;
	temp =liste;
	elem_precedent= temp;
	while((temp != NULL) && (trouve !=1) )
        {
		if(temp->arbre == arbre)
                {
			trouve = 1;
		}
                else
                {
			elem_precedent = temp;
			temp = temp->suivant;
		}
	}
	if(trouve == 1)
        {
		if(elem_precedent == temp)
                {
			liste = temp->suivant;	
		}
                else
                {
			elem_precedent->suivant = temp->suivant;
		}
	}
	return liste;
}

liste_chainee * tab_to_list(int tab_repetition[])
{
    int i;
    liste_chainee *liste =NULL;
    Arbre * a;
    for(i=0;i<256;i++)
    {
        if(tab_repetition[i] !=0)
        {
           //printf("\n on ajoute %c = %d", i, tab_repetition[i]);
            a = ajouter_nouveau_parent(NULL,NULL,i,tab_repetition[i]);
            liste =ajouterElement(liste,a);
            
	}
    }
    return liste;
            
}

//
Arbre * recherche_mini(liste_chainee *liste)
{
	liste_chainee * temp;
	Arbre * arbre;
	temp=liste;
	arbre = temp->arbre;
	temp = temp->suivant;
	while(temp != NULL)
        {
		if(temp->arbre->proba < arbre->proba)
                {
			arbre = temp->arbre;
		}
		temp = temp->suivant;
	}
	return arbre;
}

//créé l'arbre de huffman à partir du tableau de répétition
Arbre * creer_arbre_huffman(int tab_repetition[])
{
    Arbre * a;
    Arbre * a1;
    Arbre * a2;
    liste_chainee *liste;
    int taille_fichier = somme_element(tab_repetition);
    
    liste = tab_to_list(tab_repetition);
    afficher(liste);
    while(liste->arbre->proba != taille_fichier)
    {
        a1 = recherche_mini(liste);
        liste = supprimerElement(liste, a1);
        a2 = recherche_mini(liste);
        liste = supprimerElement(liste, a2);
        a = ajouter_nouveau_parent(a1,a2,0,((a1->proba) +(a2->proba)));
        //printf("proba : a1 %d  a2 %d  a %d \n",a1->proba,a2->proba,a->proba);
        liste= ajouterElement(liste, a);
    }
    
    return liste->arbre;
}

void remplir_tab_longueur(Arbre * a)
{
    longueur(a,0);
    a = creerArbreCanonique();
    recupererCode(a);
}

void arbre_decompression()
{
    
}

void afficher(liste_chainee * liste)
{
	liste_chainee *temp;
	temp = liste;
	while(temp != NULL)
        {
		if(temp->arbre !=NULL)
                {
			printf(" %c : %d \n",temp->arbre->symbole ,temp->arbre->proba);
		}
                else
                {
			printf("\nELEMENT VIDE");		
		}
		temp = temp->suivant;
	}
	printf("\n");
}

//test du module huffman
void test_huffman()
{
    int tab[256] = {0};
    Arbre * a;
    tab[5]= 2;
    tab[4]= 3;
    tab[19] =4;
    tab[22] =4;
    tab[11] =6;
    
    a = creer_arbre_huffman(tab);
    affiche_arbre(a);
}