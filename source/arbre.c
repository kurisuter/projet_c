#include "arbre.h"

/***************************** 
 * initialisation de l'arbre *
 *****************************/
Arbre * creer_arbre(){
	Arbre * un_arbre ;
	un_arbre =(Arbre *) malloc(sizeof(Arbre));
	initialiser_arbre(un_arbre);
	return un_arbre;
}

void initialiser_arbre(Arbre * un_arbre){
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
Arbre * ajouter_nouveau_parent(Arbre * fg,Arbre * fd, int symbole, float proba){
	Arbre * p;
	p = creer_arbre();
	p->fils_gauche = fg;
	p->fils_droit = fd;
	p->symbole = symbole;
	p->proba = proba;
	return p; 
}

//ajout un parent (déja créé) commun aux deux premiers arbres en paramètre
void ajouter_parent(Arbre * fg,Arbre * fd, Arbre * p){
	p->fils_gauche = fg;
	p->fils_droit = fd;
}

/******************************************
 *  récupération d'un élément de l'arbre  *
 ******************************************/

Arbre * get_fils_gauche(Arbre * a){
	return a -> fils_gauche;
}

Arbre * get_fils_droit(Arbre * a){
	return a -> fils_droit;
}
/*************
 * booléens  *
 *************/

//l'arbre en paramètre est une feuille ? renvoie 1 si oui , si non renvoie -1
int est_feuille(Arbre * a){
	if((a->fils_gauche == NULL) &&(a->fils_droit == NULL)){
		return 1;
	}else{
		return -1;
	}
}

/*************
 * affichage *
 *************/

//affichage infixe
void affiche_arbre(Arbre * a){
	if(a->fils_gauche != NULL){
		affiche_arbre(a->fils_gauche);
	}
	affiche_bin_octet(a->symbole);
	printf(" %f \n ",a->proba);
	if(a->fils_droit != NULL){
		affiche_arbre(a->fils_droit);
	}
	
}

//affiche un octet de l'entier x en binaire
void affiche_bin_octet(int x){
	int i; 
	int k =7;
	for(i =k ; i>=0 ; i--){
		printf("%d",( (x>>i) & 1));
	}	
}

/**********************
 * fonctions diverses *
 **********************/
/*fonction de test du module arbre*/
void test_arbre(){
	Arbre * a;
	Arbre * b;
	a=creer_arbre();
	b=creer_arbre();
	a = ajouter_nouveau_parent(a,b,'5',0.02);
	affiche_arbre(a);
	affiche_arbre(get_fils_gauche(a));
	
}

