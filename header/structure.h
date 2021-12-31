#ifndef DEMINEUR_STRUCTURE_H
#define DEMINEUR_STRUCTURE_H

typedef enum EtatGrille {
    DEMASQUE, MARQUE
} EtatGrille;

typedef enum EtatJeu {
    GAGNE, PERDU, EN_COURS
} EtatJeu;

typedef struct Grille {
    int nbLignes;
    int nbColonnes;
    int nbMines;
    int **matrice;
    int *mines;
} Grille;

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct Coup {
    Point position;
    EtatGrille typecoup;
} Coup;

typedef enum CaseSpecial {
    NON_REVELE = -1,
    DRAPEAU = 9,
} CaseSpecial;

#endif //DEMINEUR_STRUCTURE_H
