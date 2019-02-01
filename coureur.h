struct coureur
{
  char nom[10];
  char prenom[10];
  int dossard;
  char equipe[10];
  long temps;
  struct coureur *suiv; 

}*pCoureur;

struct coureur *Creer_Coureur();
void Ajouter_Temps(long temps, struct coureur *coureur_modifier_temps);
void Afficher_coureur( struct coureur *coureur_afficher);

