#ifndef FONCTIONS_H
#define FONCTIONS_H
#include <iostream>
#include <time.h>
#include <assert.h>

using namespace std;

//-------------------------------------------STRUCTURES-----------------------------------------------------------
typedef enum EtatGrille{
    DEMASQUE, MASQUE
}EtatGrille;


typedef struct Grille {
    unsigned int nbLignes;
    unsigned int nbColonnes;
    unsigned int nbMines;
    int** matrice;
    unsigned int* mines;
}Grille;

typedef struct Coup {
    int indexLigne;
    int indexColonne;
    EtatGrille typecoup;
}Coup;

typedef struct Point {
    int x;
    int y;
}Coup;


int NON_REVELE = -1;
int MARQUE = 9;

//-----------------------------------------PROTOYPES------------------------------------------------------------
Grille creerGrille(unsigned int nbLignes,unsigned int nbColonnes, unsigned int nbMines);


void afficherProbleme(const Grille *g);


struct Grille creerGrille(int nbLignes,int nbColonnes,int nbMines);


int* conversion(int nbAconvertir, Grille* g);


void remplirGrille(Grille* g, Coup* coups, int nbCoup);


void afficherMatrice(Grille* g);


void debugGrille(Grille* g);
#endif
