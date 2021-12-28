#include "fonctions.h"

Grille creerGrille(unsigned int nbLignes,unsigned int nbColonnes, unsigned int nbMines){
    Grille g;
    g.nbLignes = nbLignes;
    g.nbColonnes = nbColonnes;
    g.nbMines = nbMines;

    g.mines = new unsigned int[nbMines]; //delete [] g.mines
   /* g.grilles = new unsigned int*[nbLignes];
    for (int i = 0; i<nbLignes; i++)
        g.grilles[i] = new unsigned int[nbColonnes];*/

    srand(time(NULL));
    for(unsigned int i=0; i<g.nbMines; i++) {
            unsigned int mine=rand()%g.nbLignes*g.nbColonnes;
            g.mines[i] = mine;
    }
    return g;


/*
for (int i = 0; i < nbLignes*nbColonnes; i++)
delete[] g.grilles[i];
delete[] g.grilles; */


}

void afficherProbleme(Grille *g){
    cout << g->nbLignes <<" "<< g->nbColonnes<<" "<< g->nbMines<<" ";
            for(unsigned int i=0; i<g->nbMines; ++i)
            cout<<g->mines[i]<<" ";
    }





