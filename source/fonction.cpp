#include "../header/fonction.h"


void initMatrix(Grille *g, int nbLignes, int nbColonnes) {
    g->nbLignes = nbLignes;
    g->nbColonnes = nbColonnes;
    g->matrice = new int *[nbLignes];
    for (int i = 0; i < nbLignes; i++) {
        g->matrice[i] = new int[nbColonnes];
    }

    for (int i = 0; i < g->nbLignes; i++) {
        for (int j = 0; j < g->nbColonnes; j++) {
            g->matrice[i][j] = NON_REVELE;
        }
    }
}

Grille creerGrille(int nbLignes, int nbColonnes, int nbMines) {
    Grille g;
    initMatrix(&g, nbLignes, nbColonnes);
    g.nbMines = nbMines;
    g.mines = new int[nbMines];
    srand(time(nullptr));
    for (int i = 0; i < g.nbMines; i++) {
        int mine = rand() % g.nbLignes * g.nbColonnes;
        g.mines[i] = mine;
    }

    return g;

}


void afficherProbleme(const Grille *g) {
    cout << g->nbLignes << " " << g->nbColonnes << " " << g->nbMines << " ";
    for (unsigned int i = 0; i < g->nbMines; ++i)
        cout << g->mines[i] << " ";
    cout << endl;
}


void revelerCase(Grille *g, Point positionReveler) {
    int nbMineAdjacente = getNbMineAdjacente(g, positionReveler);
    if (nbMineAdjacente == 0) {
        g->matrice[positionReveler.x][positionReveler.y] = 0;
        Point voisinAdjacentNonVisite[8];
        int nbVoisin = getVoisinAdjacentNonVisites(g, positionReveler, voisinAdjacentNonVisite);
        for (int i = 0; i < nbVoisin; ++i) {
            revelerCase(g, voisinAdjacentNonVisite[i]);
        }
    } else {
        g->matrice[positionReveler.x][positionReveler.y] = nbMineAdjacente;
    }
}


void remplirGrille(Grille *g, Coup *coups, int nbCoup) {
    for (int i = 0; i < nbCoup; ++i) {
        if (coups[i].typecoup == MARQUE) {
            g->matrice[coups[i].position.x][coups[i].position.y] = DRAPEAU;
        } else {
            Point positionReveler;
            positionReveler.x = coups[i].position.x;
            positionReveler.y = coups[i].position.y;
            revelerCase(g, positionReveler);
        }
    }
}

void afficherGrille(Grille *g, Coup *coups, int nbCoup) {
    EtatJeu etatJeu = getEtatJeu(g, coups, nbCoup);
    bool partieTerminee = etatJeu == GAGNE || etatJeu == PERDU;
    int nbLignes = g->nbLignes;
    int nbColonnes = g->nbColonnes;
    for (int i = 0; i < nbLignes; ++i) {
        afficherBar(nbColonnes);
        cout << "|";
        for (int j = 0; j < nbColonnes; ++j) {
            Point p;
            p.x = i;
            p.y = j;
            afficherCase(g->matrice[i][j], isMine(g, p), partieTerminee);
        }
        cout << endl;
    }
    afficherBar(nbColonnes);
}

EtatJeu getEtatJeu(Grille *grille, Coup *coups, int nbCoup) {
    for (int i = 0; i < nbCoup; ++i) {
        Coup coup = coups[i];
        if (coup.typecoup == DEMASQUE && isMine(grille, coup.position)) {
            return PERDU;
        }
        if (coup.typecoup == MARQUE && !isMine(grille, coup.position)) {
            return PERDU;
        }
    }

    bool resteCaseNonRevele(false);
    for (int i = 0; i < grille->nbLignes; ++i) {
        for (int j = 0; j < grille->nbColonnes; ++j) {
            Point p;
            p.x = i;
            p.y = j;
            if (grille->matrice[i][j] == NON_REVELE && !isMine(grille, p)) {
                resteCaseNonRevele = true;
                break;
            }
        }
    }
    return (resteCaseNonRevele) ? EN_COURS : GAGNE;
}

Grille initGrilleFromString(int nbLignes, int nbColonnes) {
    Grille grille;
    initMatrix(&grille, nbLignes, nbColonnes);
    int currentIndex(0);
    string line;
    for (int i = 0; i < 2 * nbLignes + 1; ++i) {
        getline(cin, line);
        if (i % 2 == 0 && i != 0) {
            fillLineOfMatrix(grille.matrice[currentIndex++], line);
        }
    }
    return grille;
}

Coup trouverCoupValide(Grille *g) {
    Coup coup;
    for (int i = 0; i < g->nbLignes; ++i) {
        for (int j = 0; j < g->nbColonnes; ++j) {
            if (g->matrice[i][j] == NON_REVELE || g->matrice[i][j] == DRAPEAU) {
                coup.position.x = i;
                coup.position.y = j;
                coup.typecoup = DEMASQUE;
                return coup;
            }
        }
    }
    return coup;
}

void cleanGrille(Grille *g) {
    if (g->nbLignes != 0) {
        for (int i = 0; i < g->nbLignes; ++i) {
            delete[] g->matrice[i];
        }
        delete[] g->matrice;
    }

    if (g->nbMines != 0) {
        delete[] g->mines;
    }
}