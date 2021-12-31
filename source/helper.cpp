#include "../header/helper.h"

bool inArray(int element, int const *tab, int nbElement) {
    for (int i = 0; i < nbElement; ++i) {
        if (tab[i] == element) return true;
    }
    return false;
}

bool isMine(Grille *grille, Point point) {
    for (int i = 0; i < grille->nbMines; ++i) {
        int pos1D = conversion2DTo1D(grille, point);
        if (inArray(pos1D, grille->mines, grille->nbMines)) {
            return true;
        }
    }
    return false;
}

Point conversion1DTo2D(Grille *g, int nbAconvertir) {
    Point point;
    point.x = nbAconvertir / g->nbColonnes;
    point.y = nbAconvertir % g->nbColonnes;
    return point;
}

int conversion2DTo1D(Grille *grille, Point point) {
    return point.x * grille->nbColonnes + point.y;
}

string conversionCoupToStr(Grille *grille, Coup coup) {
    string res;
    res += (coup.typecoup == DEMASQUE) ? 'D' : 'M';
    res += to_string(conversion2DTo1D(grille, coup.position));
    return res;
}

int convertTokenEnIntGrille(char token) {
    if (token == 'x') {
        return DRAPEAU;
    } else if (token == '\0') {
        return 0;
    } else if (token == '.') {
        return NON_REVELE;
    } else {
        return token - '0';
    }
}

int getVoisinAdjacentNonVisites(Grille *grille, Point point, Point *voisinAdjacentNonVisites) {
    int currentIndex = 0;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            int x = point.x + dx;
            int y = point.y + dy;
            Point voisin;
            voisin.x = x;
            voisin.y = y;
            if ((dx == 0 && dy == 0) || !(0 <= voisin.x && voisin.x < grille->nbLignes) ||
                !(0 <= y && y < grille->nbColonnes)) {
                continue;
            }
            if (!isMine(grille, voisin) && grille->matrice[x][y] == NON_REVELE) {
                voisinAdjacentNonVisites[currentIndex++] = voisin;
            }
        }
    }
    return currentIndex;
}

int getNbMineAdjacente(Grille *grille, Point point) {
    int nbMineAdjacente = 0;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            int x = point.x + dx;
            int y = point.y + dy;
            Point voisin;
            voisin.x = x;
            voisin.y = y;
            if ((dx == 0 && dy == 0)
                || !(0 <= voisin.x && voisin.x < grille->nbLignes)
                || !(0 <= voisin.y && voisin.y < grille->nbColonnes)) {
                continue;
            }
            nbMineAdjacente += isMine(grille, voisin);
        }
    }
    return nbMineAdjacente;
}

string removeSpaces(string str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (str[i] != ' ')
            str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
    return str;
}

void fillLineOfMatrix(int *&row, string line) {
    string current;
    int currentIndex = 0;
    for (int i = 1; i < line.size(); ++i) {
        if (line[i] == '|') {
            row[currentIndex++] = convertTokenEnIntGrille(removeSpaces(current)[0]);
            current = "";
        } else {
            current += line[i];
        }
    }
}

void debugGrille(Grille *g) {
    cout << endl << "GRILLE" << endl;
    for (int i = 0; i < g->nbLignes; i++) {
        for (int j = 0; j < g->nbColonnes; j++) {
            cout << g->matrice[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------" << endl;


    cout << "MINES" << endl;
    for (int i = 0; i < g->nbMines; i++) {
        cout << g->mines[i] << endl;
    }
    cout << "---------------" << endl;
}

void afficherBar(int taille) {
    string pattern = " ___";
    for (int i = 0; i < taille; ++i) {
        cout << pattern;
    }
    cout << endl;
}

void afficherCase(int element, bool isMine, bool isPartieTerminee) {
    string elementEncadre = " % |";
    if (isMine && isPartieTerminee) {
        elementEncadre[1] = 'm';
    } else if (element == NON_REVELE) {
        elementEncadre[1] = '.';
    } else if (element == DRAPEAU) {
        elementEncadre[1] = 'x';
    } else if (element == 0) {
        elementEncadre[1] = ' ';
    } else {
        elementEncadre[1] = element + '0';
    }
    cout << elementEncadre;
}