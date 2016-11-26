#include <stdio.h>
#include "crud.h"
#include <stdlib.h>
#include <string.h>



void ajouter_maitresse(Maitresse M)
{
    int x;
    FILE *f;



    f=fopen("maitresse.txt","a+");

    if(f!=NULL)
    {

     fprintf(f,"%s %s %s %d %s %s %s \n",M.nom,M.prenom,M.mdp,M.id_maitresse,M.num_tel,M.e_mail,M.classe);

        }
        fclose(f);


    }

    void modifier_maitresse(int id_maitresse, Maitresse M )
{
    FILE *f;
    FILE *temp;
    Maitresse M1;

    f=fopen("maitresse.txt","r");
    temp=fopen("temp.txt","w");


    if(f!=NULL)
    {

        while((fscanf(f,"%s %s %s %d %s %s %s \n",M1.nom,M1.prenom,M1.mdp,&M1.id_maitresse,M1.num_tel,M1.e_mail,M1.classe)!=EOF))

        {

            if(M1.id_maitresse!=id_maitresse)
            {
                fprintf(temp,"%s %s %s %d %s %s %s \n",M1.nom,M1.prenom,M1.mdp,M1.id_maitresse,M1.num_tel,M1.e_mail,M1.classe);

            }
         else
        {

            fprintf(temp,"%s %s %s %d %s %s %s \n",M.nom,M.prenom,M.mdp,M.id_maitresse,M.num_tel,M.e_mail,M.classe);

          }
        }


    }

    fclose(temp);
    fclose(f);
    remove("maitresse.txt");
    rename("temp.txt","maitresse.txt");

}

            




void supprimer_maitresse(int id_maitresse )
{    FILE *f;
   FILE *temp;
    Maitresse M;

    f=fopen("maitresse.txt","a+");
    temp=fopen("temp.txt","w");

    if(f!=NULL)
    {        while((fscanf(f,"%s %s %s %d %s %s %s \n",M.nom,M.prenom,M.mdp,&M.id_maitresse,M.num_tel,M.e_mail,M.classe)!=EOF))
        {
            if(M.id_maitresse != id_maitresse)
            {
                fprintf(temp,"%s %s %s %d %s %s %s \n",M.nom,M.prenom,M.mdp,M.id_maitresse,M.num_tel,M.e_mail,M.classe);
            }
        }


    }
    fclose(temp);
    fclose(f);
    remove("maitresse.txt");
    rename("temp.txt","maitresse.txt");



}
int chercher_personne_maitresse(int id_maitresse , Maitresse * M)
{
    FILE *f;
    Maitresse M1;
    int x=1;

    f=fopen("maitresse.txt","r");
    while((fscanf(f,"%s %s %s %d %s %s %s \n",M1.nom,M1.prenom,M1.mdp,&M1.id_maitresse,M1.num_tel,M1.e_mail,M1.classe)!=EOF) &&(x!=0))
    {
        if (id_maitresse==M1.id_maitresse)
        {
          x=0;

            strcpy(M->nom,M1.nom);
            strcpy(M->prenom,M1.prenom);
            strcpy(M->mdp,M1.mdp);
            strcpy(M->e_mail,M1.e_mail);
            strcpy(M->num_tel,M1.num_tel);
            (M->id_maitresse)=M1.id_maitresse;

        }
        fclose(f);


    }
    return x;
}


int taille_fichier_maitresse()
{
    Maitresse M;
    FILE *f;
    int n;

    f=fopen("maitresse.txt","r");
    while((fscanf(f,"%s %s %s %d %s %s %s \n",M.nom,M.prenom,M.mdp,&M.id_maitresse,M.num_tel,M.e_mail,M.classe)!=EOF))
    {
        n++;
    }
    fclose(f);
    return n;

}
Maitresse* afficher_liste_maitresse(int n)
{
    FILE *f;
    Maitresse *tab;
    tab=malloc(sizeof(Maitresse)*n);
    Maitresse M;
    int j=0;


    f=fopen("maitresse.txt","r");
    while((fscanf(f,"%s %s %s %d %s %s %s \n",M.nom,M.prenom,M.mdp,&M.id_maitresse,M.num_tel,M.e_mail,M.classe)!=EOF))
    {

        tab[j]=M;
      j++;

    }
    fclose(f);
    return tab;
}





