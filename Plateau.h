/* 
 * File:   Plateau.h
 * Author: Brunathan
 *
 * Created on 1 décembre 2014, 10:35
 */

#ifndef PLATEAU_H
#define	PLATEAU_H

#include "Coord.h"
#include <iostream>

class Plateau {
public:
    Plateau();                              // constructeur de plateau avec une taille par défaut de 19
    Plateau(const Plateau& P);                     // constructeur de plateau qui copie le plateau argument
    Plateau(int _taille);                   // constructeur de plateau avec une taille parapétrable
    int getIntersection(Coord C) const;     // accès en lecture au contenu d'une intersection définir par ses coordonnées
    int getTaille() const;                  // accès en lecture de la taille du plateau
    void placerPion(Coord C , int couleur); // Placement d'un pion d'une couleur donnée à une intersection
    void supprimerPion(Coord C);            // suppression d'un pion par mise à 0 de la valeur de l'intersection
    void affichage();                       // Méthode d'affichage du plateau
    
    
    
private:
    int taille;
    int** tab; //-1:blanc 0:rien 1:noir 
};

#endif	/* PLATEAU_H */

