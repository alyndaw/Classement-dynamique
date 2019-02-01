#include "coureur.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct coureur *Creer_Coureur()
{
   struct coureur *nouvel_coureur = malloc(sizeof(struct coureur));
   nouvel_coureur->suiv=NULL;
   nouvel_coureur->temps=0;
   nouvel_coureur->dossard=0;
   strcpy(nouvel_coureur->nom,"");
   strcpy(nouvel_coureur->prenom,"");
   strcpy(nouvel_coureur->equipe,"");
   return nouvel_coureur;

}

void Ajouter_Temps(long temps, struct coureur *coureur_modifier_temps)
{
  (*coureur_modifier_temps).temps = (*coureur_modifier_temps).temps + temps;

}

void Afficher_coureur( struct coureur *coureur_afficher)
{
  long seconds, hours, minutes, var_inter;

  printf("Nom : %s \n", coureur_afficher->nom);
  printf("Prenom : %s \n", coureur_afficher->prenom);
  printf("Dossard : %d \n", coureur_afficher->dossard);
  printf("Equipe : %s \n", coureur_afficher->equipe);

  seconds = coureur_afficher->temps;
  hours = seconds / 3600;
  var_inter = seconds%3600;
  minutes = var_inter / 60;
  seconds = var_inter%60;

  printf("Temps : %ldh%ldm%lds \n", hours, minutes, seconds);

}



