#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include "dico.h"
#include "dico.c"

char lire ();
int win(int LTrouvee[],long MTaille);
int RLettre(char Lettre, char MSecret[], int LTrouvee[]);

int main(int argc, const char * argv[])
{
    int i = 0;
    int CRestants = 10;
    int NBErreur = 0;
    int *LTrouvee = NULL;
    int NGame = 0;
    int Mode = 0;
    char Lettre = 0;
    char MSecret[100] = {0};
    long MTaille = 0;


    printf("Bienvenue dans le Pendu !\n\n");

Game:
    printf("Choix du mode de jeux : \n 1 = Multijoueur \n 2 = Solo  \nVotre saisie : ");
    scanf("%d",&Mode);

    switch(Mode)
    {
    case 1:
        MSecret[100] = 0;
        printf("Player one choisi un mot en masjuscule :  ");
        scanf("%s",&MSecret);

        MTaille = strlen(MSecret);
        LTrouvee = malloc(MTaille * sizeof(int));

        break;

    case 2:

        if (!MPiocher(MSecret))
        {
            exit(0);
        }

        MTaille = strlen(MSecret);

        LTrouvee = malloc(MTaille * sizeof(int));
        break;
    }

    if (LTrouvee == NULL)
    {
        exit(0);
    }

    for (i = 0 ; i < MTaille ; i++)
    {
        LTrouvee[i] = 0;
    }
    while (CRestants > 0 && !win(LTrouvee,MTaille))
    {
        printf("Il vous reste %d coups a jouer.", CRestants);
        printf("Quel est le mot secret ? ");
        for (i = 0 ; i < MTaille ; i++)
        {
            if (LTrouvee[i])
            {
                printf("%c", MSecret[i]);
            }
            else
            {
                printf("*");
            }
        }

        printf("\nProposez une lettre : ");
        Lettre = lire();
        int CRestants2 = CRestants;
        if (!RLettre(Lettre, MSecret, LTrouvee))
        {
            CRestants--;
        }



        if(CRestants != CRestants2 )
        {

            NBErreur++;
            AFFPendu(NBErreur);
        }

    }

    if (win(LTrouvee, MTaille ))
    {
        printf("\n\n Gagne ! Le mot secret etait bien : %s", MSecret);
    }
    else
    {
        printf("\n\n Perdu ! Le mot secret etait : %s", MSecret);
    }

    free(RLettre);

    printf("\n Refaire une partie ? \n taper 1 pour Oui   \n taper 2 pour Non   ",NGame);
    scanf("%d",&NGame);

    if (NGame == 1)
    {
        printf("\n \n \n C'est repartie pour un tour ! \n \n");
        CRestants = 10;
        goto Game;
    }
    else
    {
        printf(" Merci de la partie");
    }





    return 0;
}

char lire()
{
    char Lettre = 0;

    Lettre = getchar();
    Lettre = toupper(Lettre);

    while (getchar() != '\n');

    return Lettre;
}

int win(int LTrouvee[],long MTaille)
{
    long i = 0;
    int playerwin = 1;

    for (i = 0 ; i < 6 ; i++)
    {
        if (LTrouvee[i] == 0)
            playerwin = 0;
    }

    return playerwin;
}

int RLettre(char Lettre, char MSecret[], int LTrouvee[])
{
    int i = 0;
    int BLettre = 0;

    for (i = 0 ; MSecret[i] != '\0' ; i++)
    {
        if (Lettre == MSecret[i])
        {
            BLettre = 1;
            LTrouvee[i] = 1;
        }
    }
    return BLettre;
}
void AFFPendu(int NBErreur)
{
    switch(NBErreur)
    {
    case 1:
        printf ("\n");
        printf("            \n");
        printf("              \n");
        printf("              \n");
        printf("              \n");
        printf("              \n");
        printf("              \n");
        printf("              \n");
        printf("      -----   \n");
        printf ("\n");
        break;

    case 2:
        printf ("\n");
        printf("             \n");
        printf("        |     \n");
        printf("        |     \n");
        printf("        |     \n");
        printf("        |     \n");
        printf("        |     \n");
        printf("        |     \n");
        printf("      -----   \n");
        printf ("\n");
        break;
    case 3:
        printf ("\n");
        printf("      __     \n");
        printf("     |  |     \n");
        printf("        |     \n");
        printf("        |     \n");
        printf("        |     \n");
        printf("        |     \n");
        printf("        |     \n");
        printf("      -----   \n");
        printf ("\n");
        break;

    case 4:
        printf ("\n");
        printf("      __     \n");
        printf("     |  |     \n");
        printf("     0  |     \n");
        printf("        |     \n");
        printf("        |     \n");
        printf("        |     \n");
        printf("        |     \n");
        printf("      -----   \n");
        printf ("\n");
        break;
    case 5:
        printf ("\n");
        printf("      __     \n");
        printf("     |  |     \n");
        printf("     0  |     \n");
        printf("    /   |     \n");
        printf("        |     \n");
        printf("        |     \n");
        printf("        |     \n");
        printf("      -----   \n");
        printf ("\n");
        break;

    case 6:
        printf ("\n");
        printf("      __     \n");
        printf("     |  |     \n");
        printf("     0  |     \n");
        printf("    /|  |     \n");
        printf("        |     \n");
        printf("        |     \n");
        printf("        |     \n");
        printf("      -----   \n");
        printf ("\n");
        break;

    case 7:
        printf ("\n");
        printf("      __     \n");
        printf("     |  |     \n");
        printf("     0  |     \n");
        printf("    /|\\ |     \n");
        printf("        |     \n");
        printf("        |     \n");
        printf("        |     \n");
        printf("      -----   \n");
        printf ("\n");
        break;

    case 8:
        printf ("\n");
        printf("      __     \n");
        printf("     |  |     \n");
        printf("     0  |     \n");
        printf("    /|\\ |     \n");
        printf("     -  |     \n");
        printf("        |     \n");
        printf("        |     \n");
        printf("      -----   \n");
        printf ("\n");
        break;

    case 9:
        printf ("\n");
        printf("      __     \n");
        printf("     |  |     \n");
        printf("     0  |     \n");
        printf("    /|\\ |     \n");
        printf("     -  |     \n");
        printf("    /   |     \n");
        printf("        |     \n");
        printf("      -----   \n");
        printf ("\n");
        break;

    case 10:
        printf ("\n");
        printf("      __     \n");
        printf("     |  |     \n");
        printf("     0  |     \n");
        printf("    /|\\ |     \n");
        printf("     -  |     \n");
        printf("    / \\ |     \n");
        printf("        |     \n");
        printf("      -----   \n");
        printf ("\n");
        break;
    }
}
