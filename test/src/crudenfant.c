#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "crud.h"

void ajouter_enfant(Enfant E)
{
 int x;
 FILE *f;



f=fopen("enfant.txt","a+");
if(f!=NULL)
{

 fprintf(f,"%s %s %d %s %d %s\n",E.nom,E.prenom,E.id,E.date_naissance,E.id_parent,E.classe);
}
fclose(f);

}



void modifier_enfant(int id,Enfant E)
{
  
  FILE *f;
  FILE *temp;
  Enfant E1;

f=fopen("enfant.txt","r");
temp=fopen("temp.txt","w");

if(f!=NULL)
{
while(fscanf(f,"%s %s %d %s %d %s  \n",E1.nom,E1.prenom,&E1.id,E1.date_naissance,&E1.id_parent,E1.classe)!=EOF)
{
  if(E1.id!=id)
{  fprintf(temp,"%s %s %d %s %d %s  \n",E1.nom,E1.prenom,E1.id,E1.date_naissance,E1.id_parent,E1.classe);
}
else
{
  fprintf(temp,"%s %s %d %s %d %s  \n",E.nom,E.prenom,E.id,E.date_naissance,E.id_parent,E.classe);
}
}
}




fclose(temp);
fclose(f);
remove("enfant.txt");
rename("temp.txt","enfant.txt");

}




void supprimer_enfant(int id)
{ FILE *f;
  FILE *temp;
  Enfant E;

 f=fopen("enfant.txt","a+");
temp=fopen("temp.txt","w");

if(f!=NULL)
{ while((fscanf(f,"%s %s %d %s %d %s  \n",E.nom,E.prenom,&E.id,E.date_naissance,&E.id_parent,E.classe)!=EOF))
{
  if(E.id!=id)
{
  fprintf(temp,"%s %s %d %s %d %s  \n",E.nom,E.prenom,E.id,E.date_naissance,E.id_parent,E.classe);
}
}
}
fclose(temp);
fclose(f);
remove("enfant.txt");
rename("temp.txt","enfant.txt");
}



int chercher_personne_enfant(int id,Enfant * E)
{
FILE *f;
Enfant E1;
int x=1;

f=fopen("enfant.txt","r");
while((fscanf(f,"%s %s %d %s %d %s  \n",E1.nom,E1.prenom,&E1.id,E1.date_naissance,&E1.id_parent,E1.classe)!=EOF)&&(x!=0))
{
  if(id==E1.id)
   {
    x=0;

strcpy(E->nom,E1.nom);
strcpy(E->prenom,E1.prenom);
strcpy(E->date_naissance,E1.date_naissance);
strcpy(E->id_parent,E1.id_parent);
strcpy(E->classe,E1.classe);
(E->id)=E1.id;

}
fclose(f);

}

return x;
}



int taille_fichier_enfant()
{
Enfant E;
FILE *f;
int n;
f=fopen("enfant.txt","r");
while((fscanf(f,"%s %s %d %s %d %s  \n",E.nom,E.prenom,&E.id,E.date_naissance,&E.id_parent,E.classe)!=EOF))
{
n++;
}
fclose(f);
return n;
}



Enfant* afficher_liste_enfant(int n)
{
FILE *f;
Enfant *tab;
tab=malloc(sizeof(Enfant)*n);
Enfant E;
int j=0;

f=fopen("enfant.txt","r");
while((fscanf(f,"%s %s %d %s %d %s  \n",E.nom,E.prenom,&E.id,E.date_naissance,&E.id_parent,E.classe)!=EOF))
{

tab[j]=E;

j++;

}


fclose(f);
return tab;
}
