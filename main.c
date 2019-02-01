#include <stdio.h>
#include <stdlib.h>
#include "coureur.h"
#include "liste.h"
#include "FonctionsGestionClassement.h"

int main()
{
    FILE* fichier= fopen("DonnéesTourdeFrance.txt", "r");

    if (fichier ==NULL) {
        printf("Erreur lors de l'ouverture du fichier");
    }

    else {
       CreationClassement(fichier);


    }
    return 0;
}
