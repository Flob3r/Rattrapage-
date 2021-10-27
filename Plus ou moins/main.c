#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char * argv[]) {
    int NRandom = 0;
    int NEntre = 0;
    int NCoup = 0;
    int NGame = 0;
    int Mode = 0;
    int Level = 0;
    int nbMin = 1;
    int nbMax = 100;

    srand(time(NULL));
    NRandom = (rand() % (nbMax - nbMin - 1)) + nbMin;

    printf("Le jeu du plus ou moins!\n");


  Game:
      printf("Choix du mode de jeux : \n 1 = Solo \n 2 = Multi  \nVotre saisie : ");
      scanf("%d",&Mode);

    if (Mode == 1)
    {
        printf("Choix de la difficulte : 1 = Facile  2 = Moyen  3 = Difficile  \nVotre saisie : ");
        scanf("   %d",&Level);

        switch(Level)	{
        case 1:
            nbMax = 100;
            printf ("Vous avez choisi le level facile \n");

            break;

        case 2:
            nbMax = 1000;
            printf ("Vous avez choisi le level Moyen \n");

			break;
        case 3:

            nbMax = 10000;
            printf ("Vous avez choisi le level Difficile \n");

			break;
	}

        srand(time(NULL));
        NRandom = (rand() % (nbMax - nbMin - 1)) + nbMin;

    }

    else if (Mode == 2)
    {

        printf("Player 1 : Choisir un chiffre entre 1 et %d\n", nbMax);
        scanf("%d",&NRandom);
        if (NRandom > 100)
        {
            printf("Chiffre non compris entre 0 et 100\n");
            goto Game;
        }
    }


    do {
        printf("Quel est le nombre ?");
        scanf("%d",&NEntre);

        NCoup++;

        if (NEntre < NRandom) {
            printf("C'est plus!\n");
        } else if (NEntre > NRandom) {
            printf("C'est moins!\n");
        } else {
            printf("Bravo, vous avez trouve le nombre mystere en %d coup!\n",NCoup);
        }
    } while(NEntre != NRandom);

    printf("Refaire une partie ? \n taper 1 pour Oui   \n taper 2 pour Non   ",NGame);
    scanf("%d",&NGame);
    if (NGame == 1)
    {
        printf("\n C'est repartie pour un tour ! \n");
        NCoup = 1;
        nbMax = 100;
        goto Game;
    }
    else
    printf("Merci de la partie");

    return 0;
}
