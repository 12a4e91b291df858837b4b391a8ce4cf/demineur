#include "../header/test.h"

void runTest() {
    testConversion();
    testRemplirGrille();
    testEtatJeuGagne();
    testEtatJeuPerduAvecDemasquage();
    testEtatJeuPerduAvecMarquage();
    testEtatJeuEnCours();
    cout << "TOUS LES TESTS SONT PASSES" << endl;
}

void testConversion() {
    Grille g;
    g.nbColonnes = 6;
    g.nbLignes = 4;

    Point tab = conversion1DTo2D(&g, 0);
    Point tab2 = conversion1DTo2D(&g, 9);
    Point tab3 = conversion1DTo2D(&g, 20);

    assert(tab.x == 0 && tab.y == 0);
    assert(tab2.x == 1 && tab2.y == 3);
    assert(tab3.x == 3 && tab3.y == 2);
}

void testRemplirGrille() {
    int nbLignes = 4;
    int nbColonnes = 6;
    int nbMines = 5;

    Grille g = creerGrille(nbLignes, nbColonnes, nbMines);
    g.mines[0] = 1;
    g.mines[1] = 5;
    g.mines[2] = 7;
    g.mines[3] = 12;
    g.mines[4] = 19;


    Coup coups[3];
    coups[0].position.x = 2;
    coups[0].position.y = 3;
    coups[0].typecoup = DEMASQUE;

    coups[1].position.x = 0;
    coups[1].position.y = 5;
    coups[1].typecoup = MARQUE;

    coups[2].position.x = 0;
    coups[2].position.y = 0;
    coups[2].typecoup = DEMASQUE;

    remplirGrille(&g, coups, 3);

    int matriceAttendue[4][6] = {
            {2,          NON_REVELE, 2, 0, 1, DRAPEAU},
            {NON_REVELE, NON_REVELE, 2, 0, 1, 1},
            {NON_REVELE, NON_REVELE, 2, 0, 0, 0},
            {NON_REVELE, NON_REVELE, 1, 0, 0, 0},
    };

    for (int i = 0; i < g.nbLignes; i++) {
        for (int j = 0; j < g.nbColonnes; j++) {
            assert(g.matrice[i][j] == matriceAttendue[i][j]);
        }
    }
}

void testEtatJeuGagne() {
    int nbLignes = 4;
    int nbColonnes = 6;
    int nbMines = 5;

    Grille g = creerGrille(nbLignes, nbColonnes, nbMines);
    g.mines[0] = 1;
    g.mines[1] = 5;
    g.mines[2] = 7;
    g.mines[3] = 12;
    g.mines[4] = 19;


    Coup coups[7];
    coups[0].position.x = 2;
    coups[0].position.y = 3;
    coups[0].typecoup = DEMASQUE;

    coups[1].position.x = 0;
    coups[1].position.y = 5;
    coups[1].typecoup = MARQUE;

    coups[2].position.x = 0;
    coups[2].position.y = 0;
    coups[2].typecoup = DEMASQUE;

    coups[3].position.x = 1;
    coups[3].position.y = 0;
    coups[3].typecoup = DEMASQUE;

    coups[4].position.x = 3;
    coups[4].position.y = 0;
    coups[4].typecoup = DEMASQUE;

    coups[5].position.x = 3;
    coups[5].position.y = 0;
    coups[5].typecoup = DEMASQUE;

    coups[6].position.x = 2;
    coups[6].position.y = 1;
    coups[6].typecoup = DEMASQUE;

    remplirGrille(&g, coups, 7);
    EtatJeu etatJeu = getEtatJeu(&g, coups, 7);
    assert(etatJeu == GAGNE);
}

void testEtatJeuPerduAvecDemasquage() {
    int nbLignes = 4;
    int nbColonnes = 6;
    int nbMines = 5;

    Grille g = creerGrille(nbLignes, nbColonnes, nbMines);
    g.mines[0] = 1;
    g.mines[1] = 5;
    g.mines[2] = 7;
    g.mines[3] = 12;
    g.mines[4] = 19;


    Coup coups[4];
    coups[0].position.x = 2;
    coups[0].position.y = 3;
    coups[0].typecoup = DEMASQUE;

    coups[1].position.x = 0;
    coups[1].position.y = 5;
    coups[1].typecoup = MARQUE;

    coups[2].position.x = 0;
    coups[2].position.y = 0;
    coups[2].typecoup = DEMASQUE;

    coups[3].position.x = 3;
    coups[3].position.y = 1;
    coups[3].typecoup = DEMASQUE;

    remplirGrille(&g, coups, 4);
    EtatJeu etatJeu = getEtatJeu(&g, coups, 4);
    assert(etatJeu == PERDU);
}

void testEtatJeuPerduAvecMarquage() {
    int nbLignes = 4;
    int nbColonnes = 6;
    int nbMines = 5;

    Grille g = creerGrille(nbLignes, nbColonnes, nbMines);
    g.mines[0] = 1;
    g.mines[1] = 5;
    g.mines[2] = 7;
    g.mines[3] = 12;
    g.mines[4] = 19;


    Coup coups[4];
    coups[0].position.x = 2;
    coups[0].position.y = 3;
    coups[0].typecoup = DEMASQUE;

    coups[1].position.x = 0;
    coups[1].position.y = 5;
    coups[1].typecoup = MARQUE;

    coups[2].position.x = 0;
    coups[2].position.y = 0;
    coups[2].typecoup = DEMASQUE;

    coups[3].position.x = 2;
    coups[3].position.y = 1;
    coups[3].typecoup = MARQUE;

    remplirGrille(&g, coups, 4);
    EtatJeu etatJeu = getEtatJeu(&g, coups, 4);
    assert(etatJeu == PERDU);
}

void testEtatJeuEnCours() {
    int nbLignes = 4;
    int nbColonnes = 6;
    int nbMines = 5;

    Grille g = creerGrille(nbLignes, nbColonnes, nbMines);
    g.mines[0] = 1;
    g.mines[1] = 5;
    g.mines[2] = 7;
    g.mines[3] = 12;
    g.mines[4] = 19;


    Coup coups[3];
    coups[0].position.x = 2;
    coups[0].position.y = 3;
    coups[0].typecoup = DEMASQUE;

    coups[1].position.x = 0;
    coups[1].position.y = 5;
    coups[1].typecoup = MARQUE;

    coups[2].position.x = 0;
    coups[2].position.y = 0;
    coups[2].typecoup = DEMASQUE;

    remplirGrille(&g, coups, 3);
    EtatJeu etatJeu = getEtatJeu(&g, coups, 3);
    assert(etatJeu == EN_COURS);
}