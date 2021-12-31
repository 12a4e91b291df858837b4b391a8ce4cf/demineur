#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <iostream>
#include <time.h>
#include <assert.h>
#include "../header/helper.h"
#include "../header/structure.h"

using namespace std;

Grille creerGrille(int nbLignes, int nbColonnes, int nbMines);

void afficherProbleme(const Grille *g);

Grille creerGrille(int nbLignes, int nbColonnes, int nbMines);

void remplirGrille(Grille *g, Coup *coups, int nbCoup);

void afficherGrille(Grille *g, Coup *coups, int nbCoup);

void remplirGrille(Grille *g, Coup *coups, int nbCoup);

EtatJeu getEtatJeu(Grille *grille, Coup *coups, int nbCoup);

Grille initGrilleFromString(int nbLignes, int nbColonnes);

Coup trouverCoupValide(Grille *g);

void cleanGrille(Grille * g);

#endif
