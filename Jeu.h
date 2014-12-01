/* 
 * File:   Jeu.h
 * Author: Brunathan
 *
 * Created on 1 décembre 2014, 10:53
 */

#ifndef JEU_H
#define	JEU_H

#include <iostream>

#include "Coord.h"
#include "Plateau.h"
#include "joueur.h"

class Jeu {
public:
    Jeu() ;
    bool jouable(Coord C, int Couleur);
    bool suicide(Coord C, int Couleur);
    void run();
    bool fin();
    void rafraichir(Coord C);
private:
    Plateau P;
    joueur jBlanc , jNoir;
    
};
#endif	/* JEU_H */

