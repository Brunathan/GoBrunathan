/* 
 * File:   Plateau.h
 * Author: Brunathan
 *
 * Created on 1 décembre 2014, 10:35
 */

#ifndef PLATEAU_H
#define	PLATEAU_H

#include "Coord.h"

class Plateau {
public:
    Plateau();
    Plateau(int _taille);
    int getIntersection(Coord C) const;
    void placerPion(Coord C , int couleur);
    void supprimerPion(Coord C);
    void affichage();
    
private:
    int taille;
    int** tab; //-1:blanc 0:rien 1:noir 
};

#endif	/* PLATEAU_H */

