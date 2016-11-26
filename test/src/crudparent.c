
#include <stdio.h>
#include "crud.h"
#include <stdlib.h>
#include <string.h>


void ajouter_parent(Parent P)
{
    int x;
    FILE *f;



    f=fopen("parent.txt","a+");

    if(f!=NULL)
    {

     fprintf(f,"%s %s %s %d %s %s \n",P.nom,P.prenom,P.mdp,P.id_parent,P.num_tel,P.e_mail);

        }        fclose(f);


    }

    void modifier_parent(int id_parent,Parent P)
{
    FILE *f;
    FILE *temp;
    Parent P1;

    f=fopen("parent.txt","r");
    temp=fopen("temp.txt","w");

    if(f!=NULL)
    {

        while((fscanf(f,"%s %s %s %d %s %s \n",P1.nom, P1.prenom,P1.mdp,&P1.id_parent,P1.num_tel,P1.e_mail)!=EOF))

        {


            if(P1.id_parent!=id_parent)
            {
                fprintf(temp,"%s %s %s %d %s %s \n",P1.nom, P1.prenom,P1.mdp,P1.id_parent,P1.num_tel,P1.e_mail);

            }
         else
        {

            fprintf(temp,"%s %s %s %d %s %s \n",P.nom, P.prenom,P.mdp,P.id_parent,P.num_tel,P.e_mail);

          }        
}


    }

    fclose(temp);
    fclose(f);
    remove("parent.txt");
    rename("temp.txt","parent.txt");

}



void supprimer_parent(int id )
{
    FILE *f;
    FILE *temp;
    Parent P1;

    f=fopen("parent.txt","a+");
    temp=fopen("temp.txt","w");

    if(f!=NULL)
    {
        while((fscanf(f,"%s %s %s %d %s %s \n",P1.nom, P1.prenom,P1.mdp,&P1.id_parent,P1.num_tel,P1.e_mail)!=EOF))
        {
            if(P1.id_parent != id)
            {
                fprintf(temp,"%s %s %s %d %s %s \n",P1.nom, P1.prenom,P1.mdp,P1.id_parent,P1.num_tel,P1.e_mail);
            }
        }


    }
    fclose(temp);
    fclose(f);
    remove("parent.txt");
    rename("temp.txt","parent.txt");



}


int chercher_personne_parent(int id_parent , Parent * P)
{
    FILE *f;
    Parent P1;
    int x=1;

    f=fopen("parent.txt","r");
    while((fscanf(f,"%s %s %s %d %s %s \n",P1.nom, P1.prenom,P1.mdp,&P1.id_parent,P1.num_tel,P1.e_mail)!=EOF) &&(x!=0))
    {
        if (id_parent==P1.id_parent)
        {
          x=0;

            strcpy(P->nom,P1.nom);
            strcpy(P->prenom,P1.prenom);
            strcpy(P->mdp,P1.mdp);
            strcpy(P->e_mail,P1.e_mail);
            strcpy(P->num_tel,P1.num_tel);
            (P->id_parent)=P1.id_parent;

        }
        fclose(f);


    }
    return x;
}



int taille_fichier_parent()
{
    Parent P1;
    FILE *f;
    int n =0;
		char *s;
    f=fopen("parent.txt","r");
    while(fscanf(f,"%s %s %s %d %s %s \n",P1.nom, P1.prenom,P1.mdp,&P1.id_parent,P1.num_tel,P1.e_mail)!=EOF)
    {
        n++;
    }
    fclose(f);
    return n;

}
Parent* afficher_liste_parent(int n)
{
    FILE *f;
    Parent* tab;
    tab=(Parent*)malloc(sizeof(Parent));
    Parent P;
    int j=0;

    char* s ;
	//tab[0].nom ="fff";
   /* f=fopen("parent.txt","r");
	if(f == NULL) exit(EXIT_FAILURE);
    while(fscanf(f,"%s %s %s %d %s %s\n",s, P.prenom,P.mdp,&P.id_parent,P.num_tel,P.e_mail)!=EOF)
    {

	fprintf(stderr,P.prenom);

        (

      

    }
    fclose(f);*/
    return tab;
}

