/* 
 * File:   mtf.hvoid mtf(int tab_code_precedent[]);
void intervertir(int tab[],int i,int j);
void avancer_i(int tab[],int i);
 * Author: kurisuter
 *
 * Created on 27 mai 2014, 20:17
 */

#ifndef MTF_H
#define	MTF_H

unsigned int tab[256];

void affiche_tab();

void initialisation_tab_mtf();

//interverti les donnée aux indices i et j
void intervertir(int i,int j);

//met l'entier à l'indice i en première place et décale les entiers d'indice 0 à i-1
void avancer_i(int i);

//recherche un entier dans le tableau et le renvoie
unsigned int rechercher_elem(unsigned int e);

//recherche un entier dans le tableau et renvoie son indice
int rechercher_indice(unsigned int e);

//encodage mtf
FILE * mtf(FILE * f);
//décodage mtf
FILE * mtf_r(FILE * f);


void test_mtf();

#endif	/* MTF_H */

