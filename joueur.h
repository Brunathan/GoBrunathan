/* 
 * File:   joueur.h
 * Author: Brunathan
 *
 * Created on 1 décembre 2014, 10:42
 */

#ifndef JOUEUR_H
#define	JOUEUR_H

#include "Coord.h"
#include "Plateau.h"

class joueur {
public:
    joueur();
    void ajoutPrisonniers(int nb);
    Coord choixJeu(); // (-1,-1) pour passer son tours 
    bool aPasse ();
    int getScore() const;
    
private:
    int couleur; //-1:blanc 0:rien 1:noir 
    int nbPrisonniers;
    int score;
    Coord dernierTour;
    
};

#endif	/* JOUEUR_H */

