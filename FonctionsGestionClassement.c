#include <stdio.h>
#include <stdlib.h>
#include "coureur.h"
#include "liste.h"

struct liste * CreationClassement(FILE* fichier)
{
    int NbreEtapes=0, NbreEquipes=0;
    int i;
    fscanf(fichier, "%d %d", &NbreEtapes, &NbreEquipes);

    struct liste *Classement = initialiserListe();
    for (i=0;i<NbreEquipes-1;i++) {
        AjouterCoureur(Creer_Coureur(), Classement);
    }

    return Classement;

}
