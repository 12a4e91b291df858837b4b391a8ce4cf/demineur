#include "fonctions.h"
#include "fonctions.cpp"


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
            cin>>grille.nbLignes>>grille.nbColonnes>>grille.nbMines;
            for (int i = 0; i < grille.nbMines; i++){
                cin>>grille.mines[i];
            }


    }

    return 0;
}
