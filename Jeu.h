/* 
 * File:   Jeu.h
 * Author: Brunathan
 *
 * Created on 1 décembre 2014, 10:53
 */

#ifndef JEU_H
#define	JEU_H

#include <iostream>
#include <cstdlib>
#include <vector>

#include "Coord.h"
#include "Plateau.h"
#include "joueur.h"

class Jeu {
public:
    void rafraichir(Plateau* plat, Coord LastC);
    bool jouable(Coord C, int Couleur);
    void run();
    bool fin();
    bool estVivant(Coord C, Plateau plat);
    int test(Coord C, int* Couleur);
    void calculScore();
    bool tested(Coord C);
    void choixpris();
    Plateau* P;
    
    
private:
    
    std::vector<Coord> T; 
    joueur jBlanc , jNoir;
    
};
#endif	/* JEU_H */

