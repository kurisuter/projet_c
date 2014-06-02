#include "arbre.h"
#include "stdint.h"

/***************************** 
 * initialisation de l'arbre *
 *****************************/
/*permet de creer un arbre avec deux fils null et le symbole et la proba à 0*/
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

//affichage infixedes feuilles de l'arbre
void affiche_feuille_arbre(Arbre * a)
{
    if(a->fils_gauche != NULL)
        {
		affiche_arbre(a->fils_gauche);
	}
	affiche_bin_octet(a->symbole);
	if(est_feuille(a))
        {
            printf("%c %f \n ",a->symbole,a->proba);
        }
	if(a->fils_droit != NULL)
        {
		affiche_arbre(a->fils_droit);
	}
}

//affiche un octet de l'entier x en binaire
void affiche_bin_octet(int x)
{
    int i;
	for(i =7 ; i>=0 ; i--)
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

/*ajoute le bit b à droite dans la derniere case du tableau code et décale les bits dans les autres cases*/
void ajoute_bit_code(unsigned long long int c[], int b)
{
   int i;

    for(i=3;i>0;i++)
    {
        c[i]=(c[i]<< 1)|(c[i-1]>>63);
    } 
    c[0]=(c[0]<<1)|b;
}

/*fonction recursive utiliser dans recupererCode*/
void code(Arbre * a, unsigned long long int c[], int h)
{ 
    int i;
    if(est_feuille(a))
    {
        ajouter_codage_tab(c, a->symbole);
    }
    else
    {
        unsigned long long int cg[4];
        for(i=0;i<3;i++)
        {
            cg[i]=c[i];
        }
        ajoute_bit_code(cg,0);
        ajoute_bit_code(c,1);
        code(a->fils_droit,c,h+1);
        code(a->fils_gauche,cg,h+1);
    }
}


/*fonction qui parcours un arbre et inscrit le code correspondant à chaque symbole dans la table de longueur*/
void recupererCode(Arbre *ac)
{
    unsigned long long int c [4]={0,0,0,0};
    code(ac,c,0);
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
	affiche_arbre(a->fils_gauche);
	
}



/**********************
 * Arbre Canonique *
 **********************/
void ajouter_symbole(Arbre *a, int t, int num, int s)
{
    if(a==NULL)
    {
        a=creer_arbre();
    }
    if(t==0)
    {
        a->symbole=s;
    }
    else if(num>t)
    {
        ajouter_symbole(a->fils_gauche, (t/2), num, s);
    }
    else
    {
        ajouter_symbole(a->fils_droit, (t/2), num, s);
    }
}



Arbre * creerArbreCanonique()
{
    int h=0;
    int numElem;
    int Hmax=get_lg_Max();
    Arbre * ac=creer_arbre();
    while(h<Hmax)
    {
        listInt elems=getSymbole(h);
        numElem=1;
        while(elems!=NULL)
        {
            ajouter_symbole(ac,(pow(2,(h-1))),numElem,elems->val);
            elems=elems->nxt;
            numElem++;
        }
    }
    return ac;
}

