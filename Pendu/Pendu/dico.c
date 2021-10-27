#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "dico.h"

int MPiocher (char *MPrendre)
{
    FILE* dico = NULL;
    int NMots = 0, NChoisi = 0, i = 0;
    int Lire = 0;
    dico = fopen("dico.txt", "r");

    if (dico == NULL)
    {
        printf("Impossible de charger le dictionnaire de mots");
        return 0;
    }

    do
    {
        Lire = fgetc(dico);
        if (Lire == '\n')
            NMots++;
    } while(Lire != EOF);

    NChoisi = randomN(NMots);

    rewind(dico);
    while (NChoisi > 0)
    {
        Lire = fgetc(dico);
        if (Lire == '\n')
            NChoisi--;
    }

    fgets(MPrendre, 100, dico);

    MPrendre[strlen(MPrendre) - 1] = '\0';
    fclose(dico);

    return 1;
}

int randomN(int NMax)
{
    srand(time(NULL));
    return (rand() % NMax);
}
