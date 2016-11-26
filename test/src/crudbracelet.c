#include <stdio.h>
#include "crud.h"
#include <stdlib.h>


void ajouter_bracelet(Bracelet B)
{
    int x;
    FILE *f;



    f=fopen("bracelet.txt","a+");

    if(f!=NULL)
    {

     fprintf(f," %d %d  \n",B.id_bracelet,B.id_enfant);

        }
        fclose(f);


    }

    void modifier_bracelet(int id_bracelet,Bracelet B)
{
    FILE *f;
    FILE *temp;
    Bracelet B1;

    f=fopen("bracelet.txt","r");
    temp=fopen("temp.txt","w");


    if(f!=NULL)
    {

        while((fscanf(f,"%d %d  \n",B1.id_bracelet , B1.id_enfant )!=EOF))
        {


            if(B1.id_bracelet!=id_bracelet)
            {
                fprintf(temp,"%d %d \n",B1.id_bracelet , B1.id_enfant);

            }
         else
        {

            fprintf(temp," %d %d \n",B.id_bracelet , B.id_enfant);

          }
        }


    }

    fclose(temp);
    fclose(f);
    remove("bracelet.txt");
    rename("temp.txt","bracelet.txt");

}
void supprimer_bracelet(int id_bracelet )
{
    FILE *f;
    FILE *temp;
    Bracelet B ;

    f=fopen("maitresse.txt","a+");
    temp=fopen("temp.txt","w");

    if(f!=NULL)
    {
        while(fscanf(f,"%d %d  \n",B.id_bracelet , B.id_enfant )!=EOF)
        {
            if(B.id_bracelet != id_bracelet)
            {
                (fprintf(temp," %d %d  \n",B.id_bracelet , B.id_enfant )!=EOF);
            }
        }


    }
    fclose(temp);
    fclose(f);
    remove("bracelet.txt");
    rename("temp.txt","bracelet.txt");



}
int chercher_personne_bracelet(int id_bracelet , Bracelet * B)
{
    FILE *f;
    Bracelet B1;
    int x=1;

    f=fopen("bracelet.txt","r");
    while((fscanf(f,"%d %d \n",B1.id_bracelet , B1.id_enfant )!=EOF) &&(x!=0))
    {
        if (id_bracelet==B1.id_bracelet)
        {
          x=0;

             strcpy(B->id_enfant,B1.id_enfant);
            (B->id_bracelet)=B1.id_bracelet;

        }
        fclose(f);


    }
    return x;
}

int taille_fichier()
{
    Bracelet B;
    FILE *f;
    int n;

    f=fopen("bracelet.txt","r");
    while(fscanf(f,"%d %d \n",B.id_bracelet , B.id_enfant !=EOF))
    {
        n++;
    }
    fclose(f);
    return n;

}
Bracelet* afficher_liste_bracelet(int n)
{
    FILE *f;
    Bracelet *tab;
    tab=malloc(sizeof(Bracelet)*n);
    Bracelet B ;
    int j=0;


    f=fopen("bracelet.txt","r");
    while((fscanf(f,"%d %d  \n",B.id_bracelet , B.id_enfant )!=EOF))
    {

        tab[j]=B;

      j++;

    }
    fclose(f);
    return tab;
}






