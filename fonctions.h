#ifndef FONCTIONS_H
#define FONCTIONS_H
#include <iostream>
#include <time.h>
#include <assert.h>

using namespace std;


typedef struct Grille {
    unsigned int nbLignes;
    unsigned int nbColonnes;
    unsigned int nbMines;
    unsigned int** matrice;
    unsigned int* mines;
}Grille;


void afficherProbleme(Grille *g);
struct Grille creerGrille(int nbLignes,int nbColonnes,int nbMines);



#endif
