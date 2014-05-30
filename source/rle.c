#include <stdio.h>
#include <stdlib.h>
#include "rle.h"

FILE * rle(FILE * f)
{
    FILE * fcode;
    unsigned int car, comp,n;
    fcode =fopen("nouveau_fichier.txt", "w+");
    n=0;
    comp=EOF; 
    if (fcode != NULL)
    {
        while ((car=fgetc(f)) != EOF)
        {
            car = car & 255;
                affiche_bin_octet(car);
                printf("  %c    n : %c  %d\n",car,n,n);
            if(car != comp)
            { 
                
                if(n>=2)
                {
                    fputc(('0'+ n -2),fcode);
                    fputc(car,fcode);
                    comp=car;
                }
                else
                {
                    fputc(car,fcode);
                    comp=car;
                }
                n=1;
            }
            else
            {
                if(n<2)
                {
                    
                    fputc(car,fcode);
                    n++;
                }else
                {
                    n++;
                }
            }
        }
        fclose(fcode);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier nouveau_fichier.txt");
    }
    return fcode;
}

FILE * rle_r(FILE * f)
{
    FILE * fdecode;
    unsigned int car, comp,n,i;
    fdecode =fopen("rle_decode.txt", "w+");
    n=0;
    comp=EOF; 
    if (fdecode != NULL)
    {
        while ((car=fgetc(f)) != EOF)
        {
            if(car != comp)
            {
                if(n>=2)
                {
                    
                    for(i=0;i<(car-'0');i++)
                    {
                        fputc(comp,fdecode);
                    }
                }
                else
                {
                    fputc(car,fdecode);
                    comp=car;
                }
                n=1;
            }
            else
            {
                if(n<2)
                {
                    
                    fputc(car,fdecode);
                    n++;
                }else
                {
                    n++;
                }
            }
        }
        fclose(fdecode);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier nouveau_fichier.txt");
    }
    return fdecode;
}


void test_rle(char * nom)
{
    FILE * f;
    f = fopen(nom,"r");
    if (f != NULL)
    {
        rle(f);
        fclose(f);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier %s",nom);
    }
    f = fopen("nouveau_fichier.txt","r");
    if (f != NULL)
    {
        rle_r(f);
        fclose(f);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier nouveau_fichier.txt");
    }
}
