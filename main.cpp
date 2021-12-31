#include "fonctions.h"
#include "fonctions.cpp"
#include "test.cpp"

int main()
{
    unsigned int choixCommande=0;
    unsigned int nbLignes;
    unsigned int nbColonnes;
    unsigned int nbMines;

    Grille grille;
    cin>>choixCommande;


    switch(choixCommande) {
        case 1:
            cin >> nbLignes >> nbColonnes >> nbMines;
            grille = creerGrille(nbLignes,nbColonnes,nbMines);
            afficherProbleme(&grille);
        break;
        case 2:
        case 10:
            testConversion();
            testRemplirGrille();
        break;
    }

    return 0;
}



