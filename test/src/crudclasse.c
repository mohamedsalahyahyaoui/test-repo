#include <stdio.h>
#include "crud.h"
#include <stdlib.h>
#include <string.h>

void ajouter_classe(Classe C)
{
    int x;
    FILE *f;


    f=fopen("classe.txt","a+");

    if(f!=NULL)
    {

     fprintf(f,"%s %d \n",C.nom_classe ,C.id_classe);

        }
        fclose(f);


    }

    void modifier_classe(int id_classe,Classe C)
{
    FILE *f;
    FILE *temp;
    Classe C1;

    f=fopen("classe.txt","r");
    temp=fopen("temp.txt","w");


    if(f!=NULL)
    {

        while((fscanf(f,"%s %d  \n",C1.nom_classe, &C1.id_classe)!=EOF))
       {


            if(C1.id_classe!=id_classe)
            {
                fprintf(temp,"%s %d  \n",C1.nom_classe,C1.id_classe); 
            }
         else
            {

            fprintf(temp,"%s %d  \n",C.nom_classe, id_classe );

            }
        }


    }

    fclose(temp);
    fclose(f);
    remove("classe.txt");
    rename("temp.txt","classe.txt");

}


void supprimer_classe(int id_classe)
{
    FILE *f;
    FILE *temp;
    Classe C;

    f=fopen("classe.txt","a+");
    temp=fopen("temp.txt","w");

    if(f!=NULL)
    {
        while((fscanf(f,"%s %d  \n",C.nom_classe,&C.id_classe))!=EOF)
        {
           if(C.id_classe != id_classe)
            {
                fprintf(temp,"%s %d  \n", C.nom_classe,C.id_classe);
            }
        }


    }
    fclose(temp);
    fclose(f);
    remove("classe.txt");
    rename("temp.txt","classe.txt");
}



int chercher_classe(int id_classe, Classe * C)
{
    FILE *f;
    Classe C1;
    int x=1;

    f=fopen("classe.txt","r");
    while((fscanf(f,"%s %d  \n",C1.nom_classe, &C1.id_classe)!=EOF) &&(x!=0))
    {
        if (id_classe==C1.id_classe)
        {
          x=0;

            strcpy(C->nom_classe,C1.id_classe);
          
            (C->id_classe)=C1.id_classe;

        }
        fclose(f);


    }
    return x;
}


int taille_fichier_classe()
{
    Classe C ;
    FILE *f;
    int n;

    f=fopen("classe.txt","r");
    while((fscanf(f,"%s %d \n",C.nom_classe,&C.id_classe)!=EOF))
    {
        n++ ;
    }
    fclose(f);
    return n;

}
 Classe* afficher_liste_classe(int n)
{
    FILE *f;
    Classe *tab;
    tab=malloc(sizeof(Classe)*n);
    Classe C ;
    int j=0;


    f=fopen("classe.txt","r");
    while((fscanf(f,"%s %d \n",C.nom_classe,&C.id_classe)!=EOF))
    {

        tab[j]=C;
      j++;

    }
    fclose(f);
    return tab;
}
