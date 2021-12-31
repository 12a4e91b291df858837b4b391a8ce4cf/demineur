#include "fonctions.h"

void testConversion() {
    Grille g;
    g.nbColonnes = 6;
    g.nbLignes = 4;

    int* tab = conversion(0, &g);
    int* tab2 = conversion(9, &g);
    int* tab3 = conversion(20, &g);

    cout << tab[0] << " " << tab[1] << endl;
    cout << tab2[0] << " " << tab2[1] << endl;
    cout << tab3[0] << " " << tab3[1] << endl;


    assert (tab[0] == 0 && tab[1]==0);
    assert (tab2[0] == 1 && tab2[1]==3);
    assert (tab3[0] == 3 && tab3[1]==2);
}


void testRemplirGrille(){
    unsigned int nbLignes = 4;
    unsigned int nbColonnes = 6;
    unsigned int nbMines = 5;

    Grille g = creerGrille(nbLignes, nbColonnes, nbMines);
    g.mines[0] = 1;
    g.mines[1] = 5;
    g.mines[2] = 7;
    g.mines[3] = 12;
    g.mines[4] = 19;



    Coup coup[3];
    coup[0].indexLigne = 2;
    coup[0].indexColonne = 3;
    coup[0].typecoup = DEMASQUE;

    coup[1].indexLigne = 0;
    coup[1].indexColonne = 5;
    coup[1].typecoup = MASQUE;

    coup[2].indexLigne = 0;
    coup[2].indexColonne = 0;
    coup[2].typecoup = DEMASQUE;

    int matriceAttendue[nbLignes][nbColonnes] = {
     {2, NON_REVELE , 2, 0, 1 , MARQUE},
     {NON_REVELE, NON_REVELE , 2, 0, 1 , 1},
     {NON_REVELE, NON_REVELE , 2, 0, 0 , 0},
     {NON_REVELE, NON_REVELE , 1, 0, 0 , 0},
    };

    debugGrille(&g);
    for(int i=0; i < g.nbLignes; i++) {
        for(int j = 0; j < g.nbColonnes; j++) {
            assert (g.matrice[i][j] == matriceAttendue[i][j]);
        }
    }



}
