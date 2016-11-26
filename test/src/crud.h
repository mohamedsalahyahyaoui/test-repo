#include<stdio.h>
struct parent  
{

    char nom[100];
    char prenom[100];
    char mdp[100];
    char num_tel[100];
    char e_mail[100];
    int id_parent;


};typedef struct parent Parent ;

struct bracelet
{

    int id_enfant ;
    int id_bracelet;


};typedef struct bracelet Bracelet ;

struct classe 
{
	char nom_classe[100];
	int id_classe; 

};typedef struct classe Classe ;
struct enfant 
{

    char nom[100];
    char prenom[100];
    int id;
    char date_naissance[100];
    char classe[100];
    int id_parent ;


};typedef struct enfant Enfant ;
struct maitresse 
{

    char nom[100];
    char prenom[100];
    char mdp[100];
    char num_tel[100];
    char e_mail[100];
    int id_maitresse ;
    char classe[50];


};typedef struct maitresse Maitresse ;

void ajouter_classe(Classe C);
void modifier_classe(int id_classe,Classe C);
void supprimer_classe(int id_classe);
int chercher_classe(int id_classe, Classe * C);
int taille_fichier_classe();
Classe* afficher_liste_classe(int n);




void ajouter_bracelet(Bracelet B);
void modifier_bracelet(int id_bracelet ,Bracelet B);
void supprimer_bracelet(int id_bracelet );
int chercher_personne_bracelet(int id_bracelet , Bracelet * B);
int taille_fichier_bracelet();
Bracelet* afficher_liste_bracelet(int n);




void ajouter_parent(Parent P);
int taille_fichier_parent();
void supprimer_parent(int id);
void modifier_parent(int id,Parent P);
int chercher_personne_parent(int id,Parent * P);
Parent* afficher_liste_parent(int n);



void ajouter_enfant(Enfant E);
void modifier_enfant(int id,Enfant E);
void supprimer_enfant(int id);
int chercher_personne_enfant(int id,Enfant * E);
int taille_fichier_enfant();
Enfant* afficher_liste_enfant(int n);


void ajouter_maitresse(Maitresse M);
void modifier_maitresse(int id_maitresse, Maitresse M);
void supprimer_maitresse(int id_maitresse );
int chercher_personne_maitresse(int id_maitresse , Maitresse * M);
int taille_fichier_maitresse();
Maitresse* afficher_liste_maitresse(int n);

