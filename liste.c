#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coureur.h"
#include "liste.h"




struct liste *initialiserListe()
{

  struct liste *nouvelleListe= malloc(sizeof(struct liste));
  nouvelleListe->premierCoureur = Creer_Coureur();
  nouvelleListe->premierCoureur->suiv=NULL;
  nouvelleListe->ptr_Courant=nouvelleListe->premierCoureur;
  return nouvelleListe;
}


void AjouterCoureur(struct coureur *Coureur_ajoute, struct liste *Liste)
{

    if(Liste==NULL) {
        Liste->premierCoureur=Coureur_ajoute;
    }

    else {
        struct coureur *trainard=NULL;

        trainard= Liste->premierCoureur;
        while(trainard->suiv!=NULL) {
            trainard=trainard->suiv;
        }
    trainard->suiv=Coureur_ajoute;


    }
}

void Aller_Debut(struct liste *Liste)
{
  Liste->ptr_Courant= Liste->premierCoureur;
}

struct coureur *Avancer(struct liste *Liste, int Avancement)
{
  int i=0;
  for(i=0;i<Avancement; i++)
    {
      if(Liste->ptr_Courant!=NULL) {
      Liste->ptr_Courant= Liste->ptr_Courant->suiv;
      }

      else
	{
	  i=Avancement;
	}
    }
  return Liste->ptr_Courant;
}

int Fin(struct liste *Liste)
{
  int condi = 0;
  if(Liste->ptr_Courant->suiv==NULL) {
    condi = 1;
  }
  return condi;
}

struct coureur CoureurCourant(struct liste *Liste)
{
  return *(Liste->ptr_Courant);
}

void EffacerCoureur(struct liste *Liste)
{
  struct coureur *Courant= Liste->ptr_Courant;
  if (Liste->ptr_Courant->suiv!=NULL) {
    struct coureur *CourantSuiv= Liste->ptr_Courant->suiv;
    struct coureur *trainard;
    Aller_Debut(Liste);
    trainard= Liste->premierCoureur;
    while(trainard->suiv!=Courant)
      {
	trainard=trainard->suiv;

      }
    trainard->suiv= CourantSuiv;
    free(Courant);
  }

  else {
    Aller_Debut(Liste);
    Liste->premierCoureur->suiv=NULL;
    free(Courant);
  }

  }

int NbreCoureurs(struct liste *Liste)
{
    int compteur=1;
    struct coureur *temp= Liste->premierCoureur;
    while(temp->suiv !=NULL) {
        compteur++;
        temp=temp->suiv;
    }
    return compteur;
}

struct liste *TriListe(struct liste *Liste)
{
    Aller_Debut(Liste);
    struct liste *ListeTriee= initialiserListe();
    int i=0, j=0;
    struct coureur *temp;
    int Taille=NbreCoureurs(Liste);
    struct coureur *Tab[Taille];


    for(i=0;i<Taille; i++) {
        Tab[i]= Liste->ptr_Courant;
        Avancer(Liste,1);
        Tab[i]->suiv=NULL;
    }

    for(i=0; i<Taille;i++){
        for(j=0; j<Taille-1;j++){
            if(Tab[j]->temps > Tab[j+1]->temps) {
                temp=Tab[j];
                Tab[j]=Tab[j+1];
                Tab[j+1]=temp;
            }
        }
    }

    ListeTriee->premierCoureur=Tab[0];
    for(j=1;j<Taille;j++){
        AjouterCoureur(Tab[j],ListeTriee);

    }

    return ListeTriee;
}

void AfficherListe(struct liste *Liste)
{
   struct coureur *aux;
   aux= Liste->premierCoureur;
   while (aux != NULL) {
     Afficher_coureur(aux);
     aux=aux->suiv;
   }
}

