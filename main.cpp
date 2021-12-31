#include "header/fonction.h"
#include "header/test.h"


void initGrilleEtHistoriqueDeCoup(Grille *grille, Coup *&coups, int *nbCoup) {
    int nbLignes, nbColonnes, nbMines;
    cin >> nbLignes >> nbColonnes >> nbMines;
    // Instantier grille
    Grille grilleCopie = creerGrille(nbLignes, nbColonnes, nbMines);
    *grille = grilleCopie;
    for (int i = 0; i < nbMines; ++i) {
        cin >> grille->mines[i];
    }
    // Instantier historique de coups
    int temp, position1D;
    string move;
    cin >> temp;
    *nbCoup = temp;
    coups = new Coup[*nbCoup];
    for (int i = 0; i < *nbCoup; ++i) {
        cin >> move;
        EtatGrille typeMove = (move[0] == 'D') ? DEMASQUE : MARQUE;
        move.erase(0, 1);
        position1D = stoi(move);
        Point pos = conversion1DTo2D(grille, position1D);
        coups[i].position = pos;
        coups[i].typecoup = typeMove;
    }
}


int main() {
    int choixCommande = 0;
    int nbLignes;
    int nbColonnes;
    int nbMines;


    Grille grille;
    Coup *coups;
    int nbCoup;

    cin >> choixCommande;

    switch (choixCommande) {
        case 1: {
            cin >> nbLignes >> nbColonnes >> nbMines;
            grille = creerGrille(nbLignes, nbColonnes, nbMines);
            afficherProbleme(&grille);
            break;
        }
        case 2: {
            initGrilleEtHistoriqueDeCoup(&grille, coups, &nbCoup);
            remplirGrille(&grille, coups, nbCoup);
            afficherGrille(&grille, coups, nbCoup);
            break;
        }
        case 3: {
            initGrilleEtHistoriqueDeCoup(&grille, coups, &nbCoup);
            remplirGrille(&grille, coups, nbCoup);
            EtatJeu etatJeu = getEtatJeu(&grille, coups, nbCoup);
            cout << ((etatJeu == GAGNE) ? "game won" : "game not won") << endl;
            break;
        }
        case 4: {
            initGrilleEtHistoriqueDeCoup(&grille, coups, &nbCoup);
            remplirGrille(&grille, coups, nbCoup);
            EtatJeu etatJeu = getEtatJeu(&grille, coups, nbCoup);
            cout << ((etatJeu == PERDU) ? "game lost" : "game not lost") << endl;
            break;
        }
        case 5: {
            cin >> nbLignes >> nbColonnes;
            grille = initGrilleFromString(nbLignes, nbColonnes);
            Coup coup = trouverCoupValide(&grille);
            string coupStr = conversionCoupToStr(&grille, coup);
            cout << coupStr << endl;
            break;
        }
        case 10: {
            runTest();
            break;
        }
    }
    cleanGrille(&grille);
    return 0;
}