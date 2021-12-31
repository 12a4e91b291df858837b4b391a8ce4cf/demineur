#ifndef DEMINEUR_HELPER_H
#define DEMINEUR_HELPER_H

#include "../header/fonction.h"
#include "../header/structure.h"
#include <string>

using namespace std;

bool inArray(int element, int const *tab, int nbElement);

bool isMine(Grille *grille, Point point);

Point conversion1DTo2D(Grille *g, int nbAconvertir);

int conversion2DTo1D(Grille *g, Point p);

string conversionCoupToStr(Grille *grille, Coup coup);

int getVoisinAdjacentNonVisites(Grille *grille, Point point, Point *voisinAdjacentNonVisites);

int getNbMineAdjacente(Grille *grille, Point point);

void afficherBar(int taille);

void afficherCase(int element, bool isMine, bool isPartieTerminee);

void debugGrille(Grille *g);

void fillLineOfMatrix(int *&row, string line);

#endif //DEMINEUR_HELPER_H
