#include "arbre.h"
#include "stdint.h"

/***************************** 
 * initialisation de l'arbre *
 *****************************/
Arbre * creer_arbre()
{
	Arbre * un_arbre ;
	un_arbre =(Arbre *) malloc(sizeof(Arbre));
	initialiser_arbre(un_arbre);
	return un_arbre;
}

void initialiser_arbre(Arbre * un_arbre)
{
	un_arbre -> fils_droit = NULL;
	un_arbre -> fils_gauche = NULL;
	un_arbre -> symbole = 0;
	un_arbre -> proba = 0;
}


/************************ 
 * ajouts dans l'arbre  *
 ************************/

/* ajoute un parent commun aux deux premiers arbres en paramètre,
   on crée le noeud parent à partir de la symbole et de la probabilité */
Arbre * ajouter_nouveau_parent(Arbre * fg,Arbre * fd, int symbole, float proba)
{
	Arbre * p;
	p = creer_arbre();
	p->fils_gauche = fg;
	p->fils_droit = fd;
	p->symbole = symbole;
	p->proba = proba;
	return p; 
}

//ajout un parent (déja créé) commun aux deux premiers arbres en paramètre
void ajouter_parent(Arbre * fg,Arbre * fd, Arbre * p)
{
	p->fils_gauche = fg;
	p->fils_droit = fd;
}

/*************
 * booléens  *
 *************/

//l'arbre en paramètre est une feuille ? renvoie 1 si oui , si non renvoie -1
int est_feuille(Arbre * a)
{
	if((a->fils_gauche == NULL) &&(a->fils_droit == NULL))
        {
            return 1;
	}
        else
        {
            return -1;
	}
}

/*************
 * affichage *
 *************/

//affichage infixe
void affiche_arbre(Arbre * a)
{
	if(a->fils_gauche != NULL)
        {
		affiche_arbre(a->fils_gauche);
	}
	affiche_bin_octet(a->symbole);
	printf(" %f \n ",a->proba);
	if(a->fils_droit != NULL)
        {
		affiche_arbre(a->fils_droit);
	}
	
}

//affiche un octet de l'entier x en binaire
void affiche_bin_octet(int x)
{
	for(int i =7 ; i>=0 ; i--)
        {
		printf("%d",( (x>>i) & 1));
	}	
}

/**********************
 * fonctions diverses *
 **********************/


/*fonction qui remplis le champs "longeur" de la structure de tab_longeur à partir d'un arbre et de la hauteur du noeud (0 au commencement, utile que pour le recursif)*/
void longueur(Arbre * a, int h)
{
    if (est_feuille(a))
    {
        ajouter_longueur(h,a->symbole);
    }
    else
    {
        longueur(a->fils_droit, h+1);
        longueur(a->fils_gauche, h+1);
    }
}


/*fonction que remplis le champs "longeur" de la structure de tab_longeur à partir d'un arbre*/


/*fonction qui permet de creer un arbre canonique à partir d'une table de longueur*/
Arbre creerArbreCanonique()
{
    Arbre ac=creer_arbre();
   // int LongueurMax=recuperer_longueurMax(tl);
    return ac;
}

void traitement(int *c[], int b)
{
   
    for(int i=3;i>0;i++)
    {
        c[i]=(c[i]<<1)|(c[i-1]>>63);
    } 
    c[0]=(c[0]<<1)|b;
}

void code(Arbre * a, int c[], int h)
{ 
   
    if(est_feuille(a))
    {
        ajouter_codage_tab(c, a->symbole);
    }
    else
    {
        int cg[]=c;
        int cd[]=c;
        free(c);
        traitement(&cd,0);
        traitement(&cg,1);
        code(a->fils_droit,cd);
        code(a->fils_gauche,cg);
    }
}


/*fonction qui parcours un arbre et inscrit le code correspondant à chaque symbole dans la table de longueur*/
void recupererCode(Arbre *ac, tab_longueur *tl)
{
    long c [4]={0,0,0,0};
    code(ac,tl,c,0);
}
/*fonction de test du module arbre*/
void test_arbre()
{
	Arbre * a;
	Arbre * b;
	a=creer_arbre();
	b=creer_arbre();
	a = ajouter_nouveau_parent(a,b,'5',0.02);
	affiche_arbre(a);
	affiche_arbre(get_fils_gauche(a));
	
}

