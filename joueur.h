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
    void ajoutPrisonniers(int nb);  // ajoute un nombre nb de prisonier au joueur
    Coord choixJeu();               // étape de jeu, le joueur choisi la case où il veut jouer ; (-1,-1) pour passer son tours 
    bool aPasse ();                 // renvoie un booléen disant si le joueur a passé au dernier tour
    
private:
    int couleur; //-1:blanc 0:rien 1:noir 
    int nbPrisonniers;
    Coord dernierTour;
    
};

#endif	/* JOUEUR_H */

