#include "fonctions.h"

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


    g.matrice = new unsigned int*[nbLignes];
    for (int i = 0; i<nbLignes; i++) {
        g.matrice[i] = new unsigned int[nbColonnes];
    }
    return g;
    /*
for (int i = 0; i < nbLignes*nbColonnes; i++)
delete[] g.grilles[i];
delete[] g.grilles; */

}






void afficherProbleme(const Grille *g){

    cout << g->nbLignes <<" "<< g->nbColonnes<<" "<< g->nbMines<<" ";
            for(unsigned int i=0; i<g->nbMines; ++i)
            cout<<g->mines[i]<<" ";
            cout << endl;
            cout << endl;
}





void afficherMatrice(Grille* g){
for (unsigned int i=0; i<g->nbLignes; i++){
        for (unsigned int j=0; j<g->nbColonnes; j++){
        g->matrice[i][j] = i+j;
                }
            }

    for(int i=0; i <g->nbLignes; i++) {

            for(int j = 0; j <g->nbColonnes; j++) {

      cout << g->matrice[i][j] << " ";
    }
    cout << endl;
}
}
