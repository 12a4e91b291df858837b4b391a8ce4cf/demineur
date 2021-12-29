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

Grille creerGrille(unsigned int nbLignes,unsigned int nbColonnes, unsigned int nbMines);
void afficherProbleme(const Grille *g);
struct Grille creerGrille(int nbLignes,int nbColonnes,int nbMines);



#endif
