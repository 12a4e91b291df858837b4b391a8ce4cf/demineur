#include "fonctions.h"


bool inArray(unsigned int element, unsigned int * tab, unsigned int nbElement){
    for(int i=0; i < nbElement ; ++i){
        if(tab[i] == element) return true;
    }
    return false;
}


Grille creerGrille(unsigned int nbLignes,unsigned int nbColonnes, unsigned int nbMines){
    Grille g;
    g.nbLignes = nbLignes;
    g.nbColonnes = nbColonnes;
    g.nbMines = nbMines;

    g.mines = new unsigned int[nbMines]; //delete [] g.mines


    srand(time(NULL));
    for(unsigned int i=0; i<g.nbMines; i++) {
            unsigned int mine=rand()%g.nbLignes*g.nbColonnes;
            g.mines[i] = mine;
    }


    g.matrice = new int*[nbLignes];
    for (int i = 0; i<nbLignes; i++) {
        g.matrice[i] = new int[nbColonnes];
    }

    for(int i=0; i < g.nbLignes; i++) {
        for(int j = 0; j < g.nbColonnes; j++) {
            g.matrice[i][j] = NON_REVELE;
        }
    }
    return g;

}


void afficherProbleme(const Grille *g){

    cout << g->nbLignes <<" "<< g->nbColonnes<<" "<< g->nbMines<<" ";
            for(unsigned int i=0; i<g->nbMines; ++i)
            cout<<g->mines[i]<<" ";

            cout << endl;
            cout << endl;

}


Point conversion(int nbAconvertir, Grille* g){
    Point point;
    point.x = nbAconvertir/g->nbColonnes;
    point.y = nbAconvertir%g->nbColonnes;
    return point;
}


void remplirGrille(Grille* g, Coup* coups,unsigned int nbCoup){
    for(int i = 0; i < nbCoup; ++i){
        if(coups[i]->typecoup == MARQUE){

        }
    }


}

void afficherMatrice(Grille* g){
    for(int i=0; i <g->nbLignes; i++) {
        for(int j = 0; j <g->nbColonnes; j++) {
            cout << g->matrice[i][j] << " ";
        }
        cout << endl;
    }
}


void debugGrille(Grille* g) {
    cout << "GRILLE" << endl;
    for(int i=0; i <g->nbLignes; i++) {
        for(int j = 0; j <g->nbColonnes; j++) {
            cout << g->matrice[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------" << endl;


    cout << "MINES" << endl;
    for(int i=0; i <g->nbMines; i++) {
        cout << g->mines[i] << endl;
    }
    cout << "---------------" << endl;
}
