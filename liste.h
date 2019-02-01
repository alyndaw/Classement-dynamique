
struct liste
{
  struct coureur *premierCoureur;
  struct coureur *ptr_Courant;

};


void AfficherListe(struct liste *Liste);
struct liste *initialiserListe();
void AjouterCoureur(struct coureur *Coureur_ajoute, struct liste *Liste);
void Aller_Debut(struct liste *Liste);
struct coureur *Avancer(struct liste *Liste, int Avancement);
int Fin(struct liste *Liste);
struct coureur CoureurCourant(struct liste *Liste);
void EffacerCoureur(struct liste *Liste);
int NbreCoureurs(struct liste *Liste);
struct liste *TriListe(struct liste *Liste);


